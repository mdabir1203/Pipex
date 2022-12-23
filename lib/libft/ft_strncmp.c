/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:51:46 by gcollet           #+#    #+#             */
/*   Updated: 2022/12/23 01:56:56 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction strcmp() compare les deux chaînes s1 et s2. Elle renvoie un 
entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale 
ou supérieure à s2. */
/* La fonction strncmp() renvoie un entier inférieur, égal ou supérieur à zéro
si s1 (ou ses n premiers octets) est respectivement inférieure, égale ou 
supérieure à s2. */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return ((*(unsigned char *) str1) - (*(unsigned char *) str2));
	str1++;
	str2++;
	}
	return (0);
}
