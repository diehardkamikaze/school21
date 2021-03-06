/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:00:54 by mchau             #+#    #+#             */
/*   Updated: 2021/04/29 14:45:31 by mchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	FILE	*map;
	char	c;
	char	buf;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	errno = 0;
	map = fopen(argv[1], "r");
	if (!map)
		strerror(errno);
	fscanf(map, "/\n%c", &buf);
	while(fread(&c, 1, 1, map))
		printf("%c", c);
	if(!fclose(map))
		strerror(errno);
	printf("\n%c\n", buf);
	return (0);
}
