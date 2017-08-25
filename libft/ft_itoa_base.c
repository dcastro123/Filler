/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:27:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 17:52:31 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int n, int base)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = (long)n;
	if (nbr < 0 && base == 10)
	{
		len++;
		nbr *= -1;
	}
	else if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*array;
	long	val;
	int		len;
	char	tab[16];

	val = (long)value;
	len = ft_intlen(val, base);
	ft_strcpy(tab, "0123456789abcdef");
	array = ft_memalloc(len);
	if (val == 0)
		return (array = ft_strdup("0"));
	if (val < 0 && (base == 10))
	{
		val *= -1;
		array[0] = '-';
	}
	else if (val < 0)
		val *= -1;
	while (val > 0)
	{
		array[len--] = tab[val % base];
		val /= base;
	}
	return (array);
}
