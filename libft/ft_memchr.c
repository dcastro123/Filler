/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:40:26 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:00:19 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*temp;

	temp = (unsigned const char *)s;
	while (n > 0)
	{
		if (*temp != (unsigned char)c)
			temp++;
		else
			return ((void*)temp);
		n--;
	}
	return (NULL);
}
