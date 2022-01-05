/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:33:46 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/23 15:39:01 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"

# define UP_ARROW 126
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define ESC	53

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char		**ptr;
	t_coord		size;
}	t_map;

typedef struct s_img
{
	void	*images;
	void	*w;
	void	*floor;
	void	*exit;
	void	*collec;
	void	*pl;
	t_coord	pos;
}	t_img;

typedef struct s_game
{
	int		steps;
	int		collec;
	int		p_x;
	int		p_y;
}	t_game;

typedef struct s_base
{
	void	*mlx;
	void	*win;
	t_game	game;
	t_img	img;
	t_map	map;
}	t_base;

char	*ft_strjoin(char *str, char *buf);

int		valid(int argc, char **argv);
int		freegame(t_base *base);
char	error(char *msg);
int		endgame(t_base base);
char	*ft_strstr(char *haystack, char *needle);

int		mallocmap(t_base *base);
int		main(int argc, char **argv);

int		len(int fd);
int		lines(int fd, int x, int largeur);
int		scale(char **argv, t_base *base);

int		checkwall(t_base *base);
int		content(t_base *base);
int		checkallcontent(t_base *base);
int		check(t_base *base);
int		start(char **argv, t_base *base);

int		putwall(t_base base, int lines, int c);
int		putplayer(t_base base, int lines, int c);
int		putfloor(t_base base, int lines, int c);
int		putexit(t_base base, int lines, int c);
int		putcollec(t_base base, int lines, int c);

int		putimg2(t_base base, int lines, int c);
int		checkcollec(t_base *base);
int		startimg(t_base base);

int		keypressed(int key, t_base *base);
int		checkexit(t_base base);
int		closed(t_base *base);

int		move_up(t_base *base);
int		move_left(t_base *base);
int		move_down(t_base *base);
int		move_right(t_base *base);
int		keymove(t_base *base, int key);

int		get_player(t_base *base);

#endif