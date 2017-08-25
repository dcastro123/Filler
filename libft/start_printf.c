/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:34:59 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:07:18 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_args(t_args *ar)
{
	ar->space = 0;
	ar->minus = 0;
	ar->plus = 0;
	ar->zero = 0;
	ar->tag = 0;
	ar->precision = 0;
	ar->width = 0;
	ar->conv = 0;
	ar->tab = NULL;
	ar->num = 0;
	ar->unum = 0;
	ar->ulong = 0;
	ar->pflag = 0;
}

static	void	check_more_type(const char *format, t_args *ar, va_list *ap)
{
	if (format[ar->index] == 'o')
	{
		ar->conv = format[ar->index];
		ar->unum = va_arg(*ap, unsigned int);
		handle_oct(ar);
	}
	else if (format[ar->index] == 'x' || format[ar->index] == 'X')
	{
		ar->conv = format[ar->index];
		ar->unum = va_arg(*ap, unsigned int);
		handle_hex(ar);
	}
	else if (format[ar->index] == 'u')
	{
		ar->unum = va_arg(*ap, unsigned long);
		handle_usint(ar);
	}
	else if (format[ar->index] == 'd' || format[ar->index] == 'i')
	{
		ar->conv = format[ar->index];
		ar->num = va_arg(*ap, long);
		handle_int(ar);
	}
}

void			check_type(const char *format, t_args *ar, va_list *ap)
{
	check_more_type(format, ar, ap);
	if (format[ar->index] == 'c' || format[ar->index] == 'C')
	{
		ar->conv = format[ar->index];
		ar->num = va_arg(*ap, int);
		check_str(ar);
	}
	else if (format[ar->index] == 's' || format[ar->index] == 'S')
	{
		ar->conv = format[ar->index];
		ar->tab = ft_strdup(va_arg(*ap, char*));
		check_str(ar);
	}
	else if (format[ar->index] == 'p')
	{
		ar->ulong = va_arg(*ap, unsigned long);
		handle_ptr(ar);
	}
}

void			start_conversion(const char *format, t_args *ar, va_list *ap)
{
	ar->index++;
	init_args(ar);
	check_flags(format, ar, ap);
	check_type(format, ar, ap);
}
