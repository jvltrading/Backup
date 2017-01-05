/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tty_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:01:09 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:02:03 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_tty_fd(t_env *env)
{
	char	*tmp;

	if (isatty(1))
	{
		env->fd = 1;
		return ;
	}
	if (!(tmp = ttyname(0)))
	{
		ft_putendl_fd("ft_select: can't get name", 2);
		exit(EXIT_FAILURE);
	}
	if ((env->fd = open(tmp, O_WRONLY)) == -1)
	{
		ft_putendl_fd("ft_select: can't open", 2);
		exit(EXIT_FAILURE);
	}
}
