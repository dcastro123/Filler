/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:31:21 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:00:47 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_args		ar;

	va_start(ap, format);
	ar.ret = 0;
	ar.index = 0;
	while (format[ar.index] != '\0')
	{
		if (format[ar.index] == '%' && format[ar.index + 1] != '%')
			start_conversion(format, &ar, &ap);
		else if (format[ar.index] == '%' && format[ar.index + 1] == '%')
		{
			ft_putchar('%');
			ar.ret++;
			ar.index++;
		}
		else
		{
			ft_putchar(format[ar.index]);
			ar.ret++;
		}
		ar.index++;
	}
	va_end(ap);
	return (ar.ret);
}
