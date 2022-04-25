/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:56:23 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/22 13:06:09 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_index_min(t_lst *stack)
{
	t_lst	*tmp;
	int		index;
	int		i;
	int		value;

	i = 0;
	index = 0;
	tmp = stack;
	value = tmp->content;
	while (tmp->next)
	{
		i++;
		if (value > tmp->next->content)
		{
			value = tmp->next->content;
			index = index + i;
			i = 0;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	nb_ra(t_lst *list)
{
	int		i;
	int		min;
	t_lst	*tmp;

	i = 0;
	tmp = list;
	min = check_index_min(tmp);
	while (min - i > 0)
		i++;
	return (i);
}

int	nb_rra(t_lst *list)
{
	int		min;
	int		size;
	t_lst	*tmp;

	tmp = list;
	min = check_index_min(tmp);
	size = ft_lstsize(&tmp);
	if (min == 0)
		return (0);
	else
		return (size - min);
}
