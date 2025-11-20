# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 14:25:00 by rpinheir          #+#    #+#              #
#    Updated: 2025/11/20 14:25:00 by rpinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= COLORS =================================== #
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
PURPLE  = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

# ================================ VARIABLES ================================= #
NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
AR          = ar rcs

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

OBJDIR      = obj

SRC         = ft_printf.c
OBJ         = $(SRC:%.c=$(OBJDIR)/%.o)

# ================================== RULES =================================== #
all: $(LIBFT) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@
	@echo "$(BLUE)⚙  Compiling: $(CYAN)$<$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✓  Libft compiled$(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)✓  $(NAME) created$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(RED)✗  Objects cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)✗  $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
