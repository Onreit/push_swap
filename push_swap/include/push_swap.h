/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:05:19 by tjalo             #+#    #+#             */
/*   Updated: 2022/04/25 09:33:45 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	struct s_lst	*next;
	int				content;
	int				index;
}				t_lst;

typedef struct s_swap
{
	t_lst	*stack_a;
	t_lst	*stack_b;
}				t_swap;

t_lst	*ft_create_elem(int data, t_swap *swap);
void	clear_list(t_lst **begin_list);
t_lst	*swap(t_lst **swap);
void	*rot_list(t_lst **list);
void	rra(t_lst **s);
void	ra(t_lst **list);
void	check_dup(t_lst *list, t_swap *swap);
t_lst	*ft_list_push(int ac, char **av, t_swap *swap);
int		ft_atoi(const char *s, t_swap *swap, char **split);
void	ft_bzero(t_swap *s, size_t n);
int		ft_isdigit(int c);
int		ft_lstsize(t_lst **lst);
char	**ft_split(char const *str, char c);
size_t	ft_strlen(const char *str);
void	exit_push(t_swap *list, char **split);
int		is_sorted(t_lst	**list, int stack);
void	push_stack(t_lst **dst, t_lst **src);
t_swap	*ft_init(void);
void	free_split(char **str);
t_lst	*ft_list_push_str(char *av, t_swap *swap);
void	little_sort(t_swap *list);
int		check_index_min(t_lst *stack);
void	medium_sort(t_swap *list);
int		nb_ra(t_lst *tmp);
int		nb_rra(t_lst *tmp);
void	check_index(t_lst **list);
void	big_sort(t_swap *list);

#endif