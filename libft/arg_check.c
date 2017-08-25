/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:29:23 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 17:44:57 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_asterisk(const char *format, t_args *ar, va_list *ap)
{
	int val;

	if (format[ar->index - 1] == '.')
	{
		val = va_arg(*ap, int);
		ar->precision = val;
	}
	else if (format[ar->index + 1] == '.')
	{
		val = va_arg(*ap, int);
		ar->width = val;
	}
	else
	{
		val = va_arg(*ap, int);
		ar->width = val;
	}
}

void	get_precision(const char *format, t_args *ar, va_list *ap)
{
	if (format[ar->index + 1] == '*')
	{
		ar->precision = va_arg(*ap, int);
		ar->index += 2;
	}
	else if (format[ar->index + 1] >= '0' && format[ar->index + 1] <= '9')
	{
		ar->precision = ft_atoi(format + (ar->index + 1));
		ar->index++;
	}
	else
		ar->precision = 0;
}

void	check_mod(const char *format, t_args *ar)
{
	if (format[ar->index] == 'h' && format[ar->index + 1] != 'h')
		ar->mods = h;
	else if (format[ar->index] == 'h' && format[ar->index + 1] == 'h')
		ar->mods = hh;
	else if (format[ar->index] == 'l' && format[ar->index + 1] != 'l')
		ar->mods = l;
	else if (format[ar->index] == 'l' && format[ar->index + 1] == 'l')
		ar->mods = ll;
	else if (format[ar->index] == 'z')
		ar->mods = z;
	else if (format[ar->index] == 'j')
		ar->mods = j;
}

void	more_parsing(const char *format, t_args *ar)
{
	if (IS_MOD(format[ar->index]))
		check_mod(format, ar);
	if (format[ar->index] == ' ')
		ar->space = 1;
	if (format[ar->index] == '-')
		ar->minus = 1;
	if (format[ar->index] == '+')
		ar->plus = 1;
	if (format[ar->index] == '#')
		ar->tag = 1;
	if (format[ar->index] == '0' && format[ar->index - 1] != '.')
		ar->zero = 1;
}

void	check_flags(const char *format, t_args *ar, va_list *ap)
{
	ar->mods = 0;
	while (IS_FLAG(format[ar->index]) || IS_NFLAG(format[ar->index])
		|| IS_MOD(format[ar->index]))
	{
		more_parsing(format, ar);
		if (format[ar->index] == '.')
		{
			ar->pflag = 1;
			get_precision(format, ar, ap);
			while (ar->index >= '0' && ar->index <= '9')
				ar->index++;
		}
		if (format[ar->index] == '*')
			break ;
		else if (format[ar->index] >= '1' && format[ar->index] <= '9'
				&& ar->pflag == 0)
		{
			ar->width = ft_atoi(format + ar->index);
			while (format[ar->index] >= '0' && format[ar->index] <= '9')
				ar->index++;
		}
		else
			ar->index++;
	}
}
