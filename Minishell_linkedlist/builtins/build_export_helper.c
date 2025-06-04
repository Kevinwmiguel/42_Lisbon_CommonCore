/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:46:02 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/01 13:47:32 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	export_helper2(char **mlc, char **argv, int i)
{
	int	j;

	if (!ft_isalpha(argv[i][0]))
		printf("export: `%s': not a valid identifier\n", argv[i]);
	else
	{
		j = mlc_size(0, mlc);
		mlc[j] = ft_strdup(argv[i]);
	}
}

void	export_helper(t_builtvars *export, char **argv, int j)
{
	export->m = var_equal_line(export->mlc, argv, j);
	while (argv[j][export->l])
	{
		while (argv[j][export->l] == \
		export->mlc[export->m][export->l] && argv[j][export->l])
		{
			if (ft_strlen3(argv[j]) == 1)
				export_helper_helper(export, argv, j);
			else
			{
				if (argv[j][export->l] == '=')
					export_helper_helper(export, argv, j);
				else if (argv[j][export->l] == '\0')
					break ;
				if (argv[j][export->l] != '\0')
					export->l++;
			}
		}
		if (argv[j][export->l] == '=')
			export_helper_helper(export, argv, j);
		if (argv[j][export->l] != '\0')
			export->l++;
	}
}
