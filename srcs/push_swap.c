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

static int	ft_free_all(char **str, t_list **a, t_list **b, int argc)
{
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	if (argc == 1)
		ft_free_all2(str);
	else
		free(str);
	return (0);
}

static int	ft_error(char **str, t_list **a, int argc)
{
	ft_putstr_fd("Error\n", _STD_ERR);
	ft_free_all(str, a, NULL, argc);
	return (-1);
}

static void	ft_init_lst(t_list **a, char **str)
{
	t_list	*new;
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new || (*a && ft_is_in_lst(new->content, *a)))
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
	if (!*argv)
		return (NULL);
	if (argc == 1)
		return (ft_split(*argv, ' '));
	str = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!str)
		return (NULL);
	while (argv[i])
	{
		str[i] = argv[i];
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

	if (argc == 1)
		return (EXIT_SUCCESS);
	argc--;
	str = ft_parse_args(argc, argv, &a, &b);
	if (!str || ft_check(str, argc, &s))
		return (ft_error(str, &a, argc));
	ft_init_lst(&a, str);
	if (!a)
		return (ft_error(str, &a, argc));
	if (ft_is_sort(a))
		return (ft_free_all(str, &a, &b, argc));
	i = NULL;
	ft_init_lst(&i, str);
	ft_set_index(i, &a);
	ft_lstclear(&i, NULL);
	// printf("size of A at begining : %d\n", ft_lstsize(a));
	// printf("size of B at begining : %d\n", ft_lstsize(b));
	ft_sort(&a, &b, &s);
	// ft_lstprint_index(a);
	// printf("%d\n\n", ft_lstsize(a));
	// ft_lstprint_index(b);
	// printf("%d element in B, A is sorted : %d\n", ft_lstsize(b), ft_is_sort(a));
	printf("%d operations\n", ft_stack_size(s));
	// ft_stack_print(s);
	ft_stack_clear(&s);
	return (ft_free_all(str, &a, &b, argc));
}
