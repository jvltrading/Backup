/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:17:02 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/21 11:01:58 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test_error(int i, char *error)
{
	if (i)
	{
		ft_putstr("Error: ");
		ft_putendl(error);
		exit(1);
	}
}

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	if (!(env->file = malloc(sizeof(*env->file))))
		error_quit("Failed to malloc env file cache");
	env->file[0] = NULL;
	env->rooms = NULL;
	env->start = NULL;
	env->end = NULL;
	env->ants = -1;
	bob(env);
	print_file(env);
	ft_putchar('\n');
	test_error(!env->start, "\033[1;37mNo start room\033[0;37m");
	test_error(!env->end, "\033[1;37mNo end room\033[0;37m");
	test_error(env->ants <= 0, "\033[1;32mInvalid number of Ants\033[1;37m");
	get_pounds(env, env->end, 0);
	test_error(env->start->pound == INT_MAX, "\033[1;32mNo path available");
	env->total_ants = env->ants;
	print_moves(env);
}
