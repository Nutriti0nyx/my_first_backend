re: fclean all

all: exe

exe: print
	./printf

print: printf.c
	@gcc printf.c -o printf

fclean:
	@rm -f printf

.PHONY: fclean