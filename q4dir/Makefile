FLAGS = -Wall -std=c99

all: replacer

replacer: q4.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm *.o replacer

