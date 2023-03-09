/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsHelpers1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:12:14 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/09 11:34:14 by obelaizi         ###   ########.fr       */
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
	if (argc != 5)
		return (ft_print("ERROR\nDude the number of arguments is sus ;)", 2), 1);
	return (0);
}