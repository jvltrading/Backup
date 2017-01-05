/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:30:26 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 16:30:28 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check(char **sa)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (sa[1][i] != '\0')
	{
		if (sa[1][i] == '/')
			count++;
		i++;
	}
	return (count);
}

void	ft_cd(t_env *env, char **sa)
{
	int		i;
	int		count;
	char	**args;

	i = 0;
	if (sa[1] == NULL)
	{
		cd_home(env);
		return ;
	}
	count = check(sa);
	args = ft_strsplit(sa[1], '/');
	i = 0;
	while (count > 0)
	{
		if (args[i] == NULL)
			return ;
		env = ft_cd_sub(env, args[i], count);
		count--;
		i++;
	}
}
