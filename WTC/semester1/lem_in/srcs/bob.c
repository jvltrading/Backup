/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:18:13 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 10:59:20 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_room(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(p->line, ' ')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && splitted[2] && !splitted[3])
		return (get_room(env, p, splitted));
	else if (splitted[0] && splitted[1])
		return (0);
	return (-1);
}

static int	check_link(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(p->line, '-')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && !splitted[2])
		return (get_link(env, p, splitted));
	else if (splitted[0] && splitted[1])
		return (0);
	return (-1);
}

static int	check_start_end(t_env *env, t_parser *p)
{
	if (!ft_strcmp(p->line, "##start"))
	{
		if (p->is_start || p->is_end || env->start)
			return (0);
		p->is_start = 1;
	}
	else if (!ft_strcmp(p->line, "##end"))
	{
		if (p->is_start || p->is_end || env->end)
			return (0);
		p->is_end = 1;
	}
	return (1);
}

static int	get_line(t_env *env, t_parser *p)
{
	int	check_reader;
	int	check_line;

	if (p->line[0] == '\0')
		return (0);
	if (p->line[0] == '#' && p->line[1] == '#')
	{
		if (!check_start_end(env, p))
			return (0);
	}
	else
	{
		if (!(check_reader = check_room(env, p)))
			return (0);
		else if (!(check_line = check_link(env, p)))
			return (0);
		if (check_reader == -1 && check_line == -1)
			return (0);
	}
	return (1);
}

void		bob(t_env *env)
{
	t_parser	p;
	int			rd;

	p.is_start = 0;
	p.is_end = 0;
	p.link_part = 0;
	while ((rd = get_next_line(0, &(p.line))) == 1)
	{
		if (p.line[0] != '#' || (p.line[1] && p.line[1] == '#'))
		{
			if (env->ants == -1)
			{
				if (valid_int(p.line))
					env->ants = ft_atoi(p.line);
				else
					return ;
			}
			else if (!get_line(env, &p))
				return ;
		}
		add_file_line(env, p.line);
	}
	if (rd == -1)
		error_quit("\033[1;37mError while reading standard input\033[0;37m");
}
