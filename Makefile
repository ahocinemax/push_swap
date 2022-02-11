NAME	= push_swap

SRCS	= srcs/ft_best_path.c srcs/ft_check.c srcs/ft_fhundred.c srcs/ft_hundred_utils.c \
	  srcs/ft_index.c srcs/ft_movement.c srcs/ft_movement2.c srcs/ft_sort.c \
	  srcs/ft_stack.c srcs/push_swap.c srcs/utils.c

HEADER	= includes/push_swap.h

CC		= gcc

FLAGS	= -Wall -Werror -Wextra -g

LIBFT	= libft/libft.a

all : $(LIBFT) $(NAME) 

$(LIBFT) : 
	@make -C libft

$(NAME)  : $(SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $@
	@printf "\e[38;5;226m./$@ successfully build 🥑\e[0m\n"


clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;206m.o files deleted 🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@printf "\e[38;5;200mBinaries deleted 🗑\e[0m\n"

re: fclean all
