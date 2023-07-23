/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pconversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:27:09 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:17:12 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_digitcount_hex(unsigned long n);
char		*ft_ptrtohex(unsigned long n, char c);

int	conversion_p(va_list args)
{
	int		i;
	char	*tmp;
	char	*string;
	void	*ptr;

	ptr = va_arg(args, void *);
	tmp = ft_ptrtohex((unsigned long) ptr, 'x');
	if (tmp == NULL)
		return (-1);
	string = ft_strjoin("0x", tmp);
	if (string == NULL)
		return (free(tmp), -1);
	i = ft_printf_putstr_fd(string, 1);
	free(tmp);
	free(string);
	return (i);
}

char	*ft_ptrtohex(unsigned long n, char c)
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
