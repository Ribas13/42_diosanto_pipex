/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:49 by diosanto          #+#    #+#             */
/*   Updated: 2023/05/22 19:37:47 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//https://reactive.so/42-a-comprehensive-guide-to-pipex
//https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
//https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

/* If execve fails, the rest of the code won't be executed
Check if the second dup2"if" is necessary */
/* void	first(char **envp, char **av, int *pipe_fd)
{
	char	*str;
	char	**avsplit;
	int		infile;

	close(pipe_fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error_handling(3);
	if (dup2(infile, STDIN_FILENO) < 0)
		error_handling(6);
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		error_handling(6);
	avsplit = ft_split(av[2], ' ');
	str = get_path(envp, avsplit[0]);
	execve(str, avsplit, envp);
	get_free(avsplit);
	free(str);
	exit(4);
} */

/*Read-only, create file if it doesnt exist, if something is inside,
set to zero to avoid anything else to be there except the new content
And 0644 is for permissions, Owner has read and write permissions and
the rest read-only*/
/* void	second(char **envp, char **av, int *pipe_fd)
{
	char	*str;
	char	**avsplit;
	int		outfile;

	close(pipe_fd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_handling(4);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		error_handling(6);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		error_handling(6);
	avsplit = ft_split(av[2], ' ');
	str = get_path(envp, avsplit[0]);
	execve(str, avsplit, envp);
	get_free(avsplit);
	free(str);
	exit(4);
} */

/* void	ft_pipex(char **av, char **envp)
{
	int	pipe_id;
	int	pipe_fd[2];

	if (pipe(pipe_fd))
		error_handling(1);
	pipe_id = fork();
	if (pipe_id < 0)
		error_handling(2);
	if (!pipe_id)
		first(envp, av, pipe_fd);
	wait(0);
	pipe_id = fork();
	if (pipe_id < 0)
		error_handling(2);
	if (!pipe_id)
		second(envp, av, pipe_fd);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	wait(0);
} */

void	child_one(int infile, char **av, char **envp, int *pipe_end)
{
	char	*cmd_path;
	char	**cmd_name;

	close(pipe_end[0]);
	if (infile < 0)
		error_handling(3);
	if (dup2(infile, STDIN_FILENO) < 0)
		error_handling(6);
	if (dup2(pipe_end[1], STDOUT_FILENO) < 0)
		error_handling(6);
	cmd_name = ft_split(av[2], ' ');
	cmd_path = get_path(envp, cmd_name[0]);
	execve(cmd_path, cmd_name, envp);
	get_free(cmd_name);
	free(cmd_path);
	wait(0);
}

void	child_two(int outfile, char **av, char **envp, int *pipe_end)
{
	char	*cmd_path;
	char	**cmd_name;

	close(pipe_end[1]);
	if (outfile < 0)
		error_handling(4);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		error_handling(6);
	if (dup2(pipe_end[0], STDIN_FILENO) < 0)
		error_handling(6);
	cmd_name = ft_split(av[3], ' ');
	cmd_path = get_path(envp, cmd_name[0]);
	execve(cmd_path, cmd_name, envp);
	get_free(cmd_name);
	free(cmd_path);
	wait(0);
}

/* We divide the workload in two using two child processes, then we
wait for those processes to finish */
void	ft_pipex(int infile, int outfile, char **av, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_one(infile, av, envp, end);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child_two(outfile, av, envp, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

/* Check for the correct number of arguments and if correct, enter ft_pipex 
Read-only, create file if it doesnt exist, if something is inside,
set to zero to avoid anything else to be there except the new content
And 0644 is for permissions, Owner has read and write permissions and
the rest read-only*/
int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		outfile;

	if (ac == 5)
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (infile < 0 || outfile < 0)
			error_handling(0);
		ft_pipex(infile, outfile, av, envp);
	}
	else
		error_handling(0);
	return (0);
}
