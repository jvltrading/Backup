/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:39:55 by jlangman          #+#    #+#             */
/*   Updated: 2016/05/31 10:36:49 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr_ld(long n)
{
	if (n == -9223372036854775807)
		ft_printf_str("-9223372036854775807");
	else if (n < 0)
	{
		n *= -1;
		ft_printf_char('-');
		ft_printf_nbr_ld(n);
	}
	else if (n >= 10)
	{
		ft_printf_nbr_ld(n / 10);
		ft_printf_nbr_ld(n % 10);
	}
	else
		return (ft_printf_char(48 + n));
	return (1);
}
