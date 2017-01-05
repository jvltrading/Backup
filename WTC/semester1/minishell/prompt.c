/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:39:22 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 11:44:48 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_dir(char *path, char *name)
{
	DIR			*dir;
	t_dirent	dirent;

	dir = opendir(path);
	while ((dirent = readdir(dir)))
	{
		if (!ft_strcmp(name, dirent->d_name))
		{
			path = ft_strjoin(path, "/");
			*path = ft_strrealloc(path, ft_strlen(path) + ft_strlen(name));
			ft_strcat(path, name);
			closedir(dir);
			return (path);
		}
	}
	closedir(dir);
	return (NULL);
}

char		*find_path(char *name, char **envp)
{
	char	*path;
	char	**path_list;
	int		i;

	if (name[0] == '/' || (name[0] == '.' && name[1] && name[1] == '/'))
		return (name);
	path_list = ft_strsplit(ft_getenv(envp, "PATH"), ':');
	i = 0;
	path = NULL;
	while (path_list[i])
	{
		if ((path = search_dir(path_list[i], name)))
			break;
		i++;
	}
	free_split(path_list);
	return (path);
}

static void	fork_handler(char **av, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(find_path(av[0], envp), av, envp);
		error(BADCMD, av[0]);
		free_split(av);
		error(EXIT, NULL);
	}
	else if (pid < 0 || waitpid(pid, NULL, 0) != pid)
	{
		free_split(av);
		error(FORK_FAIL, NULL);
	}
	free_split(av);
}

static void	execute(char *command, char **envp, t_builtin *tmp)
{
	char	**av;
	int		i;

	i = 0;
	while (command[i] == ' ' || command[i] == '\t')
		i++;
	if (command[i])
	{
		av = ft_strsplit(&command[i], ' ');
		ft_strdel(&command);
		if (!ft_strstr(BUILTIN, av[0]))
			fork_handler(av, envp);
		else
			builtin(av, envp, tmp);
	}
}

int			prompt(char **envp)
{
	char		*line;
	t_builtin	tmp[NBR_BUILTIN];

	assign_builtin(tmp);
	ft_putstr(PROMPT);
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (line && *line)
			execute(line, envp, tmp);
		ft_putstr(PROMPT);
	}
	return (1);
}
