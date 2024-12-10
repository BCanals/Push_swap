/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:53 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:33 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t len;

	i = 0;
	if (little[0] == 0)
		return (0);
		//return ((char *)(big));
	len = ft_strlen(big) - ft_strlen(little);
	while (i <= len)
	{
		printf("%c -> %i\n", *big, ft_strcmp(big, little));
		if (ft_strcmp(big, little) == 0)
			return (1);
		big++;
		i++;
	}
	return (0);
}
