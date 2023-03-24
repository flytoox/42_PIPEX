/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/23 20:55:28 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	main_helper1(int fd[], int i, int argc, int *check)
{
	if (pipe(fd) < 0)
		return (perror("pipex"), exit (1));
	if (i == argc - 2)
		*check = 1;
	else if (i != 2)
		*check = 2;
}

void	main_helper(int argc, char **argv, char **paths, int files[])
{
	int		i;
	int		check;
	int		fd[2];
	int		pid;

	i = 1;
	check = 0;
	while (++i < argc - 1)
	{
		main_helper1(fd, i, argc, &check);
		pid = fork();
		if (pid == -1)
			return (perror("pipex"), exit(1));
		if (!pid)
			middle_cmd(fd, files, path_cmd(paths, argv[i]), check);
		if (files[2] != -1)
			close(files[2]);
		files[2] = fd[0];
		close(fd[1]);
	}
	close(fd[0]);
	while (waitpid(-1, NULL, 0) != -1)
	{
	}
}

int	here_doc_helper(char ***cmd_paths, int files[], int fd[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (perror("pipex"), exit(1), 1);
	if (!pid)
		execute_cmd2(fd, files[0], files[1], cmd_paths[1]);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	free_str(cmd_paths[0]);
	free_str(cmd_paths[1]);
	free(cmd_paths);
	return (waitpid(-1, NULL, 0), unlink(".temp_file"), 0);
}

int	here_doc(char **argv, char **paths)
{
	int		files[2];
	char	***cmd_paths;
	int		pid;
	int		fd[2];

	files[0] = open(".temp_file", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	files[1] = open(argv[5], O_CREAT | O_APPEND | O_WRONLY, 0777);
	if (files[0] < 0 || files[1] < 0)
		return (perror("pipex"), exit(1), 1);
	files[0] = fill_file(files[0], argv);
	if (files[0] < 0 || pipe(fd) < 0)
		return (perror("pipex"), exit(1), 1);
	cmd_paths = malloc(sizeof(cmd_paths) * 2);
	cmd_paths[0] = path_cmd(paths, argv[3]);
	cmd_paths[1] = path_cmd(paths, argv[4]);
	pid = fork();
	if (pid == -1)
		return (perror("pipex"), exit(1), 1);
	if (!pid)
		execute_cmd1(fd, files[0], files[1], cmd_paths[0]);
	return (here_doc_helper(cmd_paths, files, fd));
}

int	main(int argc, char **argv, char **env)
{
	char	**paths;
	int		files[3];

	if (handle_parsing(argv, argc))
		return (1);
	paths = ft_split(get_path(env), ':');
	if (!paths)
		return (ft_print("ERROR\nthere is something with the path", 2), 1);
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		if (argc != 6)
			return (ft_print("Numbers of args is incorrect", 2), 1);
		return (here_doc(argv, paths));
	}
	if (access(argv[1], F_OK | R_OK))
		return (perror("pipex"), free_str(paths), 1);
	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	files[2] = -1;
	main_helper(argc, argv, paths, files);
	close(files[0]);
	close(files[1]);
	close(files[2]);
	free_str(paths);
}
