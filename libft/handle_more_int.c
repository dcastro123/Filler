/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_more_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:08:13 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:07:07 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_upperhex(t_args *ar, char *tmp)
{
	if (ar->tag == 1)
	{
		ft_putstr("0X");
		ft_putstr(tmp);
	}
	else
		ft_putstr(tmp);
}

void		handle_oct(t_args *ar)
{
	char *tmp;

	if (ar->mods == none)
	{
		tmp = ft_uitoa_base(ar->unum, 8);
		if (ar->tag == 1 && ar->unum > 0)
		{
			ft_putstr("0");
			ft_putstr(tmp);
		}
		else
			ft_putstr(tmp);
	}
}

void		handle_hex(t_args *ar)
{
	char *tmp;

	if (ar->mods == none && ar->conv == 'x')
	{
		tmp = ft_uitoa_base(ar->unum, 16);
		if (ar->tag == 1)
		{
			ft_putstr("0x");
			ft_putstr(tmp);
		}
		else
			ft_putstr(tmp);
	}
	else if (ar->mods == none && ar->conv == 'X')
	{
		tmp = ft_uitoa_capbase(ar->unum, 16);
		handle_upperhex(ar, tmp);
	}
}

void		handle_ptr(t_args *ar)
{
	char *tmp;

	tmp = ft_ultoa_base(ar->ulong, 16);
	ft_putstr("0x");
	ft_putstr(tmp);
}
