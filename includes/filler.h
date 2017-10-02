/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:11:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/10/01 16:57:01 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define LEFT			2
# define RIGHT			1
# define XPIECE			env->p.x_size
# define YPIECE			env->p.y_size
# define POS_X 			env->board.map_posx
# define POS_Y 			env->board.map_posy
# define YMAP			env->map_y
# define XMAP			env->map_x
# define NEW(x)			ft_tolower(x)

# define MAX(x, y)	XMAP > YMAP ? XMAP : YMAP
# define INBOUNDS(i, j)	i >= 0 && j >= 0 && i < YPIECE && j < XPIECE ? 1 : 0

typedef	struct	s_p
{
	int			x;
	int			y;
	int			x_size;
	int			y_size;
	char		**piece;
}				t_p;

typedef	struct	s_board
{
	char		**map;
	int			map_posx;
	int			map_posy;
	int			xplace;
	int			yplace;
}				t_board;

typedef	struct	s_enemy
{
	int			x;
	int			y;
	int			min;
	int			max;
	int			x_max;
	int			y_max;

}				t_enemy;

typedef	struct	s_player
{
	int			x;
	int			y;
	int			min;
	int			max;
	int			x_max;
	int			y_max;

}				t_player;

typedef	struct	s_env
{
	t_board		board;
	t_enemy		enemy;
	t_player	player;
	t_p			p;
	char		p1;
	char		p2;
	int			map_x;
	int			map_y;
	int			overlap;
	int			piece_value;
	int			i;
	int			count;
	int			enemy_dist;
	int			start;
	int			dir;
	int			**heatmap;
}				t_env;

int				ft_error(char *s);
void			free_structs(t_env *env);
int				parse(t_env *env, char *line);
void			check_piece(t_env *e);
void			go_upleft(t_env *env);
void			go_downright(t_env *env);
int				check_place(t_env *env, int x, int y, int valid);
void			set_piece(t_env *env, int value);
#endif
