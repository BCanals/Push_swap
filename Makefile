# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bizcru <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 17:30:42 by bizcru            #+#    #+#              #
#    Updated: 2024/11/27 21:14:01 by bizcru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_NAMES = main.c utils_list.c utils_rotate.c utils_r_rotate.c \
			 utils_param.c utils_swap.c utils_sort.c
SRCS = $(addprefix src/, $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE = src/push_swap.h
CFLAGS = -Wall -Wextra -Werror
END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo -n "\n$(YELLOW) ---> BUILDING $(NAME)...$(END)"
	@gcc $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN) DONE!$(END)"
	@echo "$(GREEN)   === BUILDING COMPLETE : ) ===$(END)\n"

$(LIBFT):
	@echo "\n $(YELLOW) ---> Compiling libft... === $(END)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)   === libft.a is compiled :) ===$(END)"

%.o: %.c $(INCLUDE)
	@gcc $(CFLAGS) -I. -c $< -o $@
	@echo -n "\n $(BLUE) ---> Building objects... --- $(END)"
	@echo " $(CIAN) DONE! :) $(END)"

clean:
	@echo -n "$(RED) --> Deleting object files... $(END)"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "$(GREEN) DONE! $(END)"

fclean: clean
	@echo -n "$(RED) --> Deleting executables... $(END)"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN) DONE! $(END)"

re: fclean all

.PHONY: all clean fclean
