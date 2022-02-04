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

static int	ft_free_all(char **str, t_list **a, t_list **b, t_stack **s)
{
	free(str);
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_stack_clear(s);
	return (0);
}

static int	ft_error(char **str, t_list **a, t_list **b, t_stack **s)
{
	ft_putstr_fd("Error\n", _STD_OUT);
	ft_free_all(str, a, b, s);
	return (-1);
}

static void	ft_init_lst(t_list **a, char **str, int	argc)
{
	t_list	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (argc == 1)
			free(str[i]);
		if (!new)
		{
			ft_lstclear(a, NULL);
			return ;
		}
		ft_lstadd_back(a, new);
		i++;
	}
}

static char	**ft_parse_args(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	if (argc == 1)
	{
		str = ft_split(argv[argc], ' ');
		return (str);
	}
	str = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!str)
		return (NULL);
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
	t_list	*b;
	t_stack	*s;
	char	**str;

	if (argc < 2)
		return (-1);
	a = NULL;
	b = NULL;
	s = NULL;
	argc--;
	str = ft_parse_args(argc, argv);
	if (!str || ft_check(str, argc))
		return (ft_error(str, &a, &b, &s));
	ft_init_lst(&a, str, argc);
	if (ft_is_sort(a))
		return (ft_free_all(str, &a, &b, &s));
	ft_sort(&a, &b, &s);
	//ft_lstprint(a);
	//ft_lstprint(b);
	ft_stack_print(s);
	return (ft_free_all(str, &a, &b, &s));
}
