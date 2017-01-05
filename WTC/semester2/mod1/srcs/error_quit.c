/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:25:40 by jlangman          #+#    #+#             */
/*   Updated: 2016/10/27 11:25:52 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("An error occured: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
