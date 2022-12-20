/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:13:34 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/20 02:34:09 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i++])
		free(ptr[i]);
	free(ptr);
}

/**Function to look into the path line inside the environment variable
 * Each command path is splitted and tested and then returns the correct value.
**/
char	*path_find(char *cmd, char **envp)
{
	char	**path_var;
	char	*path;
	int		i;
	char	*partial_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_var = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_var[i])
	{
		partial_path = ft_strjoin(path_var[i], "/");
		path = ft_strjoin(*path_var, cmd);
		free(partial_path);
		if (get_access(path, 0) == 0)
			return (path);
		free (path);
		i++;
	}
	free_ptr(path_var);
}

void	error(void)
{
	perror("\033[32mError");
	exit(EXIT_FAILURE);
}

/**Function to take the cmd and send to find_path before executing.
 * Here using the execve which transforms the calling process
 * to a new process.If execve return to calling process then
 * error will occur and return value is -1.   **/
void	exec(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = path_find(cmd[0], envp);
	if (!path)
	{
		free_ptr(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
