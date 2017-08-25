/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacecheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:43:23 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:01:57 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_spacecheck(int c)
{
	unsigned char str;

	str = (unsigned char)c;
	if (str == ' ' || str == '\t' || str == '\r' || str == '\f' || str == '\n'
			|| str == '\v')
	{
		return (1);
	}
	return (0);
}
