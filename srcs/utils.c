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

int	ft_smaller(t_list *lst)
{
	int		mini;
	t_list	*tmp;

	if (!lst)
		return (0);
	mini = lst->content;
	tmp = lst->next;
	while (tmp)
	{
		if (mini > tmp->content)
			mini = tmp->content;
		tmp = tmp->next;
	}
	return (mini);
}

int	ft_bigger(t_list *lst)
{
	int		maxi;
	t_list	*tmp;

	if (!lst)
		return (0);
	maxi = lst->content;
	tmp = lst->next;
	while (tmp)
	{
		if (maxi < tmp->content)
			maxi = tmp->content;
		tmp = tmp->next;
	}
	return (maxi);
}

char	*ft_pattern(t_list *a)
{
	if (a->content > a->next->content && a->content > a->next->next->content)
	{
		if (a->next->content > a->next->next->content)
			return ("cba");
		else
			return ("cab");
	}
	else if (a->content < a->next->content && \
		a->content < a->next->next->content)
		return ("acb");
	else
	{
		if (a->content < a->next->content && \
			a->content > a->next->next->content)
			return ("bca");
		else
			return ("bac");
	}
}

void	ft_stack_print(t_stack *s)
{
	char	*str;

	while (s)
	{
		str = s->str;
		ft_putstr_fd(str, _STD_OUT);
		s = s->next;
	}
}

static int	*ft_index(t_list **a)
{
	t_list	*tmp;
	int		*res;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(*a);
	res = (int *)malloc(size * sizeof(int));
	tmp = *a;
	while (tmp)
	{
		res[i] = 0;
		while (tmp->content != ft_smaller(tmp))
			ft_rotate(tmp, NULL, 'c');
		res[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	ft_set_index(t_list *temp, t_list **a)
{
	int	head;
	int	*index;
	int	i;

	head = (*a)->content;
	index = ft_index(&temp);
	i = 0;
	while (i < ft_lstsize(*a))
	{
		while (index[i] != (*a)->content)
			ft_reverse(a, NULL, 'x');
		(*a)->index = i;
		i++;
	}
	free(index);
	while ((*a)->content != head)
		ft_reverse(a, NULL, 'x');
}

void	ft_lstprint_index(t_list *lst)
{
	int	value;

	if (!lst)
		ft_putstr_fd("liste vide", _STD_OUT);
	else
	{
		while (lst)
		{
			value = lst->index;
			ft_putchar_fd('[', _STD_OUT);
			ft_putnbr_fd(value, _STD_OUT);
			ft_putstr_fd("] ", _STD_OUT);
			lst = lst->next;
		}
	}
	ft_putchar_fd('\n', _STD_OUT);
}
