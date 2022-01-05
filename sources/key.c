/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:12:17 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 16:49:34 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keypressed(int key, t_base *base)
{
	if (key == 53)
	{
		mlx_destroy_window(base->mlx, base->win);
		printf("Game Closed !\n");
		exit (0);
	}
	else
		keymove(base, key);
	startimg(*base);
	return (0);
}

int	checkexit(t_base base)
{
	if (checkcollec(&base) == 0)
	{
		base.game.steps++;
		printf("Steps : %d\n", base.game.steps);
		endgame(base);
	}
	if (checkcollec(&base) != 0)
		printf("Collect all babies !\n");
	return (0);
}

int	closed(t_base *base)
{
	mlx_destroy_window(base->mlx, base->win);
	printf("Game Closed !\n");
	exit (0);
}
