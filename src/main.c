/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:42:56 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 02:13:34 by bizcru           ###   ########.fr       */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	param_checker(char **params)
{
	while (*params)
	{
		while (**params)
			if (**params
		if (**params == 45 && strlen(**params) > 11)
			return (0);

	}	
}

int	*ft_splittoi(char	*string)
{
	char	**char_list;
	int		*rtrn;
	int		i;

	i = 0;
	char_list = ft_split(string, ' ');
	if (!char_list)
		return (NULL);
	if (!param_checker(char_list))
		return (NULL);
	while (char_list[i])
		i++;
	rtrn = ft_calloc(i + 1, sizeof(int));
	rtrn[0] = i;
	while (--i >= 0)
		rtrn[i + 1] = ft_atoi(char_list[i]);
	i++;
	while (char_list[i])
		free(char_list[i++]);
	free(char_list);
	return (rtrn);
}

t_element	*data_loader(int argc, char **argv)
{
	int *data;

	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		data = ft_splittoi(argv[1]);
	else if (argc > 2)
		data = ft_join_data();
	else
		return (NULL);
	if (!data)
		return (NULL);
	if (!data_checker(data))
		return (NULL);
	return (data);	
}

int	main(int argc, char **argv)
{
	t_element	*stack_a;
	int 		i;

	stack_a = data_loader(argc, argv);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	
	i = 0;
	while (i <= test[0])
		ft_printf("%i\n", test[i++]);
	return (0);
}
