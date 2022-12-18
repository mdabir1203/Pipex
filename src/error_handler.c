/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:33:58 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 14:04:29 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/** It simplifies error reporting in unified way by showing
 *  error code(errno-> external int var)  **/

void	exit_perror(char *error, int code_no)
{
	perror(error);
	exit(code_no);
}

void msg
/** Writes error msg on the basis of error code **/

void	cmd_not_found(char *cmd, char **split_cmd, t_pipe *pipex)
{
	ft_strlcpy(pipe->error_str, cmd, ft_strlen(cmd) + 1);
	if (split_cmd)
		free_split_str(split_cmd);
	pipe_exit(pipex);
	ft_putendl_fd(pipe->error_str, 2);
	ft_putendl_fd(":", 2);
	ft_putendl_fd("find the correct command bro!", 2);
	ft_putendl_fd("\n", 2);
	exit(127);
}
/**executes the perror function and returns the error code **/

void	exec_perror(char **cmd, char *error, int code_no, t_pipe *pipex)
{
	ft_strlcpy(pipe->error_str, error, ft_strlen(error) + 1);
	free_split_str(cmd);
	pipe_exit(pipex);
	exit_perror(pipe->error_str, code_no);
}
