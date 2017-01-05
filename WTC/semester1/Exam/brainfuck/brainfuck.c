/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goisetsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 10:32:40 by goisetsi          #+#    #+#             */
/*   Updated: 2016/07/12 15:00:48 by goisetsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	char	bytes[2048];
	int		ptr;
	int		i;
	int		j;

	ptr = 2048;
	i = 0;
	if (ac == 2)
	{
		while (ptr >= 0)
		{
			bytes[ptr] = 0;
			ptr--;
		}
		ptr = 0;
		while (av[1][i])
		{
			if (av[1][i] == '>')
				ptr++;
			else if (av[1][i] == '<')
				ptr--;	
			else if (av[1][i] == '+')
				bytes[ptr]++;
			else if (av[1][i] == '-')
				bytes[ptr]--;
			else if (av[1][i] == '.')
				write(1, bytes + ptr, 1);
			else if (av[1][i] == '[')
			{
				if (bytes[ptr] == 0)
				{
					i++;
					j = 0;
					while (av[1][i])
					{
						if (av[1][i] == '[')
							j++;
						if (av[1][i] == ']' && j == 0)
							break ;
						if (av[1][i] == ']')
							j--;
						i++;
					}
				}
			}
			else if (av[1][i] == ']')
			{
				if(bytes[ptr] != 0)
				{
					j = 0;
					i--;
					while (av[1][i])
					{
						if (av[1][i] == ']')
							j++;
						if (av[1][i] == '[' && j == 0)
							break ;
						if (av[1][i] == '[')
							j--;
						i--;
					}
				}
			}
			i++;
		}
	}
	else
		write(1,"\n",1);
	return (0);
}
