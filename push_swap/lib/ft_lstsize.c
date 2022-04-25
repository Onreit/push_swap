/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:17:55 by tjalo             #+#    #+#             */
/*   Updated: 2021/12/02 23:01:24 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_lst **lst)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = *lst;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
