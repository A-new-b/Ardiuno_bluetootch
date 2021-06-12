#include"Timer_judge.h"

bool time_judge(volatile long &second_1)
{
    bool result;
    if(second_1%3600==0&&second_1!=0)
    result=true;
    else
    result=false;

    while(second_1>86400)
    {
      second_1-=86400;
    }

    return result;
}
