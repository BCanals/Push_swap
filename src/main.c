/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/22 22:56:14 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("duració: %f secs\n", elapsed);
*/

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = data_loader(argc, argv);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	t_node *stack_b;
	stack_b = ft_calloc(sizeof(t_node), 1);
	t_node *second_b;
	second_b = ft_calloc(sizeof(t_node), 1);
	stack_b->next = second_b;
	stack_b->data = 1;
	second_b->data = 2;
	ft_printf("STACK A:\n----\n");
	ft_lstiter(stack_a, print_lst);
	ft_printf("STACK B:\n----\n");
	ft_lstiter(stack_b, print_lst);
	ft_printf("----\n----\n");
	do_push(&stack_a, &stack_b, 'a');
	ft_printf("----\n----\n");
	ft_printf("STACK A:\n----\n");
	ft_lstiter(stack_a, print_lst);
	ft_printf("STACK B:\n----\n");
	ft_lstiter(stack_b, print_lst);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
