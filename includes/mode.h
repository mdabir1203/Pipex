/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:15:27 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/21 04:17:29 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_H
# define MODE_H

# include <fcntl.h>

typedef struct s_mode
{
	int		mode;
	char	*name;
}	t_filemode;

t_filemode	g_file_mode[] = {{O_WRONLY | O_CREAT | O_APPEND, "append"}, \
	{O_WRONLY | O_CREAT | O_TRUNC, "truncate"}, \
	{O_RDONLY, "read"}};

#endif