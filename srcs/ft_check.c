/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:47:15 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/25 19:47:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_int_min(char *str)
{
	int	len;

	if (!str)
		return (0);
	str++;
	len = ft_strlen(str);
	if (len > 10)
		return (0);
	else if (len == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	return (1);
}

static int	ft_int_max(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len > 10)
		return (0);
	else if (len == 10)
	{
		if (ft_strcmp(str, "2147483648") > 0)
			return (0);
	}
	return (1);
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

int	ft_check(char **str, int size)
{
	int	overlap;
	int	i;

	overlap = 0;
	i = 0;
	size--;
	if (ft_check_str(str, size) || ft_check_double(str, size))
		return (-1);
	while (i < size && str[i])
	{
		if (str[i][0] == '-')
			overlap = ft_int_min(str[i]);
		else
			overlap = ft_int_max(str[i]);
		if (overlap == 1)
			return (-1);
		i++;
	}
	return (0);
}
