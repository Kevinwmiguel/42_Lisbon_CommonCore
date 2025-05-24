/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:39:41 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/24 17:35:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	input_fixer(char *input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (input[i] && input[i] == 32)
		i++;
	while (input[i] && input[i] != 32)
		i++;
	while (input[i] && input[i] == 32)
		i++;
	while (input[i])
	{
		input[j] = input[i];
		i++;
		j++;
	}
	input[j] = '\0';
}

int	where_is_echoj(char ***bizarre)
{
	int	x;
	int	j;

	x = -1;
	j = -1;
	while (bizarre[++x])
	{
		j = -1;
		while (bizarre[x][++j])
		{
			if (ft_strncmp("echo", bizarre[x][j], 4) == 0)
				return (j);
		}
	}
	return (-1);
}

int	where_is_echox(char **bizarre)
{
	int	x;

	x = -1;
	while (bizarre[++x])
	{
		if (ft_strncmp("echo", bizarre[x], 4) == 0)
			return (x);
	}
	return (-1);
}

char	*double_to_one(char **dptr)
{
	int		j;
	char	*rtn;
	char	*copy;

	j = -1;
	rtn = NULL;
	while (dptr[++j])
	{
		copy = ft_strdup(rtn);
		if (rtn)
			free (rtn);
		rtn = ft_strjoinn(copy, dptr[j]);
		free (copy);
	}
	return (rtn);
}

size_t len_dp(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	exec_builtin(int flag, char **command, char **env, t_shell *utils)
{

	int            x;
    int            y;
    char        *bizarre_breed;

	y = len_dp(command);
	x = where_is_echox(command);
    if (x != -1)
        bizarre_breed = double_to_one(utils->command);
    if (utils->input)
		input_fixer(utils->input);
    if (flag == 1 && x != -1)
    {
        build_echo(bizarre_breed + 5, utils, 0, -1);
        free (bizarre_breed);
    }
    else if (flag == 2)
		build_cd(y, command, env, utils);
    else if (flag == 3)
		build_pwd(y, command, utils);
    else if (flag == 4)
        utils->exp = build_export(y, command, utils);
    else if (flag == 5)
        utils->exp = build_unset(y, command, utils->exp, -1);
    else if (flag == 6)
        build_env(y, command, utils);
    else if (flag == 7)
        build_exit(command, utils);
}

void	index_reset(t_shell *utils)
{
	utils->j = 0;
	utils->export->i = 0;
	utils->export->j = 0;
	utils->export->k = 0;
	utils->export->l = 0;
	utils->export->m = 0;
	utils->export->n = 0;
	utils->export->x = 0;
	utils->export->flag = 0;
}

bool	redirection_verifier_utils(t_pipesort *piped, int i, int j)
{
	piped->redirection_type = NULL;
	if (ft_strncmp(piped->content[j] + i, "<", 1) == 0 &&
		piped->content[j][i + 1] != '<')
	{
		piped->redirection_type = "one left";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, "<<", 2) == 0)
	{
		piped->redirection_type = "double left";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, ">", 1) == 0 &&
		piped->content[j][i + 1] != '>')
	{
		piped->redirection_type = "one right";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, ">>", 2) == 0)
	{
		piped->redirection_type = "double right";
		return (true);
	}
	return (false);
}

bool	redirection_verifier(t_pipesort *piped)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (piped->content[++j])
	{
		while (piped->content[j][++i])
		{
			if (redirection_verifier_utils(piped, i, j) == true)
			{
				return (true);
			}
		}
		i = -1;
	}
	return (false);
}

int		correct_redirection(char **dptr)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (dptr[++j])
	{
		while (dptr[j][++i])
		{
			if (i != 0 && dptr[j][i] == '<' && dptr[j][i - 1] == '<' && dptr[j][i + 1] == '<')
				return (0);	
			if (i != 0 && dptr[j][i] == '>' && dptr[j][i - 1] == '>' && dptr[j][i + 1] == '>')
				return (0);	
			else if (dptr[j][i] == '<' && (dptr[j][i + 1] == '>' || dptr[j][i + 1] == '|' || dptr[j][i + 1] == '&'))
				return (0);
			else if (dptr[j][i] == '>' && (dptr[j][i + 1] == '<' || dptr[j][i + 1] == '|' || dptr[j][i + 1] == '&'))
				return (0);	
		}
		i = -1;
	}
	return (1);
}

int	scary_thing(t_pipesort	*piped, t_shell *utils)
{
	int			i;
	//int			k;
	t_pipesort	*piped_clone;
	t_pipesort	*piped_clone2;
	
	i = -1;
	piped_clone = piped;
	piped_clone2 = piped;
	while (utils->command[++i])
	{
		piped_clone->next = ft_calloc(1, sizeof(t_pipesort));
		piped_clone->content = ft_split(utils->command[i], ' ');
		piped_clone->id = i;
		piped_clone->redirection = redirection_verifier(piped_clone);
		// printf("type %s\n", piped->redirection_type);
		//printf("type %s\n", utils->pipe_bridge->redirection_type);
		if (piped_clone->redirection == true)
		{
			if (correct_redirection(piped_clone->content) == 0)
				return (printf("The redirection identation is incorrect\n"), 0); //retornar aqui a funcao que limpa toda a memoria da lista junto de 0.
		}
		piped_clone = piped_clone->next;
		piped_clone->prev = piped_clone2;
		piped_clone2 = piped_clone2->next;
	}
	return (1);
}

void	main2(t_shell *utils)
{
	t_pipesort	*piped;

	piped = ft_calloc(2, sizeof(t_pipesort));
	utils->pipe_bridge = piped;
	signal_search(ROOT);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	if (utils->input[0] == '\0' || utils->input[0] == '\n')
		return ;
	if (utils->input)
		add_history(utils->input);
	if (quotes_verify(utils->input) == 0)
	{
		if (pipe_verify(utils->input) == 0)
		{
			utils->command = pipping_commands(utils->input);
			if (scary_thing(piped, utils) == 1)
			{
				pipex_start(piped, utils);
			}
			free_dptr(utils->command, 0);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*utils;
	int		i;
	int		n;
	char	*num;

	i = 0;
	utils = ft_calloc(1, sizeof(t_shell));
	utils->export = ft_calloc(1, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = dptr_dup(env);
	while (utils->envr[i] && ft_strncmp("SHLVL", utils->envr[i], \
			ft_strlen3(utils->envr[i])) != 0)
		i++;
	if (utils->envr[i] != NULL)
	{
		n = ft_atoi(utils->envr[i] + ft_strlen3(utils->envr[i]) + 1);
		n++;
		free (utils->envr[i]);
		num = ft_itoa(n);
		utils->envr[i] = ft_strjoin("SHLVL=", num);
		free (num);
	}
	else
		utils->envr[i] = ft_strdup("SHLVL=1");
	utils->exp = bubble_sort(0, utils->envr, 0, argc);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
	while (1)
		main2(utils);
	return (0);
}
