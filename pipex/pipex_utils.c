/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 10:25:44 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 11:35:34 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	spit_the_error(char *error, t_pipe *pipex)
{
	free_all(pipex);
	perror(error);
	exit(1);
}

char	*handle_complete_path(char *argv)
{
	char	*tmp;
	char	**splitted_path;

	splitted_path = ft_split(argv, ' ');
	if (access(splitted_path[0], X_OK) == 0)
	{
		tmp = ft_strdup(splitted_path[0]);
		return (free_doublearray(splitted_path), tmp);
	}
	else
		return (free_doublearray(splitted_path), NULL);
}

void	close_tube(t_pipe *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}
