/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:17:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:05:21 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*temp;
	int				i;

	temp = s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)temp[i] == c)
			return ((char*)&temp[i]);
		i--;
	}
	return (NULL);
}
