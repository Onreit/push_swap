/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:45:16 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/20 13:08:29 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	little_sort_ter(t_swap *list, t_lst *tmp)
{
	if (tmp->content < tmp->next->next->content)
	{
		list->stack_a = swap(&list->stack_a);
		write(1, "sa\n", 3);
		ra(&list->stack_a);
		write(1, "ra\n", 3);
	}
	else
	{
		rra(&list->stack_a);
		write(1, "rra\n", 4);
	}
}

void	little_sort_bis(t_swap *list, t_lst *tmp)
{
	if (tmp->content < tmp->next->next->content)
	{
		list->stack_a = swap(&list->stack_a);
		write(1, "sa\n", 3);
	}
	else if (tmp->next->content < tmp->next->next->content)
	{
		ra(&list->stack_a);
		write(1, "ra\n", 3);
	}
	else
	{
		list->stack_a = swap(&list->stack_a);
		write(1, "sa\n", 3);
		rra(&list->stack_a);
		write(1, "rra\n", 4);
	}
}

void	little_sort(t_swap *list)
{
	t_lst	*tmp;

	tmp = list->stack_a;
	if (tmp->content > tmp->next->content)
		little_sort_bis(list, tmp);
	else
		little_sort_ter(list, tmp);
}
