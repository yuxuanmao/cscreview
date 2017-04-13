FLAGS = -Wall -std=c99

all: q6

q6: q6.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm *.o q6


