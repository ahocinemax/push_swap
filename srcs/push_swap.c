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
	int	i = 0;
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_stack_clear(s);
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

static int	ft_error(char **str, t_list **a, t_stack **s)
{
	ft_putstr_fd("Error\n", _STD_OUT);
	ft_free_all(str, a, NULL, s);
	return (-1);
}

static void	ft_init_lst(t_list **a, char **str, int argc)
{
	t_list	*new;
	int		i;

	(void)argc;
	i = 0;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
		{
			ft_lstclear(a, NULL);
			return ;
		}
		ft_lstadd_back(a, new);
		i++;
	}
}

static char	**ft_parse_args(int argc, char **argv, t_list **a, t_list **b)
{
	int		i;
	char	**str;

	*a = NULL;
	*b = NULL;
	i = 0;
	argv++;
	if (argc == 1)
	{
		str = ft_split(*argv, ' ');
		return (str);
	}
	str = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!str)
		return (NULL);
	while (i < argc || argv[i])
	{
		str[i] = ft_strdup(argv[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*i;
	t_stack	*s;
	char	**str;

	if (argc < 2)
		return (-1);
	argc--;
	str = ft_parse_args(argc, argv, &a, &b);
	if (!str || ft_check(str, argc, &s))
		return (ft_error(str, &a, &s));
	ft_init_lst(&a, str, argc);
	if (ft_is_sort(a))
		return (ft_free_all(str, &a, &b, &s));
	i = NULL;
	ft_init_lst(&i, str, argc);
	ft_set_index(i, &a);
	ft_lstclear(&i, NULL);
	free(i);
	ft_sort(&a, &b, &s);
	ft_stack_print(s);
	return (ft_free_all(str, &a, &b, &s));
}
