


OBJS = proje1.o fields.o jval.o dllist.o

all: proje1


proje1: $(OBJS)
	gcc -Wall $(OBJS) -o proje1

p1.o: proje1.c
	gcc -c -Wall proje1.c
fields.o: fields.c fields.h
	gcc -c -Wall fields.c

jval.o: jval.c jval.h
	gcc -c -Wall jval.c

dllist.o: dllist.c dllist.h
	gcc -c -Wall dllist.c

clean:
	rm -rf $(OBJS)
