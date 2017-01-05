/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:30:47 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 16:30:48 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_echo(char **sa)
{
	size_t	cnt;

	cnt = 1;
	while (sa[cnt] != NULL)
	{
		ft_putstr(sa[cnt]);
		ft_putchar(' ');
		cnt++;
	}
	ft_putchar('\n');
}

void	ft_echo(char **sa)
{
	size_t	i;

	i = 1;
	while (sa[i] != NULL)
	{
		sa[i] = ft_replace_literal(sa[i]);
		i++;
	}
	ft_print_echo(sa);
}
