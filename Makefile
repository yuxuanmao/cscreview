FLAGS = -Wall -std=c99

all: q2

q2: q2.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm *.o q2
