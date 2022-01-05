/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:37:49 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/21 14:48:48 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	len(int fd)
{
	int		len;
	int		fuckgnl;
	char	buf[1];

	len = 0;
	fuckgnl = 1;
	buf[0] = '\0';
	while (fuckgnl == 1)
	{
		fuckgnl = read(fd, buf, 1);
		if (buf[0] != '\n')
			len++;
		if (buf[0] == '\n')
			fuckgnl = 2;
	}
	return (len);
}

int	lines(int fd, int x, int largeur)
{
	int		lines;
	int		fuckgnl;
	char	buf[1];
	int		i;

	i = 0;
	lines = 1;
	fuckgnl = 1;
	buf[0] = '\0';
	while (fuckgnl == 1)
	{
		fuckgnl = read(fd, buf, 1);
		if (fuckgnl != 1 && i != (x / largeur))
			error("Error");
		if (i == (x / largeur))
		{
			lines++;
			i = 0;
		}
		else
			i++;
	}
	return (lines);
}

int	scale(char **argv, t_base *base)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Problem File");
	base->map.size.x = (len(fd) * 64);
	base->map.size.y = (lines(fd, base->map.size.x, 64) * 64);
	close (fd);
	return (0);
}
