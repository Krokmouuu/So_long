/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:17 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 15:56:06 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	freegame(t_base *base)
{
	mlx_destroy_window(base->mlx, base->win);
	exit (0);
	return (0);
}

char	error(char *msg)
{
	printf("%s\n", msg);
	exit (0);
	return (0);
}

int	endgame(t_base base)
{
	printf("CONGRATS\n");
	freegame(&base);
	return (0);
}
