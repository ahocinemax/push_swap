/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:50:48 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 23:50:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rot_or_rev(t_list *a, t_list *b)
{
	t_list	*tmp;
	int		index_min;
	int		index_max;
	int		min;
	int		max;

	index_min = 0;
	index_max = 0;
	min = ft_smaller(a);
	max = ft_bigger(a);
	tmp = a;
	while (tmp->content != min)
	{
		tmp = tmp->next;
		index_min++;
	}
	tmp = a;
	while (tmp->content != max)
	{
		tmp = tmp->next;
		index_max++;
	}
	return (index_max > index_min);
}
