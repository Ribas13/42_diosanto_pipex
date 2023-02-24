/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:49 by diosanto          #+#    #+#             */
/*   Updated: 2023/02/24 17:16:14 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	id;
	int	fd[2];
	int	x;
	int	y;

	if (pipe(fd) == -1)
	{
		printf("ERROR");
		return (1);
	}
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		printf("Input a number: \n");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process: %d\n", y);
	}
	return (0);
}
