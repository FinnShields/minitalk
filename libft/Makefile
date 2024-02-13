NAME		= libft.a
SOURCES		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_memcmp.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	 		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils1.c ft_printf_utils2.c \
			ft_printf_utils3.c ft_printf_execute_types_1.c ft_printf_execute_types_2.c

OBJS		= ${SOURCES:.c=.o}

BONUS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c
			  
BONUS_OBJS	= ${BONUS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

CC			= cc

%.o:		%.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
				@ar -rcs ${NAME} ${OBJS}
				@echo "libft made successfully :)"
				

clean:
				@rm -f ${OBJS} ${BONUS_OBJS}
				@rm -f .bonus

fclean:		clean
				@rm -f ${NAME}

re:			fclean all

bonus:		.bonus

.bonus:		${OBJS} ${BONUS_OBJS}
				@ar -rcs ${NAME} ${BONUS_OBJS}
				touch .bonus

.PHONY:		all clean fclean re bonus
