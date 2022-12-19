/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:33:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/19 02:02:36 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"

typedef struct pipe
{
	int		fd[2];
	pid_t	pid1;
}	t_pipe;

/** Pipe opetator initialization and file handling **/
void	error(void);
char	*path_find(char *cmd, char **envp);
void	exec(char *argv, char **envp);

int		file_open(const char *argv, int i);
void	use(void);

#endif
