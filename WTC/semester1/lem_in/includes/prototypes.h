/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:21:16 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 11:28:55 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"
# include "parser.h"

void	bob(t_env *env);
void	print_file(t_env *env);
int		get_room(t_env *env, t_parser *p, char **split);
int		get_link(t_env *env, t_parser *p, char **split);
void	error_quit(char *str);
void	get_pounds(t_env *env, t_room *room, int pound);
void	print_moves(t_env *env);
int		valid_int(char *line);
void	add_file_line(t_env *env, char *line);
t_room	*create_room(void);

#endif
