/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:29:51 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 16:29:52 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error1(int err)
{
	if (err == 1)
		ft_putstr(E_MESS01);
	else if (err == 2)
		ft_putstr(E_MESS02);
	else if (err == 3)
		ft_putstr(E_MESS03);
	else
		return (0);
	return (1);
}

int	error(int err)
{
	if (0 <= err && err <= 9)
		return (error1(err));
	return (1);
}
