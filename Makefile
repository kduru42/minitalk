NAMECL = client
NAMESV = server
PRINTF = ./ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf

SOURCECL = 	./src/minitalk_utils.c
OBJECTCL = $(SOURCECL:.c=.o)

SOURCESV = ./src/minitalk_utils.c
OBJECTSV = $(SOURCESV:.c=.o)

all: $(NAMECL) $(NAMESV)

$(NAMECL): $(OBJECTCL)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/client.c $(OBJECTCL) $(PRINTF) -o $(NAMECL)

$(NAMESV): $(OBJECTSV)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/server.c $(OBJECTSV) $(PRINTF) -o $(NAMESV) 

clean:
	make -C ./ft_printf clean
	$(RM) $(OBJECTCL) $(OBJECTSV)

fclean: clean
	make -C ./ft_printf fclean
	$(RM) $(NAMECL) $(NAMESV)

re: fclean all

.PHONY: clean fclean all re