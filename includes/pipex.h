/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:33:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/20 02:30:50 by mabbas           ###   ########.fr       */
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

typedef struct s_pipe
{
	int		fd[2];
	pid_t	pid1;
	pid_t	reader;
	int		in_file;
	int		out_file;
}	t_pipe;

typedef struct s_mode
{
	int		mode;
	char	*name;
}	t_filemode;

t_filemode	g_file_mode[] = {{O_WRONLY | O_CREAT | O_APPEND, "append"}, \
	{O_WRONLY | O_CREAT | O_TRUNC, "truncate"}, \
	{O_RDONLY, "read"}};

/** Pipe opetator initialization and file handling **/
void	error(void);
char	*path_find(char *cmd, char **envp);
void	exec(char *argv, char **envp);

int		file_open(char *argv, int i);
void	display(void);

#endif
