/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:05:21 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/18 18:05:23 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		ft_putstr_fd("liste vide", _STD_OUT);
	else
	{
		while (lst)
		{
			if (!lst->content)
				ft_putstr_fd("[NULL] ", _STD_OUT);
			else
			{
				ft_putchar_fd('[', _STD_OUT);
				ft_putnbr_fd(lst->content, _STD_OUT);
				ft_putstr_fd('] ', _STD_OUT);
			}
		}
	}
	ft_putchar_fd('\n', _STD_OUT);
}

int	ft_is_sort(t_list *lst)
{
	t_list	*last;

	last = ft_lstlast(lst);
	while (lst != last)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

void	ft_swap(int *tab_to_swap)
{
	// SWAP LES DEUX PREMIERES VALEURS
	int	tmp;

	if (!tab_to_swap[2])
		return ;
	tmp = tab_to_swap[0];
	tab_to_swap[0] = tab_to_swap[1];
	tab_to_swap[1] = tmp;
}

void	ft_push(int *tab_a, int *tab_b)
{
	int	tmp;

	tmp = tab_a[0];
	tab_a[0] = tab_b[0];
	tab_b[0] = tmp;
}

void	ft_shift()
{
	;
}