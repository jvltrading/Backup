/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:10:42 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:10:43 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*g_env;

void	terminal_default(void)
{
	char	*tmp;

	if ((tmp = tgetstr("te", 0)))
		ft_putstr_fd(tmp, g_env->fd);
	if ((tmp = tgetstr("ve", 0)))
		ft_putstr_fd(tmp, g_env->fd);
	terminal_normal_mode();
}
