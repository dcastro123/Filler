/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/10/01 16:46:20 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	int	get_dist(t_env *env, int x, int y)
{
	int	i;
	int	k;
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
					if ((NEW(env->board.map[k][i])) == env->p2)
						return (dist);
				i++;
			}
			k++;
		}
	}
	return (MAX(env->map_x, env->map_y));
}

int			check_place(t_env *env, int x, int y, int valid)
{
	int	i;
	int	j;
	int	overlap;

	i = -1;
	overlap = 0;
	while (++i < env->p.y_size)
	{
		j = -1;
		while (++j < env->p.x_size)
		{
			if (env->p.piece[i][j] == '*' && INBOUNDS(i, j))
			{
				if (i + y < 0 || x + j < 0 || i + y >= env->map_y - 1 ||\
					x + j >= env->map_x - 1)
					return (0);
				else if ((NEW(env->board.map[y + i][j + x])) == env->p1)
					overlap += 1;
				else if ((NEW(env->board.map[y + i][j + x])) == env->p2)
					return (0);
			}
		}
	}
	return ((overlap == 1) ? get_dist(env, x, y) : 0);
}
