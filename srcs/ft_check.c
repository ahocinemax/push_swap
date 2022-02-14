/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:47:15 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/14 21:44:39 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_int(char *str)
{
	int		len;
	int		i;
	int		n;
	char	*max;

	i = 0;
	n = 0;
	if (!str)
		return (1);
	if (str[0] == '-')
	{
		max = "2147483648";
		str++;
	}
	else
		max = "2147483647";
	while (str[i] == '0')
		i++;
	len = ft_strlen(str) - i;
	if (len > 10)
		return (1);
	else if (len == 10)
		if (ft_strcmp(str, max) > 0)
			return (1);
	return (0);
}

static int	ft_check_str(char **str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-' && str[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_double(char **str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check(char **str, int size, t_stack **stack)
{
	int	overlap;
	int	i;

	*stack = NULL;
	overlap = 0;
	i = 0;
	if (ft_check_str(str, size) || ft_check_double(str, size))
		return (-1);
	while (i < size && str[i])
	{
		overlap = ft_check_int(str[i]);
		if (overlap == 1)
			return (-1);
		i++;
	}
	return (0);
}
