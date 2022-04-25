/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:39:50 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/25 10:11:38 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_dup(t_lst *list, t_swap *swap)
{
	t_lst	*tmp;
	t_lst	*lmp;

	tmp = list;
	lmp = tmp->next;
	while (tmp->next)
	{
		while (lmp)
		{
			if (tmp->content == lmp->content)
				exit_push(swap, NULL);
			lmp = lmp->next;
		}
		tmp = tmp->next;
		if (tmp->next)
			lmp = tmp->next;
	}
}

int	is_sorted(t_lst	**list, int stack)
{
	int		i;
	t_lst	*tmp;
	t_lst	*tmp2;

	i = 0;
	tmp = *list;
	tmp2 = tmp->next;
	while (i < ft_lstsize(list) - 1)
	{
		if ((tmp->content < tmp2->content && stack == 1)
			|| (tmp->content > tmp2->content && stack == 2))
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

t_lst	*ft_list_push(int ac, char **av, t_swap *swap)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		n;
	int		i;

	tmp = NULL;
	tmp2 = NULL;
	i = ac - 1;
	while (i > 0)
	{
		/* free tmp */
		n = ft_atoi(av[i], swap, NULL);
		tmp = ft_create_elem(n, swap);
		tmp->next = tmp2;
		tmp2 = tmp;
		i--;
	}
	return (tmp);
}

int	ft_split_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

t_lst	*ft_list_push_str(char *av, t_swap *swap)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		n;
	int		i;
	char	**tmp_split;

	tmp = NULL;
	tmp2 = NULL;
	tmp_split = ft_split(av, ' ');
	i = ft_split_len(tmp_split) - 1;
	/* free tmp */ 
	while (i >= 0)
	{
		n = ft_atoi(tmp_split[i], swap, tmp_split);
		tmp = ft_create_elem(n, swap);
		tmp->next = tmp2;
		tmp2 = tmp;
		i--;
	}
	free_split(tmp_split);
	return (tmp2);
}
