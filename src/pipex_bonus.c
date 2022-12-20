/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:03:44 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/19 04:21:39 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/** Child process that is created  by fork and pipe, outputs are put
 *  inside a pipe and then closed with the exec fnc. Main process will 
 *  change the stdin for the pipe file descriptor. */
void	process_child(char *argv, char **envp)
{
	t_pipe	pipex;

	if (pipe(pipex.fd) == -1)
		error();
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		error();
	if (pipex.pid1 == 0)
	{
		close(pipex.fd[0]);
		dup2(pipex.fd[1], STDOUT_FILENO);
		exec(argv, envp);
	}
	else
	{
		close(pipex.fd[1]);
		dup2(pipex.fd[0], STDIN_FILENO);
		waitpid(pipex.pid1, NULL, 0);
	}
}

/** Function which makes a child process and reads from the stdin
 *  with get_next_line until reaching the delimiter word and puts
 *  the output inside a pipe. 
 *  like suppose cmd << delimiter. THis helps to avoid escape
 *  special characters in the text.
 *  Here I used fd[0] to read from the stdin. **/

void	heredoc(char *limiter, int argc)
{
	char	*line;
	t_pipe	pipex;

	if (argc < 6)
		use();
	if (pipe(pipex.fd) == -1)
		error();
	pipex.reader = fork();
	if (pipex.reader == 0)
	{
		close(pipex.fd[0]);
		while (get_next_line(pipex.fd[0]) != NULL)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipex.fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(pipex.fd[1]);
		dup2(pipex.fd[0], STDIN_FILENO);
		wait (NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipe	*pipex;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			pipex->out_file = file_open(argv[argc - 1], 0);
			heredoc(argv[2], argc);
		}
		else
		{
			i = 2;
			pipex->out_file = file_open(argv[argc - 1], 1);
			pipex->out_file = file_open(argv[1], 2);
			dup2(pipex->in_file, STDIN_FILENO);
		}
		while (i < argc -2)
			process_child(argv[i++], envp);
		dup2(pipex->out_file, STDOUT_FILENO);
		exec(argv[argc - 2], envp);
	}
	display();
}
