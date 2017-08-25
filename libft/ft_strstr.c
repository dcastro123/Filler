/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:21:45 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:05:29 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *little_temp;
	char *big_temp;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		little_temp = (char *)little;
		big_temp = (char *)big;
		while (*big && *little_temp && *big == *little_temp)
		{
			big++;
			little_temp++;
		}
		if (!*little_temp)
			return (big_temp);
		big = big_temp + 1;
	}
	return (NULL);
}
