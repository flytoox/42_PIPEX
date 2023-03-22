/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/22 16:50:32 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	close(fd[0]);
}

int	fill_file(int fd, char **argv)
{
	int		check;
	char	*line;

	check = 1;
	line = NULL;
	while (line || check)
	{
		if (!check)
			free(line);
		if (check)
			check = 0;
		line = get_next_line(0);
		if (line && ft_strlen(line) - 1 == ft_strlen(argv[2])
			&& !ft_strncmp(argv[2], line, ft_strlen(line) - 1))
		{
			free(line);
			break ;
		}
		ft_print(line, fd);
	}
	close(fd);
	return (open(".temp_file", O_RDONLY));
}

int	here_doc(int argc, char **argv, char **paths)
{
	int		files[2];
	char	***cmd_paths;
	int		pid;
	int		fd[2];

	files[0] = open(".temp_file", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	files[1] = open(argv[5], O_CREAT | O_APPEND | O_WRONLY, 0777);
	files[0] = fill_file(files[0], argv);
	pipe(fd);
	cmd_paths = malloc(sizeof(char *) * 2);
	cmd_paths[0] = path_cmd(paths, argv[3]);
	cmd_paths[1] = path_cmd(paths, argv[4]);
	pid = fork();
	if (!pid)
		execute_cmd1(fd, files[0], files[1], cmd_paths[0]);
	pid = fork();
	if (!pid)
		execute_cmd2(fd, files[0], files[1], cmd_paths[1]);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	return (waitpid(-1, NULL, 0), unlink(".temp_file"), 0);
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
		return (here_doc(argc, argv, paths));
	if (access(argv[1], F_OK | R_OK))
		return (perror("pipex"), 1);
	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	files[2] = 0;
	main_helper(argc, argv, paths, files);
	close(files[0]);
	close(files[1]);
	close(files[2]);
	free_str(paths);
	close(2);
}
