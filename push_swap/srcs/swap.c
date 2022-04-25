/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:37:52 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/19 17:19:02 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*swap(t_lst **list)
{
	int		a;
	t_lst	*tmp;

	tmp = *list;
	if (!tmp || !tmp->next)
		return (NULL);
	a = tmp->next->content;
	tmp->next->content = tmp->content;
	tmp->content = a;
	*list = tmp;
	return (*list);
}

void	rra(t_lst **s)
{
	t_lst	*tmp;
	t_lst	*prev;

	if (ft_lstsize(s) <= 1)
		return ;
	tmp = *s;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *s;
	prev->next = NULL;
	*s = tmp;
}

void	push_stack(t_lst **dst, t_lst **src)
{
	t_lst	*tmp;

	if (!src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	(*dst) = (*src);
	(*src) = tmp;
}

void	ra(t_lst **list)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = (*list)->next;
	last = (*list);
	while (last->next)
		last = last->next;
	last->next = (*list);
	(*list)->next = NULL;
	(*list) = tmp;
}
