/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:11:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/23 02:36:17 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/ft_printf.h"
#include "../libft/libft.h"
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
	t_p 	p;
	char	**map;
	int		map_x;
	int		map_y;
}				t_board;

typedef struct 	s_enemy
{
	int	x;
	int	y;
	int	score;
}				t_enemy;

typedef struct 	s_player
{
	int	x;
	int	y;
	int	score;

}				t_player;

typedef	struct s_env
{
	t_board		board;
	t_enemy		enemy;
	t_player	player;
	t_p 	p;
	char	p1;
	char	p2;
	int		map_h;
	int		map_w;
	int		tot_score;
	int		open;
}				t_env;
#endif