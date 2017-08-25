/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:00:43 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 17:49:25 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(intmax_t nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= 10 || nbr <= -10)
	{
		i++;
		nbr /= 10;
	}
	i++;
	return (i);
}

char		*ft_itoa(intmax_t n)
{
	char	*str;
	int		i;

	i = num_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (num_len(n) + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9 || n < -9)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
