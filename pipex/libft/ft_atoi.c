/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:46:32 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 15:45:52 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_iswhitespace(char c);

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_iswhitespace(*str))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign == -1)
		return (0);
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = (result * 10 + (*str - '0'));
		str++;
	}
	return (result * sign);
}

int	ft_iswhitespace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == 32))
		return (c);
	return (0);
}
