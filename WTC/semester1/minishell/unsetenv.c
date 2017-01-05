/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:39:32 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 11:50:55 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset(int i, char **envp, char *envp_key)
{
	ft_strdel(&envp[i]);
	while (envp[i + 1])
	{
		envp[i] = envp[i + 1];
		i++;
	}
	ft_strdel(&envp_key);
	envp[i] = NULL;
	return (1);
}

static int	ft_unsetenv(char **envp, char *key)
{
	int	i;
	char	*envp_key;
	char	*sep;

	if (check_envp(envp) < 0)
		return (-1);
	i = 0;
	while (envp[i])
	{
		sep = ft_strchr(envp[i], '=');
		envp_key = ft_strsub(envp[i], 0, sep - envp[i]);
		if (!ft_strcmp(key, envp_key))
			return (unset(i, envp, envp_key));
		free(envp_key);
		i++;
	}
	return (0);
}

void		get_unsetenv(char **av, char **envp)
{
	if (av[1])
		ft_unsetenv(envp, av[1]);
}
