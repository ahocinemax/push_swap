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

#include <unistd.h>
#include "../libft/libft.h"


#define _STD_OUT	1

typedef struct	s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				content;
}					t_list;

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

