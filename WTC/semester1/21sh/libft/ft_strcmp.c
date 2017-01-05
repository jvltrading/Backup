/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:06:58 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 12:07:07 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_diff(char s1, char s2)
{
	int	l;
	int	m;

	if (s1 < 0)
		m = 256 + s1;
	else
		m = s1;
	if (s2 < 0)
		l = 256 + s2;
	else
		l = s2;
	return (m - l);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int	k;

	k = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && !(s2 == NULL))
			return (s2[0]);
		else if (!(s1 == NULL) && s2 == NULL)
			return (s1[0]);
		return (0);
	}
	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (s1[k] != s2[k])
			return (ft_diff(s1[k], s2[k]));
		k++;
	}
	if (s1[k] != '\0')
		return (ft_diff(s1[k], 0));
	else if (s2[k] != '\0')
		return (ft_diff(0, s2[k]));
	return (0);
}
