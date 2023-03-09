/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 17:08:53 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}
