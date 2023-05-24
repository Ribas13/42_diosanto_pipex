/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:39:13 by diosanto          #+#    #+#             */
/*   Updated: 2023/05/17 15:29:12 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>

// Function prototypes

// Paths
char	*get_path(char **envp, char *command);

// Errors
void	error_handling(int error);

// Aux Functions
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char const *str);
char	*triple_strjoin(char *s1, char *s2, char *s3);
void	get_free(char **list);

#endif