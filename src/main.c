/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:42:56 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/20 12:17:22 by bizcru           ###   ########.fr       */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int ft_input_checker(char **argv)
{
	argv++;
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2));
	if (!ft_input_checker(argv))
		return (ft_putstr_fd("Error\n", 2));
	argv++;
	ft_putstr_fd("you win :)", 1);
	return (0);
}
