/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:50:48 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/27 04:48:54 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free(int **a, int **b)
{
	free(*a);
	*a = NULL;
	free(*b);
	*b = NULL;
}

static void	ft_nb_mouvement(int *nb_mouv, int size, int *index)
{
	if (index[MAX] > size / 2)
		nb_mouv[MAX] = size - index[MAX] + 1;
	else if (index[MAX] < size / 2)
		nb_mouv[MAX] = index[MAX];
	if (index[MIN] > size / 2)
		nb_mouv[MIN] = size - index[MIN] + 1;
	else if (index[MIN] < size / 2)
		nb_mouv[MIN] = index[MIN];
}

static void	ft_index(t_list *a, int **index)
{
	t_list	*tmp;
	int		mini;
	int		maxi;

	(*index) = (int *)ft_calloc(0, sizeof(int) * 2);
	if (!*index)
		return ;
	tmp = a;
	mini = ft_smaller(a);
	maxi = ft_bigger(a);
	while (tmp && tmp->content != mini)
	{
		tmp = tmp->next;
		(*index)[MIN] += 1;
	}
	tmp = a;
	while (tmp && tmp->content != maxi)
	{
		tmp = tmp->next;
		(*index)[MAX] += 1;
	}
}

int	ft_rot_or_rev(t_list *a)
{
	int	*index;
	int	*nb_mouv;
	int	ret;

	ft_index(a, &index);
	nb_mouv = (int *)ft_calloc(0, sizeof(int) * 2);
	if (!nb_mouv)
		return (0);
	ft_nb_mouvement(nb_mouv, ft_lstsize(a), index);
	if (nb_mouv[MIN] < nb_mouv[MAX])
	{
		if (index[MIN] > ft_lstsize(a) / 2)
			ret = 1;
		else
			ret = 0;
	}
	else
	{
		if (index[MAX] > ft_lstsize(a) / 2)
			ret = 1;
		else
			ret = 0;
	}
	ft_free(&index, &nb_mouv);
	return (ret);
}
