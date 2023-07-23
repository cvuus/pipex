/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:17:04 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:09:19 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	converter_2000(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 's')
		length = ft_printf_putstr_fd(va_arg(args, char *), 1);
	if (c == 'c')
		length = ft_printf_putchar_fd(va_arg(args, int), 1);
	if (c == 'p')
		length = conversion_p(args);
	if (c == 'i' || c == 'd')
		length = conversion_id(args);
	if (c == 'u')
		length = conversion_ui(args);
	if (c == 'x' || c == 'X')
		length = conversion_xx(args, c);
	if (c == '%')
		length = write(1, "%", 1);
	return (length);
}
