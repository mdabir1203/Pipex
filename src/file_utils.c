/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:20:12 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 13:29:04 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_close(t_pipe *pipex)
{
	close(pipe->in_file);
	close(pipe->out_file);
	return (0);
}

int	file_open(t_pipe *pipex)
{
	pipe->out_file = open(pipe->argv[pipe->argc - 1], \
					O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipe->out_file < 0)
		exit_perror(pipe->argv[pipe->argc - 1], 0);
	pipe->in_file = open(pipe->argv[1], O_RDONLY);
	if (pipe->in_file < 0)
	{
		ft_putendl_fd("Wrong input(0)\n", pipe->out_file);
		exit_perror(pipe->argv[1], 0);
	}
	return (0);
}
