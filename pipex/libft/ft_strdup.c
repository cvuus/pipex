/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:22:05 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/13 17:41:04 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (cpy == 0)
		return (cpy);
	ft_strlcpy(cpy, s1, (ft_strlen(s1) + 1));
	return (cpy);
}
