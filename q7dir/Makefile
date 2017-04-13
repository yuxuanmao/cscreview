FLAGS = -Wall -std=gnu99

all: q7

q7: q7.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm *.o q7

