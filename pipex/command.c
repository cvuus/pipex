/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 10:47:31 by cuechtri      #+#    #+#                 */
/*   Updated: 2023/01/18 12:18:51 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	if (envp[0] == NULL)
		return (NULL);
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (ft_strtrim(envp[i], "PATH="));
		else
			i++;
	}
	return (NULL);
}

int	nbr_quotes(char *argv)
{
	int	i;
	int	count1;
	int	count2;

	i = 0;
	count1 = 0;
	count2 = 0;
	while (argv[i])
	{
		if (argv[i] == 34)
			count1++;
		else if (argv[i] == 39)
			count2++;
		i++;
	}
	if (count1 == 0 && count2 == 0)
		return (-1);
	if (count1 % 2 == 0 && count2 % 2 == 0)
		return (0);
	else
		return (-1);
}

char	*replace(char *argv)
{
	int	i;
	int	replace;
	int	count34;

	i = 0;
	replace = 1;
	count34 = 0;
	while (argv[i++])
	{
		if (argv[i] == ' ' && replace > 0)
			argv[i] = 34;
		else if (argv[i] == 39 && count34 < 1)
		{
			replace = 0;
			argv[i] = 34;
		}
		else if (argv[i] == 34)
		{
			count34++;
			replace = 0;
			if (count34 == 2)
				count34 = 0;
		}
	}
	return (ft_strdup(argv));
}

char	**get_cmd(char *argv)
{
	char	**cmd;
	char	*tmp;
	char	*copy;
	int		start;

	copy = ft_strdup(argv);
	if (ft_strchr(argv, 47))
	{
		start = ft_strrchrint(argv, 47);
		tmp = ft_substr(copy, start + 1, ft_strlen(copy) - start);
		copy = ft_strdup(tmp);
		free(tmp);
	}
	if (nbr_quotes(copy) == 0)
	{
		tmp = replace(copy);
		cmd = ft_split(tmp, 34);
		if (tmp)
			free(tmp);
	}
	else
		cmd = ft_split(copy, ' ');
	free(copy);
	return (cmd);
}

char	*get_cmdpath(char *path, char *cmd, char *argv)
{
	char	**splitted_path;
	char	*filename;
	char	*tmp;
	int		check;
	int		i;

	i = 0;
	if (path == NULL || cmd == NULL)
		return (NULL);
	if (ft_strrchrint(argv, 47))
		return (handle_complete_path(argv));
	splitted_path = ft_split(path, ':');
	if (splitted_path == NULL)
		return (NULL);
	while (splitted_path[i])
	{
		tmp = ft_strjoin(splitted_path[i], "/");
		filename = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(filename, X_OK) == 0)
			return (free_doublearray(splitted_path), filename);
		free(filename);
		i++;
	}
	return (free_doublearray(splitted_path), NULL);
}
