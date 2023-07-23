/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 11:25:59 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 16:47:31 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0 || needle == NULL)
		return ((char *) haystack);
	while (i < len && *haystack)
	{
		if (*haystack == needle[0] && ((i + ft_strlen(needle) - 1) < len))
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *) haystack);
		}
		haystack++;
		i++;
	}
	return (0);
}
