/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:34:33 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:07:03 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*check_imod(t_args *ar)
{
	char *tmp;

	tmp = NULL;
	if (ar->mods == none)
		tmp = ft_itoa((int)ar->num);
	else if (ar->mods == l)
		tmp = ft_itoa((long)ar->num);
	else if (ar->mods == ll)
		tmp = ft_itoa((long long)ar->num);
	else if (ar->mods == h)
		tmp = ft_itoa((short)ar->num);
	else if (ar->mods == hh)
		tmp = ft_itoa((char)ar->num);
	else if (ar->mods == z)
		tmp = ft_itoa((size_t)ar->num);
	else if (ar->mods == j)
		tmp = ft_itoa((intmax_t)ar->num);
	else
		tmp = ft_itoa((int)ar->num);
	return (tmp);
}

static	char	*check_umod(t_args *ar)
{
	char *tmp;

	tmp = NULL;
	if (ar->mods == none)
		tmp = ft_uitoa((unsigned int)ar->unum);
	else if (ar->mods == l)
		tmp = ft_uitoa((unsigned long)ar->unum);
	else if (ar->mods == ll)
		tmp = ft_uitoa((unsigned long long)ar->unum);
	else if (ar->mods == h)
		tmp = ft_uitoa((unsigned short)ar->unum);
	else if (ar->mods == hh)
		tmp = ft_uitoa((unsigned char)ar->unum);
	else if (ar->mods == z)
		tmp = ft_uitoa((size_t)ar->unum);
	else if (ar->mods == j)
		tmp = ft_uitoa((uintmax_t)ar->unum);
	else
		tmp = ft_uitoa((unsigned int)ar->unum);
	return (tmp);
}

void			handle_int(t_args *ar)
{
	char *tmp;

	tmp = check_imod(ar);
	format_prec(ar, tmp);
	if (ar->zero == 1 && ar->minus == 0 && ar->pflag == 0)
		format_intpadding(ar, tmp);
	else if (ar->minus == 1)
		format_intljust(ar, tmp);
	else if (ar->width > 0)
	{
		format_intwidth(ar, tmp);
		ft_putstr(ar->str_out);
	}
	else
	{
		if (ar->space == 1 && ar->num >= 0)
			ar->ret += write(1, " ", 1);
		if (ar->plus == 1 && ar->num >= 0)
			ar->ret += write(1, "+", 1);
		ft_putstr(tmp);
	}
}

void			handle_usint(t_args *ar)
{
	char *tmp;

	tmp = check_umod(ar);
	format_prec(ar, tmp);
	if (ar->zero == 1 && ar->minus == 0 && ar->pflag == 0)
		format_intpadding(ar, tmp);
	else if (ar->minus == 1)
		format_intljust(ar, tmp);
	else if (ar->width > 0)
	{
		format_intwidth(ar, tmp);
		ft_putstr(ar->str_out);
	}
	else
		ft_putstr(tmp);
}
