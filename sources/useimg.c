/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:14:52 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/04 13:46:31 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	putimg2(t_base base, int lines, int c)
{
	base.game.collec = 0;
	if (base.map.ptr[lines][c] == '1')
		base.img.images = mlx_xpm_file_to_image(base.mlx, "./img/tree.xpm",
				&base.img.pos.x, &base.img.pos.y);
	else if (base.map.ptr[lines][c] == '0')
		base.img.images = mlx_xpm_file_to_image(base.mlx, "./img/floor.xpm",
				&base.img.pos.x, &base.img.pos.y);
	else if (base.map.ptr[lines][c] == 'E')
		base.img.images = mlx_xpm_file_to_image(base.mlx, "./img/exit.xpm",
				&base.img.pos.x, &base.img.pos.y);
	else if (base.map.ptr[lines][c] == 'C')
		base.img.images = mlx_xpm_file_to_image(base.mlx,
				"./img/collectible.xpm",
				&base.img.pos.x, &base.img.pos.y);
	else if (base.map.ptr[lines][c] == 'P')
		base.img.images = mlx_xpm_file_to_image(base.mlx, "./img/player-1.xpm",
				&base.img.pos.x, &base.img.pos.y);
	mlx_put_image_to_window(base.mlx, base.win, base.img.images, 64 * c,
		64 * lines);
	mlx_destroy_image(base.mlx, base.img.images);
	return (0);
}

int	checkcollec(t_base *base)
{
	int		lines;
	int		c;

	lines = 0;
	base->game.collec = 0;
	while (lines < base->map.size.y / 64)
	{
		c = 0;
		while (base->map.ptr[lines][c])
		{
			if (base->map.ptr[lines][c] == 'C')
				base->game.collec++;
			c++;
		}
		lines++;
	}
	return (base->game.collec);
}

int	startimg(t_base base)
{
	int		lines;
	int		c;

	lines = 0;
	while (lines < base.map.size.y / 64)
	{
		c = 0;
		while (c < base.map.size.x / 64)
		{
			putimg2(base, lines, c);
			c++;
		}
		lines++;
	}
	return (0);
}
