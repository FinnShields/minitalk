NAME		=	server client
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SERVER		=	server.c
CLIENT		=	client.c
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a
HEADER		=	minitalk.h

all:		$(NAME)

$(NAME):	$(LIBFT) $(HEADER)
				@$(CC) $(CFLAGS) $(SERVER) $(LIBFT) -o server
				@$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) -o client
				@echo "~ ~ ~ ~ ~ ~ ~ ~ ~"
				@echo "~  minitalk 🗣  ~"
				@echo "~ ~ ~ ~ ~ ~ ~ ~ ~"
				@echo "Compiled successfully, nice."

$(LIBFT):
				@make -C $(LIBFT_PATH) all

clean:
				@make -C $(LIBFT_PATH) clean
				@echo "cleaned"

fclean:		clean
				@make -C $(LIBFT_PATH) fclean
				@rm -f server
				@rm -f client
				@echo "fcleaned"

re:			fclean all

.PHONY:		all clean fclean re libft