/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:38 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/28 18:44:39 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	return (0);
}

void	free_structs(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->map_y)
		free(env->board.map[i]);
	free(env->board.map);
	i = -1;
	while (++i < env->p.x_size)
		free(env->p.piece[i]);
	free(env->p.piece);
	ft_bzero(env->board.map, sizeof(env->map_y));
	ft_bzero(env->p.piece, env->p.y_size);
	env->count = 0;
	env->i = 0;
}
