/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_free_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 11:30:28 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 12:39:24 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_doublearray(char **string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		free(string[index]);
		index++;
	}
	free(string);
}

void	free_cmd(t_pipe *pipex)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (index < 2)
	{
		if (pipex->cmd[index])
		{
			while (pipex->cmd[index][index2])
			{
				free(pipex->cmd[index][index2]);
				index2++;
			}
			index2 = 0;
		}
		index++;
	}
}

void	free_all(t_pipe *pipex)
{
	int	index;

	index = 0;
	while (index < 2)
	{
		if (pipex->cmdpath[index] != NULL)
			free(pipex->cmdpath[index]);
		index++;
	}
	free_cmd(pipex);
	if (pipex->path)
		free(pipex->path);
	close(pipex->input);
	close(pipex->output);
}
