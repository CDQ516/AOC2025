all: day1

clean:
	rm -f day1

day1:
	gcc -g -O0 -Wall -Wextra -o day1 day1.c
