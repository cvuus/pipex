/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:44:58 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/10/17 17:48:34 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_digitcount(int n);

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	char	number;

	i = ft_digitcount(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = ft_calloc(i + 1, sizeof(char));
	if (result == 0)
		return (result);
	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
	}
	while (n != 0 && i > 0)
	{
		number = (n % 10) + '0';
		result[i - 1] = number;
		n = n / 10;
		i--;
	}
	return (result);
}

int	ft_digitcount(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}
