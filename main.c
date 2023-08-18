/*
 * timer output compare mode.c
 *
 * Created: 8/18/2023 8:58:35 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
     sei();
	 TIMSK |= (1<<OCIE1A);
	 TCCR1A |= 0X40;
	 TCCR1B &= ~(1<<WGM12)& ~(1<<WGM13);
	 TCCR1B |= (1<<CS12)|(1<<CS10);
	 TCCR1B &= ~(1<<CS11);
	 TCNT1 = 0;
	 OCR1A =7812.5;
	 DDRD |= (1<<DDD5);
	 
    while (1) 
    {
    }
}

ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0;
	OCR1A = 7812.5;
}
