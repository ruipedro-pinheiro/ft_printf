CC=cc
CFLAGS= -Wall -Wextra -Werror -g

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#TODO
#Ajouter la libft et compiler printf avec (apres eval ajouter simplement ft_printf dams la libft)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all
	
.PHONY : all clean fclean re
