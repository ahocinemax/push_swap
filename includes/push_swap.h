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

// UTILS
void	ft_utils(int i, t_list **a, t_list **b, t_stack **stack);
void	ft_push_b(t_list **a, t_list **b, t_stack **stack);
void	ft_sort(t_list **a, t_list **b, t_stack **stack);
int		ft_check(char **str, int size, t_stack **stack);
void	ft_set_index(t_list *i, t_list **a);
int		ft_chunk_left(t_list *a, int pow);
int		ft_is_in_lst(int val, t_list *a);
void	ft_lstprint_index(t_list *list);
t_list	*ft_smaller_index(t_list *lst);
t_list	*ft_bigger_index(t_list *lst);
int		ft_rota(t_list *a, int pow);
int		ft_rev(t_list *a, int val);
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
int		ft_stack_size(t_stack *stack);

// FONCTION TRI
void	ft_five_hundred(t_list **a, t_list **b, t_stack **stack);
void	ft_push_beta(t_list **a, t_list **b, t_stack **stack);
void	ft_fhundred(t_list **a, t_list **b, t_stack **stack);
void	ft_hundred(t_list **a, t_list **b, t_stack **stack);
void	ft_five(t_list **a, t_list **b, t_stack **stack);
void	ft_three(t_list **a, t_stack **stack);

#endif