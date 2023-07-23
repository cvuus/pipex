/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 11:28:47 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/28 09:48:13 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isvalidtype(char c);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup((char *) input);
	if (str == NULL)
		return (-1);
	va_start(args, input);
	i += ft_parsing(str, args);
	va_end(args);
	free(str);
	return (i);
}

int	ft_parsing(char *input, va_list args)
{
	int	length;
	int	number;

	length = 0;
	while (*input)
	{
		if (*input == '%' && *(input + 1))
		{
			if (ft_isvalidtype(*(++input)))
			{
				number = converter_2000(*input, args);
				if (number == -1)
					return (-1);
				length = length + number;
			}
		}
		else if (*input != '%')
		{
			if (ft_printf_putchar_fd(*input, 1) == -1)
				return (-1);
			length++;
		}
		input++;
	}
	return (length);
}

static int	ft_isvalidtype(char c)
{
	if (c == 'c' || c == 'd' || c == 'x' || c == 'X' || c == 'p' \
	|| c == 's' || c == 'u' || c == 'i' || c == '%')
		return (1);
	else
		return (0);
}
