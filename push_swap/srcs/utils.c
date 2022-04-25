/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:17:23 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/25 09:53:43 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_list(t_lst **lst)
{
	t_lst	*list;
	t_lst	*tmp;

	if (!lst || !*lst)
		return ;
	list = *lst;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = NULL;
}

void	exit_push(t_swap *list, char **split)
{
	write(2, "Error\n", 6);
	if (split)
		free_split(split);
	clear_list(&list->stack_a);
	free(list);
	exit(1);
}

t_swap	*ft_init(void)
{
	t_swap	*list;

	list = (t_swap *)malloc(sizeof(t_swap));
	if (!list)
		return (NULL);
	ft_bzero(list, sizeof(t_swap));
	return (list);
}

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}
