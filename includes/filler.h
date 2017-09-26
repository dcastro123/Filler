/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:11:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/25 23:43:50 by dcastro-         ###   ########.fr       */
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
	int	x_size;
	int	y_size;
	char	**piece;
}				t_p;

typedef	struct s_board
{
	char	**map;
	int		map_posx;
	int		map_posy;
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
	int		map_x;
	int		map_y;
	int		tot_score;
	int		open;
}				t_env;

void	check_player(t_env *env);
int	ft_error(char *s);
void	get_piece(t_env *env, char *line);
#endif