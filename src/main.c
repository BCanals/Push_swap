/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 13:57:00 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

/*
   function to be called to free memory and return NULL.
*/

static int	*clean_up(char **prms)
{
	int	i;

	i = 0;
	while (prms[i])
		free(prms[i++]);
	free (prms);
	return (NULL);
}

/*
	Takes the already-checked number list of params passed by user,..............
	and checks that all numbers are inside int range.
	Returns 1 if all is right and 0 otherwise.


static int	param_checker_size(char	**prms)
{
	int	i;
	int	str_len;

	i = -1;
	while (prms[++i])
	{
		str_len = ft_strlen(prms[i]);
		if (str_len < 10)
			continue ;
		if (str_len > 11)
			return (0);
		if (str_len == 10)
			if (ft_strcmp("2147483647", prms[i]) < 0)
				return (0);
		if (str_len == 11)
		{
			if ((prms[i][0] != '-' && prms[i][0] != '+') ||
				(prms[i][0] == '-' && ft_strcmp("-2147483648", prms[i]) < 0) ||
				(prms[i][0] == '+' && ft_strcmp("+2147483647", prms[i]) < 0))
				return (0);
		}
	}
	return (1);
}
*/
/* 
   Checks if any of the parameters passed by user is not a number,
   and returns 0 if so. Otherwise, yields the return to param_checker_size.
*/

static int	param_checker(char **prms)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (prms[i])
	{
		if (prms[i][j] != '-' && prms[i][j] != '+' && !ft_isdigit(prms[i][j]))
			return (0);
		j++;
		while (prms[i][j])
			if (!ft_isdigit(prms[i][j++]))
				return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int	*ft_splittoi(char	**char_list)
{
	int		*rtrn;
	int		*temp;
	int		i;

	i = 0;
	if (!param_checker(char_list))
		return (NULL);
	while (char_list[i])
		i++;
	rtrn = ft_calloc(i + 1, sizeof(int));
	rtrn[0] = i;
	while (--i >= 0)
	{
		temp = ft_atoi_pshswp(char_list[i]);
		if (!temp)
		{
			free (rtrn);
			return (NULL);
		}
		rtrn[i + 1] = *temp;
		free(temp);
	}
	return (rtrn);
}

/*
	Funtion in charge of returning 0 if params aren't valid 
	or load stack_a otherwise.
*/

int	*data_loader(int argc, char **argv)
{
	int		*data;
	char	**char_list;

	if (argc == 1)
		return (NULL);
	else if (argc == 2)
	{
		char_list = ft_split(argv[1], ' ');
		if (char_list == NULL)
			return (clean_up(char_list));
		data = ft_splittoi(char_list);
		clean_up(char_list);
	}
	else if (argc > 2)
		data = ft_splittoi(++argv);
	if (!data)
		return (NULL);
	return (data);
}

int	main(int argc, char **argv)
{
	int	*data;
	int	i;

	data = data_loader(argc, argv);
	if (!data)
		return (ft_putstr_fd("Error\n", 2));
	i = 0;
	while (i <= data[0])
		ft_printf("%i\n", data[i++]);
	free(data);
	return (0);
}
