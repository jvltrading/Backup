/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:04:54 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 11:04:55 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, display);
}

t_all	*ft_check(t_all *all, int i)
{
	static t_all	*tmp;

	tmp = NULL;
	if (i == 0)
		tmp = all;
	return (tmp);
}
