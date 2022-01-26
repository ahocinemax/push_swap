/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:40:55 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 06:40:56 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list *lst, t_stack **stack, char list)
{
	int	tmp;
	int	tmp2;

	tmp = lst->content;
	tmp2 = lst->next->content;
	lst->content = tmp2;
	lst->next->content = tmp;
	if (list == 'a')
		ft_stack("sa", stack);
	else
		ft_stack("sb", stack);
}

void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack)
{
	ft_swap(a, stack, 'a');
	ft_swap(b, stack, 'b');
}

void	ft_rotate(t_list *lst, t_stack **stack, char list)
{
	t_list	*tmp;
	int		high;

	if (!lst || !lst->next)
		return ;
	high = lst->content;
	tmp = lst->next;
	while (lst->next)
	{
		tmp = lst->next;
		lst->content = tmp->content;
		lst = lst->next;
	}
	lst->content = high;
	lst->next = NULL;
	if (list == 'a')
		ft_stack("ra", stack);
	else
		ft_stack("rb", stack);
}

void	ft_rotate_rr(t_list *a, t_list *b, t_stack **stack)
{
	ft_rotate(a, stack, 'a');
	ft_rotate(b, stack, 'b');
}
