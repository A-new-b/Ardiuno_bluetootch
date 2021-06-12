#include <SoftwareSerial.h> 

#include "QhBuzzer.h"
#include "TimerOne.h"
#include "Timer_judge.h"

SoftwareSerial BT(10, 11);

QhBuzzer qbez(8);


void setup() {
  pinMode(8, OUTPUT);
  Timer1.initialize(1000000);//初始化定时器为1s
  Timer1.attachInterrupt( timerIsr );//设置中断回调函数

  Serial.begin(9600);
//  Serial.println("Serial is ready!");
  BT.begin(9600);
  BT.println("Serial is ready!");
}


int t= 500;
bool flag=false;//防止一秒多响

bool mode_1=false;//模式标志符
bool mode_2=false;

char symbol_1='#';//对应模式终止符
char symbol_2='@';

volatile long second_1=0;//对应模式计时器
volatile long second_2=0;
volatile long pre_second_2=1;//不能和second_2一样


String input="";//输入字符串


void loop() {
  //播放模块

  bool judge=time_judge(second_1);

  if(judge&&!flag)
  {
    for(int i = 1; i < 8; i++)
    {
      qbez.play(i, t);  delay(t);
    }
    flag=true;   
  }
  else if(second_2==pre_second_2&&mode_2)
  {
    for(int i = 1; i < 8; i++)
    {
      qbez.play(i, t);  delay(t);
    }
    mode_2=false;
    second_2=0;
    pre_second_2=1;
  }

  if (!judge)
  {
    flag=false;
  }
  
  
  //蓝牙检验模块
  if (BT.available()) {
    
      char val = BT.read();
      if(val==symbol_1)//若接受到模式一的终止符
      {
        if(mode_1)
        {
          second_1=input.toInt();
          input="";
          Serial.println(second_1);
        }
        else if (!mode_1)
        {
          mode_1=true;
        }

      }
      else if (val==symbol_2)
      {
        if(mode_2)
        {
          pre_second_2=input.toInt();
          input="";
          Serial.println(pre_second_2);
        }
        else if (!mode_2)
        {
          mode_2=true;
        }
      }
      else
      {
        input+=val;
      }
      
  }
  
 }


void timerIsr()//定时器中断处理函数
{
//  String myString1 = String(second_1);
//  Serial.println(myString1);
//  second_1=second_1+1;
//  String myString2 = String(second_1);
//  Serial.println(myString2);

  if(mode_1)
    second_1++;
  if(mode_2)
    second_2++;
}
