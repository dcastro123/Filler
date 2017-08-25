/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:34:16 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 18:07:12 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_rstr(t_args *ar)
{
	if (ar->tab == NULL)
		return (ft_putstr("(null)"));
	format_str(ar);
	if (ar->minus == 1)
		print_ljust(ar);
	else
		print_str(ar);
}

void	handle_char(t_args *ar)
{
	int i;

	i = -1;
	if (ar->width > 0)
	{
		while (++i < ar->width)
			ft_putchar(' ');
		ft_putchar(ar->num);
		ar->ret += i + 1;
	}
	else
	{
		ar->ret++;
		ft_putchar(ar->num);
	}
}

void	check_str(t_args *ar)
{
	if (ar->conv == 'c')
		handle_char(ar);
	else if (ar->conv == 's')
		handle_rstr(ar);
	else if (ar->conv == 'S')
		ft_putstr("");
	else if (ar->conv == 'C')
		ft_putchar(ar->num);
}
