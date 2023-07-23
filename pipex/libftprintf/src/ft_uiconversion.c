/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uiconversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:53:20 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:17:50 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_digitcount(unsigned long n);
char		*ft_uitoa(unsigned int n);

int	conversion_ui(va_list args)
{
	char	*tmp;
	int		length;

	tmp = ft_uitoa(va_arg(args, unsigned int));
	if (tmp == NULL)
		return (-1);
	length = ft_printf_putstr_fd(tmp, 1);
	free(tmp);
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*result;
	char	number;

	i = ft_digitcount(n);
	if (n == 0)
		return (ft_strdup("0"));
	result = ft_calloc(i + 1, sizeof(char));
	if (result == 0)
		return (result);
	while (n > 0)
	{
		number = (n % 10) + '0';
		result[i - 1] = number;
		n = n / 10;
		i--;
	}
	return (result);
}

static int	ft_digitcount(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
