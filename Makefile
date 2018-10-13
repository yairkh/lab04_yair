CC=gcc
CFLAGS=-lWarn -pedantic

alarm:  alarm.o libmyifttt.a
	$(CC) alarm.o -L. -lmyifttt -lcurl -lwiringPi  -o alarm

tester: tester.o libmyifttt.a
	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

alarm.o: alarm.c
	$(CC) $(CFLAGS) -c -ansi $<
tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm tester *.o
