/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:10:30 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/14 15:28:50 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}



int	check_file_is_valid(char *file_line)
{
	// while (*file_line)
	// {
	// 	if (*file_line == '.')
	// 	{
	// 		if (find(file_line, ".ber"))
	// 		{
	// 			return (1);
	// 		}
	// 	}
	// 	file_line++;
	// }
	// write(1, "ERROR: map file is not valid\n", 29);
	// exit(1);
	char *temp;

	temp = ft_strchr(file_line, '.');
	if (temp)
	{
		if (ft_strncmp(temp, ".ber", 5) == 0)
		{
			return (1);
		}
		else
		{
			ft_printf("erro encontrado no nome da funcao\n");
			return (0);
		}
			
	}
	else 
	{
		ft_printf("erro encontrado no nome da funcao");
		return (0);
	}
	return 1;
}

int	check_c(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n - 1] == 'C')
			{
				ft_printf("NO way to collectable and exit\n");
				final_cleaner(vars, 4);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

int	check_e(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n] == 'E')
			{
				ft_printf("No way to exit\n");
				final_cleaner(vars, 0);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(vars);
	check_walls(vars);
	check_elements(vars);
	if (!checker_way_out(vars->map, 0, 0))
	{
		printf("no way out\n");
		exit(1);
	}
}
