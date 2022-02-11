/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:27:16 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/07 14:27:21 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_set_index(t_list *temp, t_list **a)
{
	int	*index;
	int	tmp;
	int	i;

	index = ft_index(&temp);
	tmp = (*a)->content;
	i = 0;
	while (i < ft_lstsize(*a))
	{
		while (index[i] != (*a)->content)
			ft_reverse(a, NULL, NULL);
		(*a)->index = i;
		i++;
	}
	free(index);
	while ((*a)->content != tmp)
		ft_reverse(a, NULL, NULL);
}
