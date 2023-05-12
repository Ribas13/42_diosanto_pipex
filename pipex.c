/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:49 by diosanto          #+#    #+#             */
/*   Updated: 2023/05/11 18:42:46 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//https://reactive.so/42-a-comprehensive-guide-to-pipex
//https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
//https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

void	first_file(char **envp, char **av, int pipe_id)
{
}

void	ft_pipex(char **av, char **envp)
{
	int	pipe_id;
	int	pipe_fd[2];

	if (pipe(pipe_fd))
		error_handling(1);
	pipe_id = fork();
	if (pipe_id < 0)
		error_handling(2);
	if (!pipe_id)
		first_file(envp, av, pipe_id);
	wait(0);
	pipe_id = fork();
	if (pipe_id < 0)
		error_handling(2);
	if (!pipe_id)
		second(envp, av, pipe_id);
	close(pipe_id[1]);
	close(pipe_id[0]);
	wait(0);
}

/* Check for the correct number of arguments and if correct, enter ft_pipex */
int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		ft_pipex(av, envp);
	else
		error_handling(0);
	return (0);
}
