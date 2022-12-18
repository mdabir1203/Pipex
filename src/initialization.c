/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:05:15 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:08 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipe_init(int argc, char **argv, char **envp, t_pipe *pipex)
{
	pipe->argc;
	pipe->argv;
	pipe->envp;
	pipe->indx_cmd = argc - 3;
	pipe->offset = 2;
	pipe->lock_state = 0;
	file_open(pipex);
	return (0);
}