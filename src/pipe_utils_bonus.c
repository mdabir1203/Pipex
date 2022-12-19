/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:36:07 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/19 03:42:30 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	display(void)
{
	ft_putendl_fd("\033[32mArguments are wrong Bro!!\n\e[0m", 2);
	ft_putendl_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putendl_fd("Ex: ./pipex \"here_doc\" <DELIMITER> <cmd> <cmd1> \
						 						<...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

/** Fnc to open the files with right flag **/
int	file_open(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}
