/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:35:54 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/22 16:22:26 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkwall(t_base *base)
{
	int		lines;
	int		c;

	lines = 0;
	c = 0;
	while (lines < base->map.size.y / 64)
	{
		if (lines == 0 || lines == base->map.size.y / 64 - 1)
		{
			c = 0;
			while (base->map.ptr[lines][c])
			{
				if ((base->map.ptr[lines][0 + 1] != '1'
					&& base->map.ptr[lines][c] != '\n')
					|| base->map.ptr[0][0] != '1')
					error("Top or Bottom wall invalid");
				c++;
			}
		}
		if (base->map.ptr[lines][0] != '1'
		|| base->map.ptr[lines][base->map.size.x / 64 - 1] != '1')
			error("Left or Right Wall invalid");
		lines++;
	}
	return (0);
}

int	content(t_base *base)
{
	int	lines;
	int	c;
	int	content;
	int	collec;

	collec = 0;
	content = 0;
	lines = 0;
	c = 0;
	while (lines < base->map.size.y / 64)
	{
		c = 0;
		while (base->map.ptr[lines][c])
		{
			if (base->map.ptr[lines][c] == 'E' || base->map.ptr[lines][c] == 'P')
				content++;
			if (base->map.ptr[lines][c] == 'C')
				collec++;
			c++;
		}
		lines++;
	}
	if (content != 2 || collec == 0)
		error("Missing or Too much characters");
	return (0);
}

int	checkallcontent(t_base *base)
{
	int	lines;
	int	c;

	lines = 0;
	while (lines < base->map.size.y / 64)
	{	
		c = 0;
		while (base->map.ptr[lines][c])
		{
			if (base->map.ptr[lines][c] == '\n')
				break ;
			if (base->map.ptr[lines][c] != '1'
			&& base->map.ptr[lines][c] != '0' && base->map.ptr[lines][c] != 'C'
			&& base->map.ptr[lines][c] != 'P' && base->map.ptr[lines][c] != 'E')
				error("Char unknown");
			c++;
		}
		lines++;
	}
	return (0);
}

int	check(t_base *base)
{
	checkwall(base);
	content(base);
	checkallcontent(base);
	return (0);
}

int	start(char **argv, t_base *base)
{
	int		fd;
	int		line;

	line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Error File");
	while (get_next_line(fd, &base->map.ptr[line]))
		line++;
	close (fd);
	return (0);
}
