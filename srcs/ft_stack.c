/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 07:30:04 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/26 07:30:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_stack_new(char *str)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

static t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	ft_stack_add_back(t_stack **actual, t_stack *new)
{
	t_stack	*last;

	if (!new || !actual)
		return ;
	if (!*actual)
	{
		*actual = new;
		return ;
	}
	last = ft_stack_last(*actual);
	new->next = NULL;
	last->next = new;
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}

void	ft_stack(char *str, t_stack **stack)
{
	t_stack	*new;

	new = ft_stack_new(str);
	if (!new)
		return ;
	ft_stack_add_back(stack, new);
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}