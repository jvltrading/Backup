/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 10:40:29 by jlangman          #+#    #+#             */
/*   Updated: 2016/07/08 12:04:09 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>
# include <stdlib.h>

# define NBR_BUILTIN	6
# define PROMPT		"$> "
# define BUILTIN	"cd env setenv unsetenv exit echo"

# define NB_ERROR	8
# define AC		0
# define BADCMD		1
# define NSFOD		2
# define INVPTH		3
# define NOENV		4
# define BADVAL		5
# define FORK_FAIL	6
# define EXIT		7
# define RES_ERR	8

typedef void	(t_resolver)(char **, char **);
typedef struct dirent	*t_dirent;

typedef struct		s_builtin
{
	char		*name;
	t_resolver	*builtin;
}			t_builtin;

typedef struct	s_error
{
	int	exit;
	char	*err_str;
}		t_error;

void	assign_builtin(t_builtin *tmp);
void	get_cd(char **av, char **envp);
void	resolve_env(char **av, char **envp);
void	get_setenv(char **av, char **envp);
void	get_unsetenv(char **av, char **envp);
void	ft_exit(char **av, char **envp);
void	get_echo(char **av, char **envp);
char	*ft_getenv(char **envp, char *key);
char	**ft_setenv(char **envp, char *ket, char *val, int override);
void	free_split(char **arr);
int		count_split(char **arr);
int		check_envp(char **envp);
char	*find_path(char *name, char **envp);
int		error(int err_num, char *arg);
int		prompt(char **envp);
void	builtin(char **av, char **envp, t_builtin *tmp);

#endif
