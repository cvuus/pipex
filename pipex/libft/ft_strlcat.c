/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:05:12 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/20 11:49:33 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_src;
	size_t	len_dst;
	size_t	result;
	size_t	i;

	s = (char *) src;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	result = 0;
	i = 0;
	if (size > len_dst)
		result = len_dst + len_src;
	else
		result = size + len_src;
	while (s[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (result);
}
