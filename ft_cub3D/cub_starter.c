/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:59:25 by mchau             #+#    #+#             */
/*   Updated: 2021/03/20 09:58:12 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3D.h"

void	free_wrapper(t_all *t)
{
	int i;

	if (t)
	{
		if (t->plr)
			free(t->plr);
		if (t->maze)
			free(t->maze);
		if (t->spr)
			free(t->spr);
		if (t->map)
		{
			i = 0;
			while (t->map[i])
				free(t->map[i++]);
		}
		free(t);
	}
}

void	exit_with_message(char *str, t_all *t)
{
	write(1, "Error\n", 6);
	free_wrapper(t);
	ft_putstr(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	int				i;
	int				fd;
	t_all			*t;

	if (argc < 2)
		exit_with_message("Map file is missing\n", 0);
	i = 0;
	while (*(argv[1] + i) != 0)
		i++;
	if (i < 4 || IS_NOT_TRUE_FORMAT(i - 1))
		exit_with_message("Invalid map format\n", 0);
	errno = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_with_message(strerror(errno), 0);
	t = map_file_parser(fd);
	close(fd);
	if (argc >= 3 && ft_strncmp(argv[2], "--save", 6) == 0)
	{
		printf("Here implementation of --save flag");
	}
	//go_game_logic()!!!;
	void *mlx = 0;
	void *win = 0;

	int x = -1;
	int y;
	int g;
	int g2;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 250, 200, "MCHAAAAAAAAAAAAAAAAAAAAAAAAAau");

	while (t->map[++x] && (y = -1))
		while (t->map[x][++y])
			if (t->map[x][y] == '1' && (g = -1))
				while (++g < 20 && (g2 = -1))
					while(++g2 < 20)
						mlx_pixel_put(mlx, win, y*20 + g, x*20 + g2, 0xFFFFFF);

	mlx_loop(mlx);
	//game logic
	//эта функция уже никогда не завершиться,
	//так что чисти все при --save и escape/[x]
	return (0);
}