/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchrint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 17:58:14 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 10:07:33 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strrchrint(const char *s, int c)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			tmp = i;
		i++;
	}
	if ((char) c == '\0')
		return (1);
	return (tmp);
}
