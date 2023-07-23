/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 11:26:32 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 12:25:55 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "pipex.h"

void	initialitize_pipe(t_pipe *pipex, char **argv, char **envp)
{
	int			check;

	check = pipe(pipex->tube);
	if (check < 0)
	{
		perror("in initialize pipe");
		exit(1);
	}
	pipex->path = get_path(envp);
	pipex->cmd[0] = get_cmd(argv[2]);
	pipex->cmd[1] = get_cmd(argv[3]);
	if (pipex->cmd[0] == NULL)
		pipex->cmdpath[0] = NULL;
	else
		pipex->cmdpath[0] = get_cmdpath(pipex->path, pipex->cmd[0][0], argv[2]);
	if (pipex->cmd[1] == NULL)
		pipex->cmdpath[1] = NULL;
	else
		pipex->cmdpath[1] = get_cmdpath(pipex->path, pipex->cmd[1][0], argv[3]);
}

//Replace std out with writing part of tube
//Replace std input with input file

int	execute_first_process(t_pipe *pipex, char *envp[])
{
	int	check;
	int	index;

	index = 0;
	if (pipex->input < 1)
		exit(1);
	dup2(pipex->tube[1], 1);
	close(pipex->tube[0]);
	dup2(pipex->input, 0);
	if (!(pipex->cmdpath[0]))
	{
		dup2(2, 1);
		if (!(pipex->cmd[0][0]))
			ft_printf("pipex:  command not found\n");
		else
			ft_printf("pipex: %s: command not found\n", pipex->cmd[0][0]);
		free_all(pipex);
		exit (1);
	}
	check = execve(pipex->cmdpath[0], pipex->cmd[0], envp);
	if (check < 0)
		return (spit_the_error("pipex: ", pipex), -1);
	return (0);
}

//Replace std out with reading part of tube
//Replace std input with input file

int	execute_second_process(t_pipe *pipex, char **envp)
{
	int	check;
	int	index;

	index = 0;
	dup2(pipex->tube[0], 0);
	close(pipex->tube[1]);
	if (dup2(pipex->output, 1) < 0)
		spit_the_error("pipex", pipex);
	if (!(pipex->cmdpath[1]))
	{
		dup2(2, 1);
		if (!(pipex->cmd[1][0]))
			ft_printf("pipex:  command not found\n");
		else
			ft_printf("pipex: %s: command not found\n", pipex->cmd[1][0]);
		free_all(pipex);
		exit(127);
	}
	check = execve(pipex->cmdpath[1], pipex->cmd[1], envp);
	if (check < 0)
		return (spit_the_error("pipex", pipex), -1);
	return (0);
}

int	start_pipex(t_pipe *pipex, char **envp)
{
	int	status1;
	int	status2;

	status2 = 0;
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		perror("pipex:");
	if (pipex->pid1 == 0)
		execute_first_process(pipex, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		perror("pipex:");
	if (pipex->pid2 == 0)
		execute_second_process(pipex, envp);
	close_tube(pipex);
	waitpid(pipex->pid1, &status1, 0);
	waitpid(pipex->pid2, &status2, 0);
	if (WIFEXITED(status2))
		status2 = (WEXITSTATUS(status2));
	return (status2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;
	int		status;

	if (argc != 5)
		return (ft_printf(ERR_INPUT));
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input < 0)
		perror("pipex: input");
	pipex.output = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.output < 0)
	{
		write (2, argv[4], ft_strlen(argv[4]));
		return (perror(" "), 1);
	}
	initialitize_pipe(&pipex, argv, envp);
	status = start_pipex(&pipex, envp);
	free_all(&pipex);
	return (status);
}

	// system("leaks pipex");