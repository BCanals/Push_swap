/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:40:43 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/18 16:25:24 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtrn;

	rtrn = malloc(sizeof(t_list));
	if (!rtrn)
		return (NULL);
	rtrn->content = content;
	rtrn->next = NULL;
	return (rtrn);
}
