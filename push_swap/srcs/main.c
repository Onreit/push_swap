/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:00:25 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/23 16:50:19 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_swap *list)
{
	if (ft_lstsize(&list->stack_a) == 2)
	{
		swap(&list->stack_a);
		write(1, "sa\n", 3);
	}
	else if (ft_lstsize(&list->stack_a) == 3)
		little_sort(list);
	else if (ft_lstsize(&list->stack_a) < 6)
		medium_sort(list);
	else
		big_sort(list);
}

int	main(int ac, char *av[])
{
	t_swap	*swap;

	if (ac == 1)
		return (0);
	swap = ft_init();
	swap->stack_b = NULL;
	if (ac == 2)
		swap->stack_a = ft_list_push_str(av[1], swap);
	else
		swap->stack_a = ft_list_push(ac, av, swap);
	check_dup(swap->stack_a, swap);
	if (!is_sorted(&swap->stack_a, 1))
		push_swap(swap);
	clear_list(&swap->stack_a);
	free(swap);
	return (0);
}
