#ifndef QHBuzzer_H
#define QHBuzzer_H

///@brief Class for MeBuzzer module
class QhBuzzer 
{
	public:
	    QhBuzzer();
	    QhBuzzer(unsigned char pin);//初始函数
	    void qtone(int frequency, long int duration = 0);//播放指定频率方波，时间对应的声音
	    void noqTone();
		  void play(int num, unsigned int tx);//播放设置好的七种声调的声音，num决定播放哪一种，tx决定时间
};

#endif
