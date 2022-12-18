/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:56:13 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/18 14:03:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/** Frees str or array of strings. Using 
 *  void * is used as its defines generic
 *  type **/


void    free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}	
}

void    *free_split_str(char **str)
{
	int	i;
	
	i = 0;
	if (str)
	{
		while (str[i++]
			ft_ptr_free((void *)&str[i]);
		ft_ptr_free((void *)&str);
	}	
}