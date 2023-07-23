/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_idconversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:57:02 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:18:54 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	conversion_id(va_list args)
{
	char	*tmp;
	int		length;
	int		number;

	number = va_arg(args, int);
	tmp = ft_itoa(number);
	if (tmp == 0)
		return (-1);
	length = ft_printf_putstr_fd(tmp, 1);
	free(tmp);
	return (length);
}
