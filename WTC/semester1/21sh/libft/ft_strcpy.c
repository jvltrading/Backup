/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:09:48 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/07 12:09:54 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	cnt;

	cnt = 0;
	while (src[cnt] != '\0' && src[cnt] && dest[cnt] && dest[cnt] != '\0')
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	return (dest);
}
