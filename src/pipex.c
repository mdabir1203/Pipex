/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:31:23 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/19 03:37:08 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/** Child process inside a fork that runs , takes the input file, puts the
 *  output inside a pipe and closes with the exec function */

void	process_child(char **argv, char **envp, int fd)
{
	t_pipe	piped;
	int		in_file;

	in_file = open(argv[1], O_RDONLY, 0777);
	if (in_file == -1)
		error();
	dup2(piped.fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(piped.fd[0]);
	exec(argv[2], envp);
}

/** Parent process takes data from the pipe and  changes the output 
 *  for the output.It closes with the exec function.
 *  If it is not done then it can lead to resource leaks /the fd remaining open 
 *  even after cmd is executed **/

void	process_parent(char **argv, char **envp, int *fd)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}

/** This fnc runs the child and parent process or displays an
 *  an error message if wrong arguments are passed **/

int	pipex(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc > 5)
	{
		ft_putendl_fd("Argument threshold exceeded!\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc == 5)
	{
		if (pipe(pipex.fd) == -1)
			error();
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			error();
		if (pipex.pid1 == 0)
			process_child(argv, envp, pipex.fd);
		waitpid(pipex.pid1, NULL, 0);
		process_parent(argv, envp, pipex.fd);
	}
	else
	{
		ft_putendl_fd("\033[32mArguments are wrong Bro!!\n\e[0m", 2);
		ft_putendl_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	}
	return (0);
}
