/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_csconversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 12:21:09 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/25 17:02:53 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	conversion_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

// int	conversion_s(va_list args)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = va_arg(args, char *);
// 	if (str == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	while (str[i] != '\0')
// 	{
// 		ft_putchar_fd(str[i], 1);
// 		i++;
// 	}
// 	return (i);
// }
