/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 09:54:44 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 16:33:29 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp( const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned int)(s1[i]) != (unsigned int)(s2[i]))
		{
			result = (unsigned char)(s1[i]) - (unsigned char)s2[i];
			return (result);
		}
		i++;
	}
	if (i == n)
		i--;
	result = (unsigned char)(s1[i]) - (unsigned char)s2[i];
	return (result);
}
