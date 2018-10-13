#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int i;
  int alarm_ready=0;
  struct tm tm = *localtime(&(time_t){time(NULL)});

  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1)
  {
      i = digitalRead (0);
      switch(i)
     {
      case 0:
            if (alarm_ready != 1)
            {

               alarm_ready=1;
               ifttt("http://127.0.0.1:8080/trigger/event/with/key/lab04_yair", "Alarm ready", asctime(&tm), "");
            }
            digitalWrite (2, LOW) ;
	    digitalWrite (1, HIGH) ; delay (200) ;
            digitalWrite (1, LOW) ; delay (200) ;   
            break;
       case 1:
            alarm_ready = 0;
            ifttt("http://127.0.0.1:8080/trigger/event/with/key/lab04_yair", "Alarm Event", asctime(&tm), "");
	    digitalWrite (1, LOW);
            digitalWrite (2, HIGH); delay (300) ;
            break;
       }
  }
  /*NOTREACHED*/
  return 0 ;
}
