/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:21:57 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/19 16:21:58 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_LIST_H
# define ROOM_LIST_H

struct s_room;

typedef struct			s_room_list
{
	struct s_room		*room;
	struct s_room_list	*next;
}						t_room_list;

#endif
