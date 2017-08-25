/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:58:28 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/17 15:54:11 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

# define IS_FLAG(x)		((x == 32 || x == 35 || x == 42 || x == 43) ? 1 : 0)
# define IS_NFLAG(x)	((x == 45 || x == 46 || (x > 47 && x < 58)) ? 1 : 0)
# define IS_MOD(x)		((x == 'h' || x == 'l' || x == 'j' || x == 'z') ? 1: 0)
# define IS_TRUE(x)		((x == 1) ? 1 : 0)

typedef	enum		e_mods
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
}					t_mods;

typedef	struct		s_args
{
	char			*str_out;
	char			conv;
	char			*tab;
	int				ret;
	int				index;
	int				space;
	int				plus;
	int				minus;
	int				tag;
	int				zero;
	int				num;
	int				pflag;
	unsigned long	unum;
	unsigned long	ulong;
	int				precision;
	int				width;
	t_mods			mods;
}					t_args;

int					ft_printf(const char *format, ...);
void				init_args(t_args *ar);
void				start_conversion(const char *format, t_args *ar,
					va_list *ap);

void				check_flags(const char *format, t_args *ar, va_list *ap);
void				get_precision(const char *format, t_args *ar, va_list *ap);
void				check_mod(const char *format, t_args *ar);
void				parse_asterisk(const char *format, t_args *ar, va_list *ap);
void				check_type(const char *format, t_args *ar, va_list *ap);

void				print_ljust(t_args *ar);
void				format_str(t_args *ar);
void				print_str(t_args *ar);
void				check_str(t_args *ar);
void				handle_char(t_args *ar);
void				handle_rstr(t_args *ar);

void				format_prec(t_args *ar, char *tmp);
void				format_intpadding(t_args *ar, char *tmp);
void				format_intwidth(t_args *ar, char *tmp);
void				format_intljust(t_args *ar, char *tmp);
void				handle_ptr(t_args *ar);
void				handle_int(t_args *ar);
void				handle_oct(t_args *ar);
void				handle_hex(t_args *ar);
void				handle_usint(t_args *ar);
#endif
