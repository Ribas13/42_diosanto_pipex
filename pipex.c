/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:49 by diosanto          #+#    #+#             */
/*   Updated: 2023/05/04 20:03:38 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	fork();
	fork();
	printf("Hello\n");
	return (0);
}


//https://reactive.so/42-a-comprehensive-guide-to-pipex
//https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
//https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
//https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2
