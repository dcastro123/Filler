/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:11:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/24 22:34:57 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct s_p
{
	int	x;
	int	y;
	int	width;
	int	height;
	char	**piece;
	
}				t_p;

typedef	struct s_board
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	t_p 	p;
	char	**map;
	
}				t_board;

typedef	struct s_env
{
	t_board	board;
	t_piece	piece;
	char	*p1_name;
	char	*p2_name;
	int		score;
	
}				t_env;