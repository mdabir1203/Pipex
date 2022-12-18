/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:33:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 03:09:02 by mabbas           ###   ########.fr       */
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

/** Mandatory portion **/
void	error_chk(void);
char	*path_finder(char *cmd, char **envp);
void	execution(char *argv, char **envp);

/** Bonus portion **/
int		file_open(char *argv, int i);
void	use(void);

#endif
