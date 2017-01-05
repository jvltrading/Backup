/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:09:15 by jlangman          #+#    #+#             */
/*   Updated: 2016/12/05 11:09:27 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	error_quit(char *error_message)
{
	terminal_default();
	if (error_message)
	{
		ft_putstr_fd("\033[91mAn error occured: ", 2);
		ft_putendl_fd(error_message, 2);
		ft_putstr_fd("\033[0m", 2);
	}
	exit(-1);
}
