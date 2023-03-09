/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:56:40 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 11:33:53 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**paths;

	if (handle_parsing(argv, argc))
		return (1);
	paths = ft_split(get_path(env), ':');
	if (!paths)
		return (ft_print("ERROR\nthere something with the path", 2), 1);
}
