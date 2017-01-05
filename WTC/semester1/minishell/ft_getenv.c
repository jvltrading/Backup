/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:39:05 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 10:39:07 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **envp, char *key)
{
	int	index;
	int	i;

	check_envp(envp);
	index = 0;
	while (envp[index])
	{
		i = 0;
		while (envp[i] && key[i] == envp[index][i])
			i++;
		if (envp[index][i] == '=')
			return (&envp[index][i + 1]);
		index++;
	}
	return (NULL);
}
