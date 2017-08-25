/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_capbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:58:24 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:06:43 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(int n, int base)
{
	unsigned int	len;
	unsigned int	nbr;

	len = 0;
	nbr = (unsigned int)n;
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

char				*ft_uitoa_capbase(int value, int base)
{
	char			*array;
	unsigned int	val;
	unsigned int	len;
	char			tab[16];

	val = (unsigned int)value;
	len = ft_intlen(val, base);
	ft_strcpy(tab, "0123456789ABCDEF");
	if (!(array = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	array[len--] = '\0';
	if (val == 0)
	{
		array[0] = '0';
		return (array);
	}
	while (val > 0)
	{
		array[len] = tab[val % base];
		val /= base;
		len--;
	}
	return (array);
}
