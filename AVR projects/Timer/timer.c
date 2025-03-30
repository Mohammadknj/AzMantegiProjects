#include <mega16.h>
#include <stdio.h>
#include <alcd.h>
int tenth=0,sec=0,Min=0,hour=0;
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
char st[20];
tenth++;
if(tenth==100){sec++;tenth=0;
  if(sec==60){Min++;sec=0; 
    if(Min==60){hour++;Min=0;
        if(hour==24)hour=0;
    }
  }      
}sprintf(st,"%02d:%02d:%02d:%02d",hour,Min,sec,tenth);
lcd_gotoxy(0,0); lcd_puts(st);
}
void main(void)
{
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 0.977 kHz
// Mode: CTC top=OCR0
// OC0 output: Toggle on compare match
// Timer Period: 99.328 ms
// Output Pulse(s):
// OC0 Period: 0.19866 s Width: 99.328 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (1<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x0A;
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (1<<OCIE0) | (0<<TOIE0);
lcd_init(16);
#asm("sei")
while (1)
      {        }
}