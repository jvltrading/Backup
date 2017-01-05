/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:20:56 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/19 16:20:57 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "room_list.h"
# include "room.h"

typedef struct		s_env
{
	t_room_list		*rooms;
	t_room			*start;
	t_room			*end;
	char			**file;
	int				total_ants;
	int				ants;
}					t_env;

#endif
