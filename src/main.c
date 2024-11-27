/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/27 17:40:40 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

static void	print_lst(int data)
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
	printf("duració: %f secs\n", elapsed);
*/



int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = data_loader(argc, argv);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	ft_printf("STACK A:\n----\n");
	ft_lstiter(stack_a, print_lst);
	//aquí la funció per ordenar
	stack_b = load_b(&stack_a);
	ft_printf("----\n----\n");
	ft_printf("STACK A:\n----\n");
	ft_lstiter(stack_a, print_lst);
	ft_printf("STACK B:\n----\n");
	ft_lstiter(stack_b, print_lst);
	ft_lstiter_back(ft_lstlast(stack_a), print_lst);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
