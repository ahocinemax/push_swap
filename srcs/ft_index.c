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

void	ft_set_index(t_list *temp, t_list **a, t_data **data)
{
	int	*index;
	int	i;

	*data = malloc(sizeof(t_data));
	(*data)->head = (*a)->content;
	(*data)->size = ft_lstsize(*a);
	index = ft_index(&temp);
	i = 0;
	while (i < (*data)->size)
	{
		while (index[i] != (*a)->content)
			ft_reverse(a, NULL, NULL);
		(*a)->index = i;
		i++;
	}
	free(index);
	while ((*a)->content != (*data)->head)
		ft_reverse(a, NULL, NULL);
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

static void	ft_push_wrong(t_list **curr, t_list **scnd, t_stack **s, t_data *d)
{
	int	i;

	i = 0;
	while ((*curr)->index != d->markup)
		ft_rotate(*curr, s, "ra\n");
	//printf("%d\n", ft_count_suite((*curr)));
	while (i < d->size)
	{
		if ((*curr)->keep == TRUE)
			ft_rotate(*curr, s, "ra\n");
		else
			ft_push(scnd, curr, s, "pb\n");
		i++;
	}
}

void	ft_move(t_list **curr, t_list **scnd, t_stack **s, t_data *data)
{
	t_list	*current;
	int		actual_count;
	int		max_count;
	int		i;

	current = *curr;
	max_count = 0;
	i = 0;
	while (i < ft_lstsize(*curr))
	{
		actual_count = ft_count_suite(current);
		if (actual_count > max_count)
		{
			data->markup = current->index;
			max_count = actual_count;
		}
		else if (actual_count == max_count && (current->index < data->markup))
			data->markup = current->index;
		i++;
		current = current->next;
	}
	ft_push_wrong(curr, scnd, s, data);
	//printf("FININSH\n");
}
