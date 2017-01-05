/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:39:11 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 11:45:24 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_envp(char **envp)
{
	if (envp == NULL)
		return (error(NOENV, NULL));
	if (*envp == NULL)
		return (error(NOENV, NULL));
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
}

int		count_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
