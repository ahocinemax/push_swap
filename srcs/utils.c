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
