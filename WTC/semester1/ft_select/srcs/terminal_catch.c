/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_catch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:10:29 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:10:32 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*g_env;

void	terminal_catch(void)
{
	char	*tmp;

	if ((tmp = tgetstr("ti", 0)))
		ft_putstr_fd(tmp, g_env->fd);
	if ((tmp = tgetstr("vi", 0)))
		ft_putstr_fd(tmp, g_env->fd);
	if ((tmp = tgetstr("cl", 0)))
		ft_putstr_fd(tmp, g_env->fd);
	terminal_catch_mode();
}
