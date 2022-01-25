/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:06:06 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/18 18:06:10 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

# ifndef _STD_OUT
#  define _STD_OUT	1
# endif

typedef struct s_stack
{
	struct s_stack	*next;
	char			*str;
}					t_stack;

typedef struct s_data
{
	int				min;
	int				max;
	int				c_min;
	int				c_max;
	int				chunk;
}					t_data;

#endif

int	ft_check(char **str, int size);