/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/30 22:58:33 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	get_start(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->board.map[y])
	{
		x = 0;
		while (env->board.map[y][x])
		{
			if (env->board.map[y][x] == env->p2)
			{
				env->enemy.x = x;
				env->enemy.y = y;
			}
			else if (env->board.map[y][x] == env->p1)
			{
				env->player.x = x;
				env->player.y = y;
			}
			x++;
		}
		y++;
	}
	env->start = 1;
	env->dir = env->enemy.y > env->player.y ? RIGHT : LEFT;
}

static	void	set_piece(t_env *env, int value)
{
	env->enemy_dist = value;
	env->board.xplace = env->board.map_posx;
	env->board.yplace = env->board.map_posy;
}

static	int		get_dist(t_env *env, int x, int y)
{
	int i;
	int k;
	int	dist;

	i = 0;
	k = 0;
	dist = 0;
	while (++dist)
	{
		k = y - dist;
		while (k <= y + dist)
		{
			i = x - dist;
			while (i <= x + dist)
			{
				if (k >= 0 && i >= 0 && i < env->map_x && k < env->map_y)
				{
					if (env->board.map[k][i] == env->p2)
						return (dist);
				}
				i++;
			}
			k++;
		}
	}
	return (MAX(env->map_x, env->map_y));
}

static	int		check_place(t_env *env, int x, int y, int valid)
{
	int	i;
	int	j;
	int	overlap;

	i = -1;
	overlap = 0;
	while (++i < env->p.y_size)
	{
		j = -2;
		while (++j < env->p.x_size)
		{
			if (env->p.piece[i][j] == '*' && INBOUNDS(i, j))
			{
				if (i + y < 0 || x + j < 0 || i + y >= env->map_y || x + j >= env->map_x)
					return (0);
				else if (env->board.map[y + i][j + x] == env->p1)
					overlap += 1;
				else if (env->board.map[y + i][j + x] == env->p2)
					return (0);
			}
		}
	}
	if (overlap == 1)
		return (get_dist(env, x, y));
	else
		return (0);
}

void	go_upleft(t_env *env)
{
	env->board.map_posy = env->map_y + env->p.y_size;
	int	value = 0;
	while (env->board.map_posy > -env->p.y_size)
	{
		env->board.map_posx = env->map_x + env->p.x_size;
		while (env->board.map_posx > -env->p.x_size)
		{
			if ((value = check_place(env, env->board.map_posx, env->board.map_posy, value)))
				if (value < env->enemy_dist)
					set_piece(env, value);
			env->board.map_posx--;
		}
		env->board.map_posy--;
	}
}

void		go_downright(t_env *env)
{
	int		value;

	value = 0;
	env->board.map_posy = -env->p.y_size;
	while (env->board.map_posy < env->map_y - 1)
	{
		env->board.map_posx = -env->p.x_size;
		while (env->board.map_posx < env->map_x - 1)
		{
			if ((value = check_place(env, env->board.map_posx, env->board.map_posy, value)))
				if (value < env->enemy_dist)
					set_piece(env, value);
			env->board.map_posx++;
		}
		env->board.map_posy++;
	}
}

void	check_piece(t_env *env)
{
	env->enemy.max = MAX(env->map_x, env->map_y);
	env->enemy_dist = env->enemy.max;
	env->board.xplace = 0;
	env->board.yplace = 0;
	if (env->start == 0)
		get_start(env);
	if (env->dir == RIGHT)
		go_downright(env);
	if (env->dir == LEFT)
		go_upleft(env);
	ft_printf("%d %d\n", env->board.yplace, env->board.xplace);
	free_structs(env);
}