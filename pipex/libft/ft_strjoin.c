/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:00:18 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 18:32:30 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*newstr;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(sizeof(*newstr) * length);
	if (newstr == 0)
		return (newstr);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, length);
	return (newstr);
}
