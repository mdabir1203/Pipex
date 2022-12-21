/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:36:07 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/21 04:17:57 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "..includes/mode.h"

void	display(void)
{
	ft_putendl_fd("\033[32mArguments are wrong Bro!!\n\e[0m", 2);
	ft_putendl_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putendl_fd("Ex: ./pipex \"here_doc\" <DELIMITER> <cmd> <cmd1> \
						 						<...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

/** Fnc to open the files with right flag 
 *  Here I had an array f structs containing all the necessary info
 *  for each file opening mode. Also added descriptinve name for the
 *  mode("append"). I used the global var g_file_mode array to replace
 *  if else statements. When the array of struct matches  **/
int	file_open(char *argv, int i)
{
	int	file;
	int	j;

	file = -1;
	j = 0;
	while (j++ < 3)
	{
		if (g_file_mode[j].mode == i)
		{
			file = open(argv, g_file_mode[j].mode, 0777);
			break ;
		}
	}
	if (file == -1)
		error();
	return (file);
}
