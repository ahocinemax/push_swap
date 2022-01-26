/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:06:06 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/18 18:06:10 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

# ifndef _STD_OUT
#  define _STD_OUT	1
# endif

typedef struct s_stack
{
	struct s_stack	*next;
	char			*str;
}					t_stack;

typedef struct s_data
{
	int				min;
	int				max;
	int				c_min;
	int				c_max;
	int				chunk;
}					t_data;

// UTILS
void	ft_sort(t_list **a, t_list **b, t_stack **stack, t_data *data);
int		ft_error(char **str, t_list **a, t_list **b, t_stack **stack);
int		ft_free_all(char **str, t_list **a, t_list **b, t_stack **s);
int		ft_check(char **str, int size);
int		ft_smaller(t_list *lst);
char	*ft_pattern(t_list *a);

// FONCTION DE MOUVEMENT
void	ft_push(t_list **to, t_list **from, t_stack **stack, char list);

void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack);
void	ft_reverse(t_list **lst, t_stack **stack, char list);

void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack);
void	ft_rotate(t_list *lst, t_stack **stack, char list);

void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack);
void	ft_swap(t_list *lst, t_stack **stack, char list);

// FONCTION STACK
void	ft_stack(char *str, t_stack **stack);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_print(t_stack *stack);

#endif