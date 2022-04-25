/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:05 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/23 16:50:01 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort_ter(t_swap *list, int num, int i)
{
	if (((num >> i) & 1) == 1)
	{
		ra(&list->stack_a);
		write(1, "ra\n", 3);
	}
	else
	{
		push_stack(&list->stack_b, &list->stack_a);
		write(1, "pb\n", 3);
	}
}

void	big_sort_bis(t_swap *list, int size, int max_bits)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = list->stack_a->index;
			big_sort_ter(list, num, i);
			j++;
		}
		while (list->stack_b != NULL)
		{
			push_stack(&list->stack_a, &list->stack_b);
			write(1, "pa\n", 3);
		}
		i++;
	}
}

void	big_sort(t_swap *list)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = ft_lstsize(&list->stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	check_index(&list->stack_a);
	big_sort_bis(list, size, max_bits);
}
