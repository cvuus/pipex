/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:39:52 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/16 17:00:58 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	size_t	i;
	size_t	len_s;

	len_s = (unsigned int) ft_strlen(s);
	i = 0;
	str = (char *) s;
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len_s < len)
		len = len_s;
	if (len > (ft_strlen(s) - start - 1))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (substr == NULL)
		return (substr);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
