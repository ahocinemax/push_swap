/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:31:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/01/20 15:31:26 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init_lst(t_list **a, char **str, int size)
{
	t_list	*new;
	int		i;

	i = 0;
	size--;
	while (i < size)
	{
		new = ft_lstnew(ft_atoi(str[i++]));
		if (!new)
		{
			ft_lstclear(a, NULL);
			return ;
		}
		ft_lstadd_back(a, new);
	}
}

/*static t_data	ft_init_data(t_list **a, t_list **b, t_stack **s)
{
	t_data	data;

	*a = NULL;
	*b = NULL;
	*s = NULL;
	data.min = 0;
	data.max = 0;
	data.c_min = 0;
	data.c_max = 0;
	data.chunk = 0;
	return (data);
}*/

static char	**ft_parse_args(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * argc - 1);
	while (i < argc || argv[i + 1] != NULL)
	{
		str[i] = argv[i + 1];
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	//t_list	*b;
	//t_stack	*s;
	//t_data	data;
	char	**str;

	if (argc < 2)
		return (-1);
	//data = ft_init_data(&a, &b, &s);
	str = ft_parse_args(argc, argv);
	ft_init_lst(&a, str, argc);
	if (!str || !ft_check(str, argc))
	{
		ft_putstr_fd("Error\n", _STD_OUT);
		return (-1);
	}
	if (ft_is_sort(a))
	{
		//ft_free_all(&a, &b, &s, str);
		return (0);
	}
	ft_lstprint(a);
	free(a);
	return (0);
}
