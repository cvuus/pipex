/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_xxconversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:38:02 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:19:29 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_itohex(unsigned int n, char c);
static int	ft_digitcount_hex(unsigned long n);

int	conversion_xx(va_list args, char c)
{
	char	*tmp;
	int		length;

	tmp = ft_itohex(va_arg(args, unsigned int), c);
	if (tmp == NULL)
		return (-1);
	length = ft_printf_putstr_fd(tmp, 1);
	free(tmp);
	return (length);
}

char	*ft_itohex(unsigned int n, char c)
{
	int		i;
	char	*result;
	char	*base_str;

	if (c == 'x')
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_digitcount_hex(n);
	result = ft_calloc(i + 1, sizeof(char));
	if (result == 0)
		return (result);
	while (n > 0)
	{
		result[i - 1] = base_str[(n % 16)];
		n = n / 16;
		i--;
	}
	return (result);
}

static int	ft_digitcount_hex(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
