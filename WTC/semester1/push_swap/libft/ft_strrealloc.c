/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 12:11:32 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/15 12:01:39 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrealloc(char *ptr, size_t size)
{
	char	*str;

	if (!ptr || !size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * size + 1);
	ft_strncpy(str, ptr, size + 1);
	free(ptr);
	return (str);
}
