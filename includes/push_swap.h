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

# define MIN		0
# define MAX		1

# define FALSE		0
# define TRUE		1

typedef struct s_stack
{
	struct s_stack	*next;
	char			*str;
}					t_stack;

typedef struct s_data
{
	int				markup;
	int				size;
	int				head;
}					t_data;

// UTILS
void	ft_move(t_list **a, t_list **b, t_stack **stack, t_data *data);
void	ft_sort(t_list **a, t_list **b, t_stack **stack, t_data *data);
void	ft_set_index(t_list *i, t_list **a, t_data **data);
int		ft_check(char **str, int size, t_stack **stack);
void	ft_lstprint_index(t_list *lst);
int		ft_count_suite(t_list *a);
int		ft_rot_or_rev(t_list *a);
int		ft_smaller(t_list *lst);
int		ft_bigger(t_list *lst);
char	*ft_pattern(t_list *a);
int		*ft_index(t_list **a);

// FONCTION DE MOUVEMENT
void	ft_push(t_list **to, t_list **from, t_stack **stack, char *list);
void	ft_reverse_rr(t_list **a, t_list **b, t_stack **stack);
void	ft_reverse(t_list **lst, t_stack **stack, char *list);
void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack);
void	ft_rotate(t_list *lst, t_stack **stack, char *list);
void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack);
void	ft_swap(t_list *lst, t_stack **stack, char *list);

// FONCTION STACK
void	ft_stack(char *str, t_stack **stack);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_print(t_stack *stack);

#endif