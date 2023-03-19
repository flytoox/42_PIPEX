/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/15 17:43:24 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd1(int fd[], int file_in, int file_out, char **path)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	close(file_in);
	close(file_out);
	close(fd[1]);
	execve(path[0], path, NULL);
}

void	execute_cmd2(int fd[], int file_in, int file_out, char **path)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file_in);
	close(file_out);
	execve(path[0], path, NULL);
}

void	main_helper(int argc, char **argv, char **path1, char **path2)
{
	int		fd[2];
	int		file_in;
	int		file_out;
	int		pid1;
	int		pid2;

	file_out = open(argv[argc - 1], O_CREAT | O_WRONLY, 666);
	file_in = open(argv[1], O_RDONLY);
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
		execute_cmd1(fd, file_in, file_out, path1);
	pid2 = fork();
	if (pid2 == 0)
		execute_cmd2(fd, file_in, file_out, path2);
	close(file_in);
	close(file_out);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	char	**paths;
	char	**path1;
	char	**path2;

	if (handle_parsing(argv, argc))
		return (1);
	paths = ft_split(get_path(env), ':');
	if (!paths)
		return (ft_print("ERROR\nthere something with the path", 2), 1);
	path1 = path_cmd(paths, argv[2]);
	path2 = path_cmd(paths, argv[3]);
	if (!path1 || !path2)
		return (ft_print("Error\nCannot find these commands", 2), 1);
	if (access(argv[1], F_OK | R_OK))
		return (perror("bash"), 1);
	main_helper(argc, argv, path1, path2);
	free_str(paths);
	free_str(path1);
	free_str(path2);
}
