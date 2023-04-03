NAMECL = client
NAMESV = server
NAMECLBS = client_bonus
NAMESVBS = server_bonus
PRINTF = ./ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf

SOURCECL = 	./src/minitalk_utils.c
OBJECTCL = $(SOURCECL:.c=.o)

SOURCESV = ./src/minitalk_utils.c
OBJECTSV = $(SOURCESV:.c=.o)

SOURCECLBS = ./src/minitalk_utils.c
OBJECTCLBS = $(SOURCECLBS:.c=.o)

SOURCESVBS = ./src/minitalk_utils.c
OBJECTSVBS = $(SOURCESVBS:.c=.o)

all: $(NAMECL) $(NAMESV)

$(NAMECL): $(OBJECTCL)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/client.c $(OBJECTCL) $(PRINTF) -o $(NAMECL)

$(NAMESV): $(OBJECTSV)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/server.c $(OBJECTSV) $(PRINTF) -o $(NAMESV) 

$(NAMECLBS): $(OBJECTCLBS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/client_bonus.c $(OBJECTCLBS) $(PRINTF) -o $(NAMECLBS)

$(NAMESVBS): $(OBJECTSVBS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/server_bonus.c $(OBJECTSVBS) $(PRINTF) -o $(NAMESVBS)

bonus: $(NAMECLBS) $(NAMESVBS)

clean:
	make -C ./ft_printf clean
	$(RM) $(OBJECTCL) $(OBJECTSV) $(OBJECTSVBS) $(OBJECTCLBS)

fclean: clean
	make -C ./ft_printf fclean
	$(RM) $(NAMECL) $(NAMESV) $(NAMESVBS) $(NAMECLBS)

re: fclean all

.PHONY: clean fclean all re