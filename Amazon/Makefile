NAME = findodd

CC = g++ 

UNAME := $(shell uname)

$(NAME): $(NAME).o
	$(CC) $(NAME).o $(GLFLAGS) -o $(NAME)

$(NAME).o: $(NAME).cpp
	$(CC) -c $(NAME).cpp
	
clean:
	rm -rf $(NAME) *.o
