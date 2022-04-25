/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:53 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/23 16:49:49 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	medium_sort_bis(t_swap *list, int size, int min)
{
	while (size > 3)
	{
		if (nb_ra(list->stack_a) <= nb_rra(list->stack_a))
		{
			while (min > 0)
			{
				ra(&list->stack_a);
				write(1, "ra\n", 3);
				min--;
			}
		}
		else
		{
			while (size - min > 0)
			{
				rra(&list->stack_a);
				write(1, "rra\n", 4);
				min++;
			}
		}
		push_stack(&list->stack_b, &list->stack_a);
		write(1, "pb\n", 3);
		size--;
		min = check_index_min(list->stack_a);
	}
}

void	medium_sort(t_swap *list)
{
	int	size;
	int	min;

	min = check_index_min(list->stack_a);
	size = ft_lstsize(&list->stack_a);
	medium_sort_bis(list, size, min);
	if (!is_sorted(&list->stack_a, 1))
		little_sort(list);
	push_stack(&list->stack_a, &list->stack_b);
	write(1, "pa\n", 3);
	if (list->stack_b)
	{
		push_stack(&list->stack_a, &list->stack_b);
		write(1, "pa\n", 3);
	}
}
