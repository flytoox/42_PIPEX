/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/21 22:57:16 by obelaizi         ###   ########.fr       */
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
	execve(path[0], path, NULL);
}

void	middle_cmd(int fd[], int files[], char **path, int check)
{
	write(2, path[0], ft_strlen(path[0]));
	write(2, "\n", 1);
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

void	main_helper(int argc, char **argv, char **paths, int files[])
{
	int		i;
	int		check;
	int		fd[2];
	int		pid;

	i = 2;
	check = 0;
	while (i < argc - 1)
	{
		pipe(fd);
		if (i == argc - 2)
			check = 1;
		else if (i != 2)
			check = 2;
		pid = fork();
		if (!pid)
			middle_cmd(fd, files, path_cmd(paths, argv[i]), check);
		waitpid(pid, NULL, 0);
		files[2] = fd[0];
		close(fd[1]);
		i++;
	}
}

void	execute_cmd1(int fd[], int file_in, int file_out, char **path)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	close(file_in);
	close(file_out);
	close(fd[1]);
	write(2, "--", ft_strlen(path[0]));
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
	write(2, path[0], ft_strlen(path[0]));
	execve(path[0], path, NULL);
}


int	here_doc(int argc, char **argv, char **paths)
{
	int		files[2];
	char	*line;
	int		check;
	int		pid;
	int		fd[2];

	check = 1;
	line = NULL;
	files[0] = open(".tmp_file", O_CREAT | O_RDWR | O_TRUNC, 666);
	files[1] = open(argv[5], O_CREAT | O_APPEND | O_WRONLY, 666);
	while (line || check)
	{
		if (!check)
			free(line);
		if (check)
			check = 0;
		line = get_next_line(0);
		if (line && ft_strlen(line) - 1 == ft_strlen(argv[2]) && !ft_strncmp(argv[2], line, ft_strlen(line) - 1))
		{
			free(line);
			break;
		}
		ft_print(line, files[0]);
	}
	pipe(fd);
	pid = fork();
	if (!pid)
		execute_cmd1(fd, files[0], files[1], path_cmd(paths, argv[3]));
	pid = fork();
	if (!pid)
		execute_cmd2(fd, files[0], files[1], path_cmd(paths, argv[4]));
	waitpid(-1, NULL, 0);
	unlink(".temp_file");
	return(0);
}

int	main(int argc, char **argv, char **env)
{
	char	**paths;
	int		files[3];

	if (handle_parsing(argv, argc))
		return (1);
	paths = ft_split(get_path(env), ':');
	if (!paths)
		return (ft_print("ERROR\nthere something with the path", 2), 1);
	if (!ft_strncmp("here_doc", argv[1], 9))
		return(here_doc(argc, argv, paths));
	if (access(argv[1], F_OK | R_OK))
		return (perror("bash"), 1);
	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC , 666);
	files[2] = 0;
	main_helper(argc, argv, paths, files);
	close(files[0]);
	close(files[1]);
	close(files[2]);
	free_str(paths);
	// char *s = get_next_line(0);
	// while (s)
	// {
	// 	printf("|%s|", s);
	// 	s = get_next_line(0);
	// 	// s++;
	// }
}
