/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2025/02/20 23:26:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

//utils->input = readline("minishell"); 
//prompt escreve por cima por causa do prompt ser interativo

void	main2_helper(t_pipe_comms *pcomms, t_shell *utils)
{
	int	flag;

	flag = builtins(pcomms->args[0], utils, -1);
	if (flag == 0)
		path_comms(utils->command, utils, -1, -1);
	if (flag != 0)
		exec_builtin(flag, pcomms, utils->envr, utils);
}

void	init_pcomms(t_pipe_comms *pcomms)
{
	if (pcomms->strp)
		free (pcomms->strp);
	pcomms->strp = ft_calloc(1,1);
	pcomms->args = NULL;
	pcomms->argc = 0;
	pcomms->fd_in = NULL;
	pcomms->fd_out = NULL;
	pcomms->next = NULL;
}

int	fusion(t_nodes *tree, t_shell *utils, int h)
{
	char	*connection;
	char	*shelf;

	connection = ft_strjoinsp(tree->content, utils->command[h]);
	h++;
	while (utils->command[h] && utils->command[h][0] == '-')
	{
		if (shelf)
			free(shelf);
		shelf = ft_strjoinsp(connection, utils->command[h]);
		connection = shelf;
		h++;
	}
	tree->content = shelf;
	free (connection);
	return (h);
}

int	tree_filler(t_nodes *tree_cpy, t_shell *utils, int h, int layer_count)
{
	int	x;
	int shelf;
	int	flag;

	printf("\nCAGANEIRA!!!!!!!!!!\n");
	flag = 0;
	shelf = layer_count;
	layer_count++;
	x = h;
	printf("H ======= %i\n", h);
	if (h > 0)
	{
		while (utils->command[h - 1] && utils->command[h - 1][0] != '|')		
		{
			h--;
			if (h == 0)
				break ;
		}
	}
	if (h < x)
	{
		tree_cpy->left = ft_calloc(1, sizeof(t_nodes));
		tree_cpy = tree_cpy->left;
		tree_cpy->content = utils->command[h];
		tree_cpy->token = 'C';
		tree_cpy->layer = layer_count;
		layer_count++; // aqui lvl do comando 
		printf("\nAAAAAAAAAAAA tree_cpy->content = %s, nivel %i da arvore, token= %c\n", tree_cpy->content, tree_cpy->layer, tree_cpy->token);
		h++;
	}
	while (h < x)
	{
		if (utils->command[h][0] == '-' && flag == 0)
		{
			tree_cpy->left = ft_calloc(1, sizeof(t_nodes));
			tree_cpy = tree_cpy->left;
			tree_cpy->content = utils->command[h];
			tree_cpy->token = 'F';
			tree_cpy->layer = layer_count;
			printf("\nBBBBBBBBBBBBBtree_cpy->content = %s, nivel %i da arvore, token= %c\n", tree_cpy->content, tree_cpy->layer, tree_cpy->token);
			flag = 1;
		}
		else if (utils->command[h][0] == '-' && flag == 1)
			h = fusion(tree_cpy, utils, h);
		else if ((ft_isalnum(utils->command[h][0]) == 1|| utils->command[h][0] == '_'))
		{
			tree_cpy->right = ft_calloc(1, sizeof(t_nodes));
			tree_cpy = tree_cpy->right;
			tree_cpy->content = utils->command[h];
			tree_cpy->token = 'A';
			printf("\nCCCCCCCCCCCCCCCCtree_cpy->content = %s, nivel %i da arvore, token= %c\n", tree_cpy->content, tree_cpy->layer, tree_cpy->token);
		}
		h++;
	}
	/*if (utils->command[h][0] == '-')
		fusion(tree_cpy, utils, h);*/
	printf("============================%i\n", shelf);
	if (utils->command[h + 1] == NULL)
	{
		tree_cpy->left = ft_calloc(1, sizeof(t_nodes));
		tree_cpy = tree_cpy->left;
		if (utils->command[h][0] == '-')
			tree_cpy->token = 'F';
		else if ((ft_isalnum(utils->command[h][0]) == 1|| utils->command[h][0] == '_'))
			tree_cpy->token = 'A';
		else
			tree_cpy->token = 'C';
	 	tree_cpy->content = utils->command[h];
	 	tree_cpy->layer = layer_count;
		layer_count++;
		printf("\nDDDDDDDDDDDDDDDDDDtree_cpy->content = %s, nivel %i da arvore, token= %c\n", tree_cpy->content, tree_cpy->layer, tree_cpy->token);
	 }
	shelf++;
	return (shelf);
}

int	main3(t_nodes *tree, t_pipe_comms *pcomms, t_shell *utils)
{
	// t_nodes	*tree_cpy;

	// tree_cpy = tree;
	// while (tree_cpy && tree_cpy->right)
	// {
	// 	//mesclaçao
	// 	pipex(tree_cpy->fd_in, pcomms, utils, tree_cpy->fd_out);
	// 	tree = tree->right;
	// }
	while (tree->right)
				tree = tree->right;
			ft_split_args_in_comms(pcomms, utils);
			pcomms_arg_count(pcomms);
			main2_helper(pcomms, utils);
			free_dptr(utils->command, 0);
	return (0);
}

int	main2(t_shell *utils)
{
	t_pipe_comms	*pcomms;
	t_nodes			*tree;
	t_nodes			*tree_cpy;
	int				layer_count;

	layer_count = 0;
	pcomms = ft_calloc(1, sizeof(t_pipe_comms));
	tree = ft_calloc(1, sizeof(t_nodes));
	tree_cpy = tree;
	init_pcomms(pcomms);
	free_dptr(utils->command, 0);
	signal_search(ROOT);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	if (utils->input)
		add_history(utils->input);
	else
		return (free_dptr(utils->envr, 0), free(utils->export), \
		free_dptr(utils->exp, 0), free(utils), 0);
	if (quotes_verify(utils->input) == 0)
	{
		if (pipe_verify(utils->input, -1, 0) == 0)
		{
			utils->command = pipping_commands(utils->input, pcomms);
			int h;
			h = -1;
			while (utils->command[++h])
			{
				printf("utils->command[%d]: %s\n", h, utils->command[h]);
				if (utils->command[h][0] == '|')
				{
					tree_cpy->content = utils->command[h];
					tree_cpy->token = 'P';
					tree_cpy->layer = layer_count;
					layer_count = tree_filler(tree_cpy, utils, h, layer_count);
				}
				else if (utils->command[h + 1] == NULL)
					layer_count = tree_filler(tree_cpy, utils, h, layer_count);
				if (utils->command[h + 1])
				{
					tree_cpy->right = ft_calloc(1, sizeof(t_nodes));
					tree_cpy = tree_cpy->right;
				}
				else
					tree_cpy = NULL;
			}
			main3(tree, pcomms, utils);
			// while (tree->right)
			// 	tree = tree->right;
			// ft_split_args_in_comms(pcomms, utils);
			// pcomms_arg_count(pcomms);
			// main2_helper(pcomms, utils);
			// free_dptr(utils->command, 0);
		}
		utils->command = NULL;
	}
	return (1); 
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*utils;

	utils = ft_calloc(1, sizeof(t_shell));
	utils->export = ft_calloc(1, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = dptr_dup(env);
	increase_shlvl(utils);
	utils->exp = bubble_sort(0, utils->envr, 0, argc);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
	signal_search(IGNORE);
	while (main2(utils))
		;
	return (0);
}
 