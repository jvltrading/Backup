/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 11:39:50 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/12 11:39:51 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**save_map(char **line, t_info *d)
{
	char	**map;
	char	**mapinfo;
	int		i;

	i = 0;
	mapinfo = ft_strsplit(*line, ' ');
	d->maprow = ft_atoi(mapinfo[1]);
	d->mapcol = ft_atoi(mapinfo[2]);
	ft_putstr_fd(ft_itoa(d->maprow), 2);
	ft_putstr_fd(ft_itoa(d->mapcol), 2);
	map = (char **)malloc(d->maprow * sizeof(char *));
	ft_putstr_fd("<<<<<<<<<<>>>>>>>>><<<<<<<<>>>>>>>>>\n", 2);
	free(*line);
	get_next_line(0, line);
	ft_putstr_fd(*line, 2);
	ft_putstr_fd("\n", 2);
	free(*line);
	freetab(mapinfo);
	while (i < d->maprow)
	{
		ft_putstr_fd(ft_itoa(i), 2);
		get_next_line(0, line);
		ft_putstr_fd(*line, 2);
		ft_putstr_fd("\n", 2);
		map[i] = ft_strdup(*line + 4);
		i++;
		free(*line);
	}
	i = -1;
	return (map);
}

char	**save_piece(char **line, t_info *d)
{
	char	**piece;
	char	**pieceinfo;
	int		i;

	i = 0;
	pieceinfo = ft_strsplit(*line, ' ');
	d->piecerow = ft_atoi(pieceinfo[1]);
	d->piececol = ft_atoi(pieceinfo[2]);
	piece = (char **)malloc(d->piecerow * sizeof(char *));
	while (i < d->piecerow)
	{
		get_next_line(0, line);
		piece[i] = strdup(*line);
		i++;
		free(*line);
	}
	i = -1;
	freetab(pieceinfo);
	return (piece);
}
