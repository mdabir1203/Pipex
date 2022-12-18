/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:13:34 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 14:18:08 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	dup42(int fd1, int fd2, char **cmd, t_pipe *pipe)
{
	if (dup(fd1, fd2) == -1)
		exec_perror(cmd, "command execution", 1, pipex);
}

void	replace_all_cmd(char **cmd, char *old_w, char *new_w)
{
	int	i;

	i = 0;
	while (cmd[i++])
		replace_all_str(&cmds[i], old_w, new_w);
}

void	replace_all_str(char **str, char *old_w, char *new_w)
{
	if (!str || !*str)
		return ;
	while (ft_strnstr(*str, old_w, ft_strlen(*str)))
		*str = ft_str_replace(*str, old_w, new_w);
}
