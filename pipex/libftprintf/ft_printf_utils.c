/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 17:01:49 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/13 16:11:24 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write (fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_printf_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
