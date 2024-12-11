/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:17:19 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/11 19:04:29 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

static void	do_sort(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		do_rotate(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rotate(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_two(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_r_rotate(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_r_rotate(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		r_rotate_two(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		do_push(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_push(stack_b, stack_a);
	else if (ft_strcmp(line, "sa\n") == 0)
		do_swap(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_swap(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_two(stack_a, stack_b);
}



static int	check_line(char *line)
{
	char	**checks;
	char	*l;
	int		i;

	i = 0;
	l = ft_strdup("rrr\n rra\n rrb\n rr\n ra\n rb\n ss\n sa\n sb\n pa\n pb\n");
	if (!l)
		return (0);
	checks = ft_split(l, ' ');
	free(l);
	if (!checks)
		return (0);
	while (checks[i])
	{
		if (ft_strcmp(checks[i++], line) == 0)
		{
			ft_free_array(checks);
			return (1);
		}
	}
	ft_free_array(checks);
	return (0);
}

int	sort_serf(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		if (!check_line(line))
		{
			free(line);
			ft_lstclear(stack_a);
			ft_lstclear(stack_b);
			return (0);
		}
		do_sort(stack_a, stack_b, line);
		free(line);
	}
}
