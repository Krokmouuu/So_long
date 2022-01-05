/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:45 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 16:47:26 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up(t_base *base)
{
	base->map.ptr[base->game.p_y][base->game.p_x] = '0';
	base->game.p_y -= 1;
	base->map.ptr[base->game.p_y][base->game.p_x] = 'P';
	base->game.steps++;
	printf("Steps : %d\n", base->game.steps);
	return (0);
}

int	move_left(t_base *base)
{
	base->map.ptr[base->game.p_y][base->game.p_x] = '0';
	base->game.p_x -= 1;
	base->map.ptr[base->game.p_y][base->game.p_x] = 'P';
	base->game.steps++;
	printf("Steps : %d\n", base->game.steps);
	return (0);
}

int	move_down(t_base *base)
{
	base->map.ptr[base->game.p_y][base->game.p_x] = '0';
	base->game.p_y += 1;
	base->map.ptr[base->game.p_y][base->game.p_x] = 'P';
	base->game.steps++;
	printf("Steps : %d\n", base->game.steps);
	return (0);
}

int	move_right(t_base *base)
{
	base->map.ptr[base->game.p_y][base->game.p_x] = '0';
	base->game.p_x += 1;
	base->map.ptr[base->game.p_y][base->game.p_x] = 'P';
	base->game.steps++;
	printf("Steps : %d\n", base->game.steps);
	return (0);
}

int	keymove(t_base *base, int key)
{
	if ((key == KEY_W)
		&& (base->map.ptr[base->game.p_y - 1][base->game.p_x] == 'E'))
		checkexit(*base);
	else if ((key == KEY_W)
		&& (base->map.ptr[base->game.p_y - 1][base->game.p_x] != '1'))
		move_up(base);
	if ((key == KEY_A)
		&& (base->map.ptr[base->game.p_y][base->game.p_x - 1] == 'E'))
		checkexit(*base);
	else if ((key == KEY_A)
		&& (base->map.ptr[base->game.p_y][base->game.p_x - 1] != '1'))
		move_left(base);
	if ((key == KEY_S)
		&& (base->map.ptr[base->game.p_y + 1][base->game.p_x] == 'E'))
		checkexit(*base);
	else if ((key == KEY_S)
		&& (base->map.ptr[base->game.p_y + 1][base->game.p_x] != '1'))
		move_down(base);
	if ((key == KEY_D)
		&& (base->map.ptr[base->game.p_y][base->game.p_x + 1] == 'E'))
		checkexit(*base);
	else if ((key == KEY_D)
		&& (base->map.ptr[base->game.p_y][base->game.p_x + 1] != '1'))
		move_right(base);
	return (0);
}
