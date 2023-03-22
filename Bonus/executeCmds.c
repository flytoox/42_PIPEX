/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainHelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:49:53 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/22 16:50:39 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(int fd[], int files[], char **path)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	close(files[1]);
	close(fd[0]);
	close(fd[1]);
	execve(path[0], path, NULL);
}

void	last_cmd(int fd[], int files[], char **path)
{
	dup2(files[2], STDIN_FILENO);
	dup2(files[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	close(files[2]);
	execve(path[0], path, NULL);
}

void	middle_cmd(int fd[], int files[], char **path, int check)
{
	if (!check)
		first_cmd(fd, files, path);
	else if (check == 1)
		last_cmd(fd, files, path);
	dup2(files[2], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	close(files[2]);
	execve(path[0], path, NULL);
}

void	execute_cmd1(int fd[], int file_in, int file_out, char **path)
{
	close(file_out);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(file_in, STDIN_FILENO);
	close(file_in);
	execve(path[0], path, NULL);
	perror("pipex");
	exit(1);
}

void	execute_cmd2(int fd[], int file_in, int file_out, char **path)
{
	close(file_in);
	close(fd[1]);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execve(path[0], path, NULL);
	perror("pipex");
	exit(1);
}
