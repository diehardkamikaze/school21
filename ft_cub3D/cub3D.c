/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:59:25 by mchau             #+#    #+#             */
/*   Updated: 2021/03/18 13:17:04 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3D.h"

void	exit_with_message(char *str, t_all *t)
{
	write(1, "Error\n", 6);
	if (t)
	{
		//end free structs and arrays into t
		free(t);
	}
	ft_putstr(str);
	exit(0);
}

int main(int argc, char **argv)
{
	int				i;
	int				fd;
	t_all 			*t;

	if (argc < 2)
		exit_with_message("Map file is missing\n", 0);
	i = 0;
	while (*(argv[1] + i) != 0)
		i++;
	if (i < 4 || argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'\
			|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
		exit_with_message("Invalid map format\n", 0);
	errno = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_with_message(strerror(errno), 0);
	t = map_parser(fd);
	/*/close(fd) into map_parser??! after reading? into parser?
	// HERE --save FLAG implementation!
	/if (argc < 3 && argv[2] == "--save")
	 do somethin 
*/	return (0);
}
