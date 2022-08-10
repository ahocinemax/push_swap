#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void	ft_lstprint(t_list *lst)
{
	int	value;

	if (!lst)
		printf("liste vide");
	else
	{
		while (lst)
		{
			value = lst->data;
			printf("[%d] ", value);
			lst = lst->next;
		}
	}
	printf("\n");
}

int cmp(int a, int b)
{
    return (a <= b);
}

int is_sorted(t_list *lst, int (*cmp)(int, int))
{
    if (!lst)
        return 0;
    while (lst->next)
    {
        if (!cmp(lst->data, lst->next->data))
            return 0;
        lst = lst->next;
    }
    return 1;
}

void    swap_data(int *data1, int *data2)
{
    int tmp = *data1;
    *data1 = *data2;
    *data2 = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    if(!lst || !cmp)
        return NULL;
    t_list	*tmp = lst;
	while(!is_sorted(lst, cmp))
	{
		if (tmp->next && !(*cmp)(tmp->data, tmp->next->data))
			swap_data(&tmp->data, &tmp->next->data);
        if (tmp->next && lst->next->next)
            tmp = tmp->next;
		else
			tmp = lst;
	}
	return (lst);
}

int main(void)
{
    t_list *fst = (t_list *)malloc(sizeof(t_list));
    t_list *snd = (t_list *)malloc(sizeof(t_list));
    t_list *trd = (t_list *)malloc(sizeof(t_list));
    t_list *fth = (t_list *)malloc(sizeof(t_list));
    fst->next = snd;
    fst->data = 40;
    snd->next = trd;
    snd->data = 1;
    trd->next = fth;
    trd->data = -8;
    fth->next = NULL;
    fth->data = 10;
    t_list *res = sort_list(fst, &cmp);
    printf("res : ");
    ft_lstprint(res);
    free(fst);
    free(snd);
    free(trd);
    free(fth);
    return 0;
}