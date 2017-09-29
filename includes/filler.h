/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:11:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/28 20:37:42 by dcastro-         ###   ########.fr       */
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

// # define OVERFLOW(i, y, x) i + y < 0 || x + j < 0 || i + y >= env->map_y || x + j >= env->map_x ? 1 : 0
# define LEFT 2
# define RIGHT 1
typedef	struct s_p
{
	int	x;
	int	y;
	int	x_size;
	int	y_size;
	char	**piece;
}				t_p;

typedef	struct s_board
{
	char		**map;
	int			map_posx;
	int			map_posy;
	int			xplace;
	int			yplace;
}				t_board;

typedef struct 	s_enemy
{
	int			x;
	int			y;
	int	min;
	int	max;
	int	x_max;
	int	y_max;

}				t_enemy;

typedef struct 	s_player
{
	int	x;
	int	y;
	int	min;
	int	max;
	int	x_max;
	int	y_max;

}				t_player;

typedef	struct s_env
{
	t_board		board;
	t_enemy		enemy;
	t_player	player;
	t_p 		p;
	char		p1;
	char		p2;
	int			map_x;
	int			map_y;
	int			overlap;
	int			heat;
	int			i;
	int			count;
	int			dist;
	int			start;
	int			dir;
}				t_env;

int		ft_error(char *s);
void	free_structs(t_env *env);
int		parse(t_env *env, char *line);
void	check_piece(t_env *e);
void	find_valid(t_env *env);
void	go_upleft(t_env *env);
void	go_downright(t_env *env);
#endif