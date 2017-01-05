/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:29:40 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:29:52 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static void		place_mount(t_env *env, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '(')
			error_quit("Invalid file line 1");
		i++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] != ',')
			error_quit("Invalid file line 2");
		i++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] != ',')
			error_quit("Invalid file line 3");
		i++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] != ')')
			error_quit("Invalid file line 4");
		i++;
		if (line[i] == ' ')
			i++;
	}
	map_place_mount_line(env, line);
}

void			map_parse(t_env *env, char *file)
{
	char	*line;
	int		fd;
	int		rd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open file");
	while ((rd = get_next_line(fd, &line)) == 1)
	{
		place_mount(env, line);
		free(line);
	}
	if (rd == -1)
		error_quit("Error while get_next_line");
	close(fd);
}
