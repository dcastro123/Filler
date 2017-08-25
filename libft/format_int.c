/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 20:56:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 17:48:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_prec(t_args *ar, char *tmp)
{
	int j;
	int i;
	int len;

	len = (int)ft_strlen(tmp);
	j = 0;
	i = -1;
	if (ar->precision == 0 && *tmp == '0')
		return ;
	else if (ar->precision > len)
	{
		ar->str_out = ft_memalloc(ar->precision);
		while (++i < (ar->precision - len))
			ar->str_out[i] = '0';
		while (i < ar->precision)
		{
			ar->str_out[i] = tmp[j];
			j++;
			i++;
		}
	}
	else
		ar->str_out = ft_strdup(tmp);
}

void	format_intljust(t_args *ar, char *tmp)
{
	int	i;
	int j;
	int len;

	i = 0;
	j = -1;
	len = (int)ft_strlen(ar->str_out);
	if (ar->plus == 1 && ar->num >= 0)
	{
		ft_putchar('+');
		i++;
	}
	while (ar->str_out[++j])
		ft_putchar(ar->str_out[j]);
	if (ar->width > 0)
	{
		if ((int)ft_strlen(tmp) > ar->width)
		{
			ar->ret += (int)ft_strlen(tmp);
			return ;
		}
		while (i++ < ar->width - len)
			ft_putchar(' ');
	}
	ar->ret += ft_strlen(ar->str_out) + i;
}

void	format_intpadding(t_args *ar, char *tmp)
{
	int i;
	int	len;

	i = -1;
	len = (int)ft_strlen(tmp);
	if (ar->num >= 0 && ar->plus == 1)
	{
		ft_putchar('+');
		ar->ret++;
		i++;
	}
	if (ar->width > 0)
	{
		while (++i < (ar->width - len))
		{
			ft_putchar('0');
			ar->ret++;
		}
	}
	ft_putstr(ar->str_out);
	ar->ret += ft_strlen(ar->str_out);
}

void	format_intwidth(t_args *ar, char *tmp)
{
	int	i;
	int len;

	i = -1;
	len = (int)ft_strlen(ar->str_out);
	if ((int)ft_strlen(tmp) > ar->width)
	{
		ar->ret += (int)ft_strlen(tmp);
		return ;
	}
	if (ar->space == 1 && ar->plus == 0 && ar->num >= 0)
	{
		ar->ret += write(1, " ", 1);
		ar->width--;
	}
	if (ar->plus == 1 && ar->num >= 0)
	{
		i++;
		ft_putchar('+');
	}
	if (ar->width > ar->precision)
		while (++i < ar->width - len)
			ft_putchar(' ');
	ar->ret += len + i;
}
