/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:22:28 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 16:39:25 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid(int argc, char **argv)
{
	if (argc < 2)
		error("Missing <maps/...>");
	if (argc > 2)
		error("Too much parameters");
	if (!ft_strstr(argv[1], ".ber"))
		error("Missing .ber");
	return (0);
}

int	mallocmap(t_base *base)
{
	base->map.ptr = malloc((base->map.size.y + 1) * sizeof(char *));
	if (!base->map.ptr)
		error("Error Malloc Map");
	return (0);
}

int	main(int argc, char **argv)
{
	t_base	base;

	valid(argc, argv);
	scale(argv, &base);
	mallocmap(&base);
	start(argv, &base);
	check(&base);
	get_player(&base);
	base.game.steps = 0;
	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, base.map.size.x,
			base.map.size.y, "solong");
	checkcollec(&base);
	startimg(base);
	mlx_hook(base.win, 2, 1L << 0, keypressed, &base);
	mlx_hook(base.win, 17, 1L << 0, closed, &base);
	mlx_loop(base.mlx);
	return (0);
}
