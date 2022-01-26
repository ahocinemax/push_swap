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

int	ft_free_all(char **str, t_list **a, t_list **b, t_stack **s)
{
	free(str);
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_stack_clear(s);
	return (0);
}

int	ft_error(char **str, t_list **a, t_list **b, t_stack **s)
{
	ft_putstr_fd("Error\n", _STD_OUT);
	ft_free_all(str, a, b, s);
	return (-1);
}

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

char	*ft_pattern(t_list *a)
{
	char	*res;

	if (a->content > a->next->content && a->content > a->next->next->content)
	{
		if (a->next->content > a->next->next->content)
			res = "cba";
		else
			res = "cab";
	}
	else if (a->content < a->next->content && \
		a->content < a->next->next->content)
		res = "acb";
	else
	{
		if (a->content < a->next->content && \
			a->content > a->next->next->content)
			res = "bca";
		else
			res = "bac";
	}
	return (res);
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
