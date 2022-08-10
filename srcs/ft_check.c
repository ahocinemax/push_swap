/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:47:15 by ahocine           #+#    #+#             */
/*   Updated: 2022/04/13 17:47:42 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_in_lst(int val, t_list *a)
{
	t_list	*tmp;

	if (!a)
		return (EXIT_SUCCESS);
	tmp = a;
	while (tmp)
	{
		if (tmp->content == val)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_int(char *str)
{
	char	*max;
	int		len;
	int		i;

	i = 0;
	if (!str)
		return (EXIT_FAILURE);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			max = "2147483648";
		str++;
	}
	else
		max = "2147483647";
	while (str[i] == '0' && str[i + 1])
		i++;
	len = ft_strlen(str) - i;
	if (len > 10 || !*str)
		return (EXIT_FAILURE);
	else if (len == 10)
		if (ft_strcmp(str, max) > 0)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_check_str(char **str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (str[i])
	{
		j = 0;
		c = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				c++;
			if ((!ft_isdigit(str[i][j]) && str[i][j] != '-' && \
				str[i][j] != '+') || c > 1)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_double(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				ft_putstr_fd("Double trouve\n", _STD_ERR);
				printf("%s %d\n", str[i], i);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check(char **str, int size __attribute__ ((unused)), t_stack **stack)
{
	int	overlap;
	int	i;

	*stack = NULL;
	overlap = 0;
	i = 0;
	if (ft_check_str(str) || ft_check_double(str))
		return (EXIT_FAILURE);
	while (str[i])
	{
		overlap = ft_check_int(str[i]);
		if (overlap == 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
