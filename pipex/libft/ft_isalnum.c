/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:48 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/10 10:36:04 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalpha(int c)
// {
// 	if ((c > 64 && c < 91) || (c > 96 && c < 123))
// 	{
// 		return (c);
// 	}
// 	return (0);
// }

// int	ft_isdigit(int c)
// {
// 	if (c > 47 && c < 58)
// 	{
// 		return (c);
// 	}
// 	return (0);
// }

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
	{
		return (c);
	}
	return (0);
}
