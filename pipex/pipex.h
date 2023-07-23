/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 10:16:51 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 12:39:19 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_CMDPATH "Command not found"

//Pipex Struct

typedef struct s_pipex
{
	int		input;
	int		output;
	int		pid1;
	int		pid2;
	int		tube[2];
	char	*path;
	char	*cmdpath[2];
	char	**cmd[2];
}	t_pipe;

//Command File
char	*get_path(char **envp);
char	**get_cmd(char *argv);
char	*get_cmdpath(char *path, char *cmd, char *argv);

//Pipex Utils
char	*handle_complete_path(char *argv);
void	close_tube(t_pipe *pipex);
int		start_pipex(t_pipe *pipex, char **envp);
void	spit_the_error(char *error, t_pipe *pipex);
int		ft_strrchrint(const char *s, int c);

//Pipex Free Utils
void	free_all(t_pipe *pipex);
void	free_doublearray(char **string);

#endif