/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:05:21 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/18 18:05:23 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list *a, t_stack **stack, char list)
{
	int	tmp;
	int	tmp2;

	tmp = a->content;
	tmp2 = a->next->content;
	a->content = tmp2;
	a->next->content = tmp;
	if (list == 'a')
		ft_stack("sa", stack);
	else
		ft_stack("sb", stack);
}

void	ft_swap_ss(t_list *a, t_list *b, t_stack **stack)
{
	ft_swap(a, stack);
	ft_swap(b, stack);
}

void	ft_push(int *tab_a, int *tab_b)
{
	int	tmp;

	tmp = tab_a[0];
	tab_a[0] = tab_b[0];
	tab_b[0] = tmp;
}

void	ft_free_all(char **str, t_list **a, t_list **b, t_stack **s)
{
	free(str);
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	*s = NULL;
	(void)s;
}

int	ft_error(char **str, t_list **a, t_list **b, t_stack **s)
{
	ft_putstr_fd("Error\n", _STD_OUT);
	ft_free_all(str, a, b, s);
	return (-1);
}