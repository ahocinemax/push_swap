/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:56:38 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/05 04:09:52 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstcpy(tlist *lst)
{
    t_list  **res;
    t_list  *node;

    while (lst)
    {
        node = ft_lstnew(lst->content);
        ft_lstadd_back(res, new);
        lst = lst->next;
    }
    return (node);
}
