/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:39:28 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 11:50:01 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**set(char **envp, char *tmp, char *val, int index)
{
	tmp = ft_strjoin(tmp, val);
	envp[index] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (envp);
}

char		**ft_setenv(char **envp, char *key, char *val, int override)
{
	int	i;
	char	*envp_key;
	char	*sep;
	char	*tmp;

	if (check_envp(envp) < 0)
		return (NULL);
	i = 0;
	tmp = ft_strjoin(key, "=");
	while (envp[i])
	{
		sep = ft_strchr(envp[i], '=');
		envp_key = ft_strsub(envp[i], 0, sep - envp[i]);
		if (!ft_strcmp(key, envp_key))
		{
			if (override)
				return (set(envp, tmp, val, i));
			return (NULL);
		}
		free(envp_key);
		i++;
	}
	envp[i] = ft_strjoin(tmp, val);
	envp[++i] = NULL;
	return (envp);
}

void		get_setenv(char **av, char **envp)
{
	if (av[1] && av[2])
		ft_setenv(envp, av[1], av[2], 1);
}
