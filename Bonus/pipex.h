/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:55:36 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/23 20:55:32 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../gnl/get_next_line.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size);
char	**ft_split(const char *str, char c);
size_t	ft_strlen(const char *s);
void	ft_print(const char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_str(char **str);

char	**path_cmd(char **paths, char *cmd);
char	*get_path(char **env);
int		handle_parsing(char **argv, int argc);
void	first_cmd(int fd[], int files[], char **path);
void	last_cmd(int fd[], int files[], char **path);
void	middle_cmd(int fd[], int files[], char **path, int check);
void	execute_cmd1(int fd[], int file_in, int file_out, char **path);
void	execute_cmd2(int fd[], int file_in, int file_out, char **path);
int		fill_file(int fd, char **argv);

#endif