/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:33:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 13:58:06 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h
# include <string.h>
# include "..libs/libft/libft.h"
# include "..libs/gnl/get_next_line.h"


typedef struct pipe
{
	int		argc;
	int		indx_cmd;
	int		in_file;
	int		out_file;
	int		offset;
	int		lock_state;
	int		**pipe;
	char	error_str[128];
	char	**argv;
	char	**envp;
}	t_pipe;

/** Pipe opetator initialization and file handling **/
int		pipex(int argc, char **argv, char **envp);
int		pipe_init(int argc, char **argv, char **envp, t_pipe *pipex);
int		exec_cmd(t_pipe *pipex);
int		file_open(t_pipe *pipe);
int		file_close(t_pipe *pipex);
int		pipe_exit(t_pipe *pipex);

void	cmd_not_found(char *cmd, char **split_cmd, t_pipe *pipex);
void	dup42(int fd1, int fd2, char **cmd, t_pipe *pipex);

/** Error Handling **/
void	exec_perror(char **cmd, char *error, int code_no, t_pipe *pipex);
void	exit_perror(char *error, int code_no);

/** Reading and execution of strdin and out **/
void	free_split_str(char **str);
void	replace_all_str(char **cmd, char *old_w, char *new_w);
void	std_in_read(int *fd, char *limiter);
void	replace_all_str(char **str, char *old_w, char *new_w);

/** Bonus portion **/
int		file_open(char *argv, int i);
void	use(void);

#endif
