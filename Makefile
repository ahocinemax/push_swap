NAME	= push_swap
SRCS	= srcs/*.c
HEADER	= includes/push_swap.h
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
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
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all
