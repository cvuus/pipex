/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:35:04 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 18:15:30 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_currentcharinset(char s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (ft_strlen(set) == 0 || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] || s1[end])
	{
		while (ft_currentcharinset(s1[start], set) == 0)
			start++;
		while (ft_currentcharinset(s1[end], set) == 0)
			end--;
		break ;
	}
	return (ft_substr(s1, start, (end - start) + 1));
}

int	ft_currentcharinset(char s, const char *set)
{
	while (*set)
	{
		if (*set == s)
			return (0);
		set++;
	}
	return (1);
}
