/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/29 20:08:57 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

/*
   function to be called to free memory and return NULL.
*/

static void	*clean_up(char **prms, int *data)
{
	int	i;

	i = 0;
	while (prms[i])
		free(prms[i++]);
	free(prms);
	free(data);
	return (NULL);
}

/* 
   Checks if any of the parameters passed by user is not a number.
   Returns 1 if all is right and 0 otherwise.
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

/*
   Converts the list of ASCII numbert to int. Also checks for integer overflow.
   Return NULL if there's any problem, or a pointer to an array of integers.
*/

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
   Function to check if the values of a int array have duplicates.
*/

static int	array_dup_check(int *data)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < (data[0]))
	{
		while (j <= data[0])
		{
			if (data[i] == data[j++])
			{
				free(data);
				return (0);
			}
		}
		i++;
		j = i + 1;
	}
	return (1);
}

/*
	Funtion in charge of coordinating the checking of params and the case for 
	a string of values and a list of individual ones.
	Returns the loaded stack_a if all is right or NULL otherwise.
*/

t_node	*data_loader(int argc, char **argv)
{
	int		*data;
	char	**char_list;
	t_node	*stack_a;

	if (argc == 2)
	{
		char_list = ft_split(argv[1], ' ');
		if (char_list == NULL)
			return (NULL);
		data = ft_splittoi(char_list);
		clean_up(char_list, NULL);
	}
	else if (argc > 2)
		data = ft_splittoi(++argv);
	if (!data)
		return (NULL);
	if (!array_dup_check(data))
		return (NULL);
	stack_a = initial_data_load(data);
	free(data);
	if (stack_a == NULL)
		return (NULL);
	return (stack_a);
}
