CC = gcc
CFLAG = -Wall -Wextra -g -o

bank: 
	$(CC) main.c myBank.c $(CFLAG) main.o

clean:
	rm -f *.o main