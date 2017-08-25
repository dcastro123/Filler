/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:05 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 17:52:35 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	size_t	i;

	i = 0;
	list = begin_list;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
