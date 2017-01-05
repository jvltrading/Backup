/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:39:21 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 16:39:22 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*trim_start(char *str)
{
	int		k;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t')
		k++;
	if (k > 0)
	{
		str = ft_strcpy(str, &str[k]);
		str[ft_strlen(str) - k] = '\0';
	}
	return (str);
}

void	trim_end(char **str)
{
	int		k;

	if (*str == NULL)
		return ;
	k = ft_strlen(*str) - 1;
	while (k >= 0 && (*str[k] == ' ' || k == '\t'))
		k--;
	if (*str[k] && *str[k + 1] &&
			(*str[k + 1] == ' ' || *str[k + 1] == '\t'))
		*str[k + 1] = '\0';
}

void	trim_str(char **str)
{
	if (*str == NULL)
		return ;
	*str = trim_start(*str);
}

int		trim_arr(char ***arr)
{
	int		k;

	k = 0;
	while (arr[0][k] != NULL)
	{
		trim_str(&arr[0][k]);
		k++;
	}
	return (k);
}

void	rm_tabs(char **str)
{
	int		k;

	k = 0;
	while (str[0][k] != '\0')
	{
		if (str[0][k] == '\t')
			str[0][k] = ' ';
		k++;
	}
}
