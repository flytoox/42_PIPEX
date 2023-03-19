/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsHelpers1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:12:14 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/11 19:20:06 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
	return (0);
}

int	handle_parsing(char **argv, int argc)
{
	if (argc != 5 && argv)
		return (ft_print("ERROR\nDude the number of arguments is sus ;)", 2), 1);
	return (0);
}

char	**path_cmd(char **paths, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	tmp = 0;
	path = ft_split(cmd, ' ');
	if (!access(path[0], F_OK))
		return (path);
	cmd = ft_strjoin("/", path[0]);
	while (paths[i])
	{
		if (tmp)
			free(tmp);
		tmp = ft_strjoin(paths[i], cmd);
		if (!access(tmp, F_OK))
			return (free(cmd), free(path[0]), path[0] = tmp, path);
		i++;
	}
	free_str(path);
	return (free(tmp), free(cmd), NULL);
}
