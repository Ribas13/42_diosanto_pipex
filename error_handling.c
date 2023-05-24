/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:09:58 by diosanto          #+#    #+#             */
/*   Updated: 2023/05/17 15:17:50 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling(int error)
{
	if (error == 0)
		perror("Invalid number of parameters");
	if (error == 1)
		perror("Error initializing the pipe");
	if (error == 2)
		perror("Error initializing the fork");
	if (error == 3)
		perror("Error reading the infile");
	if (error == 4)
		perror("Error initializing the outfile");
	if (error == 5)
		perror("Path not found");
	if (error == 6)
		perror("Error related to dup2");
}
