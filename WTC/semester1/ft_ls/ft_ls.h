/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:42:16 by jlangman          #+#    #+#             */
/*   Updated: 2016/06/10 10:44:34 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include <sys/types.h>

int		ft_list_dir(void);
int		ft_list_dir_a(void);

typedef struct		s_args
{
	char			*arg;
	char			*file;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

#endif
