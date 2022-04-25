/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:04:56 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/25 09:32:02 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *s, t_swap *swap, char **split)
{
	unsigned long long	nb;
	int					ng;
	int					i;

	nb = 0;
	i = 0;
	ng = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ng = -1;
		i++;
		if (s[i] == '\0')
			exit_push(swap, split);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + (s[i++] - '0');
		if ((nb > 2147483647 && ng == 1) || (nb > 2147483648 && ng == -1))
			exit_push(swap, split);
	}
	if (i == 0 || i != (int)ft_strlen(s))
		exit_push(swap, split);
	return (ng * nb);
}
