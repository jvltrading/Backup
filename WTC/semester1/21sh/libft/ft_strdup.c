/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:13:03 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 12:57:37 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	cnt;

	cnt = 0;
	cpy = (char *)ft_strnew(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[cnt])
	{
		cpy[cnt] = s1[cnt];
		cnt++;
	}
	if (cpy == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (cpy);
}
