CC = gcc
CFLAG = -Wall -Wextra -g -o

bank: 
	$(CC) main.c myBank.c $(CFLAG) main.o

git:
	git add -A
	git commit -m "$m"
	git push

clean:
	rm -f *.o main