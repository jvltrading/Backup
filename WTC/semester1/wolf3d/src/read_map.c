/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:52 by jlangman          #+#    #+#             */
/*   Updated: 2016/11/21 10:56:12 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		read_size(t_env *te, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 0)
		exit(EXIT_FAILURE);
	size = ft_strsplittoint(line, ' ');
	te->map.x_size = size[0];
	te->map.y_size = size[1];
}

static void		read_map(t_env *te, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * te->r.x_pos_map);
	if (worldmap == 0)
		exit(1);
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	te->map.map = worldmap;
}

void			check_file(t_env *te, char **argv)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	read_map(te, fd);
	read_size(te, fd);
	close(fd);
}
