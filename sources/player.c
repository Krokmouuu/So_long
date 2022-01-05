/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:40:09 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 15:50:41 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_player(t_base *base)
{
	int	lines;
	int	c;

	lines = 0;
	while (lines < base->map.size.y / 64)
	{
		c = 0;
		while (c <= base->map.size.x / 64)
		{
			if (base->map.ptr[lines][c + 1] == '\n')
				break ;
			if (base->map.ptr[lines][c] == 'P')
			{
				base->game.p_x = c;
				base->game.p_y = lines;
			}
			c++;
		}
		lines++;
	}
	return (0);
}
