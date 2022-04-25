/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:48:22 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/22 13:12:52 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_int_tab_swap(int *t, int i, int j)
{
	int	tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

int	*ft_quicksort(int *t, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (t[i] <= t[pivot] && i < end)
				i++;
			while (t[j] > t[pivot])
				j--;
			if (i < j)
				ft_int_tab_swap(t, i, j);
		}
		ft_int_tab_swap(t, pivot, j);
		(void)ft_quicksort(t, start, j - 1);
		(void)ft_quicksort(t, j + 1, end);
	}
	return (t);
}

void	check_index_bis(t_lst **list, int *tab, int size)
{
	int	i;

	while (*list)
	{
		i = 0;
		while (i < size)
		{
			if ((*list)->content == tab[i])
				(*list)->index = i;
			i++;
		}
		(*list) = (*list)->next;
	}
}

void	check_index(t_lst **list)
{
	int		*tab;
	int		i;
	t_lst	*tmp;
	int		size;

	i = 0;
	tmp = (*list);
	size = ft_lstsize(list);
	tab = malloc(sizeof(int) * (size + 1));
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tab = ft_quicksort(tab, 0, i - 1);
	tmp = (*list);
	check_index_bis(list, tab, size);
	(*list) = tmp;
	free(tab);
}
