#include "QhBuzzer.h"
#include"Arduino.h" 

static unsigned char buzzer_pin;


QhBuzzer::QhBuzzer()
{
    buzzer_pin = 8;
    pinMode(buzzer_pin, OUTPUT);
}
QhBuzzer::QhBuzzer(unsigned char pin)
{
    pinMode(pin, OUTPUT);
    buzzer_pin = pin;
}

// frequency (in hertz) and duration (in milliseconds).
void QhBuzzer::qtone(int frequency, long int duration)
{
   tone(buzzer_pin, frequency, duration);
}

void QhBuzzer::noqTone()
{
	noTone(buzzer_pin);
}

void QhBuzzer::play(int num, unsigned int tx)
{
	switch(num){
		case 1: tone(buzzer_pin,595, tx); break;
		case 2: tone(buzzer_pin,661, tx); break;
		case 3: tone(buzzer_pin,700, tx); break;
		case 4: tone(buzzer_pin,786, tx); break;
		case 5: tone(buzzer_pin,882, tx); break;
		case 6: tone(buzzer_pin,990, tx); break;
		case 7: tone(buzzer_pin,1112,tx); break;
    default: break;
	}
}
