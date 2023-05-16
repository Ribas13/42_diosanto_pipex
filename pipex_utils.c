/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:17:01 by ribs              #+#    #+#             */
/*   Updated: 2023/05/16 17:03:41 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* **This function takes two parameters, envp is an array of strings
representing the environment variables, and command, which is a string
representing the command for which the path is to be found.* 

1. Function checks if the 'command' is either 'NULL', or if it exists using the
access function with the F_OK flag. If it exists, the function returns the
'command' itself, since it already contains the full path.

2. */
char	*getpath(char **envp, char *command)
{
	int		i;
	char	**paths;
	char	*str;

	if (!command || !access(command, F_OK))
		return (command);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		str = triple_strjoin(paths[i++], "/", command);
		if (!access(str, F_OK))
			break ;
		free(str);
		str = NULL;
	}
	if (!str)
		error_handling(5);
	get_free(paths);
	return (str);
}
