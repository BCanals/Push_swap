/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 21:13:47 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <time.h>

void	print_lst(int data)
{
	ft_printf("%i\n", data);
}

/*
   Helper code:
	struct timespec start, end;
	double elapsed;
	elapsed = end.tv_sec - start.tv_sec;
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	clock_gettime(CLOCK_MONOTONIC, &start);
	clock_gettime(CLOCK_MONOTONIC, &end);
*/

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = data_loader(argc, argv);
	printf("duració: %f secs\n", elapsed);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	ft_lstiter(stack_a, print_lst);
	ft_lstclear(&stack_a);
	return (0);
}
