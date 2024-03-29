/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:47:15 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:47:16 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*norm_3(t_mini *shell, char *str, int *k, int j)
{
	char	*perm;
	char	*name;
	char	*tmp;

	name = NULL;
	tmp = NULL;
	perm = NULL;
	perm = ft_substr(str, 0, j - 1);
	*k = 0;
	while (str[j + *k] && str[j + *k] != -2 \
	&& str[j + *k] != '\'' && str[j + *k] != '\"')
		(*k)++;
	name = ft_substr(str, j, *k);
	if (!ft_strncmp(name, "?", 2))
		tmp = ft_itoa(shell->exit_status);
	else
		tmp = get_env_val(shell->env, name);
	free(name);
	perm = ft_strjoin_gnl(perm, tmp);
	free(tmp);
	return (perm);
}

void	get_spec_char(t_cmd *cmd, int i, t_mini *shell)
{
	char	*perm;
	int		j;
	int		k;

	perm = NULL;
	j = -1;
	while (cmd->str[i][++j])
	{
		if (cmd->str[i][j] == -2)
		{
			perm = norm_3(shell, cmd->str[i], &k, ++j);
			free(cmd->str[i]);
			cmd->str[i] = perm;
			j = -1;
		}
		else if (cmd->str[i][j] == -1)
			cmd->str[i][j] = ' ';
	}
}

char	*get_env_val(t_env *env, char *name)
{
	t_env	*tmp;
	char	*res;
	int		i;

	tmp = env;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i] != '=')
			;
		res = ft_substr(tmp->str, 0, i);
		if (!ft_strncmp(name, res, ft_strlen(res) + 1))
		{
			free(res);
			return (ft_substr(tmp->str, i + 1, ft_strlen(tmp->str) - i));
		}
		free(res);
		tmp = tmp->next;
	}
	return (NULL);
}

void	replace_spec_char(t_mini *shell)
{
	t_cmd	*cmd;
	int		i;

	cmd = shell->cmd;
	while (cmd)
	{
		i = -1;
		while (cmd->str[++i])
			get_spec_char(cmd, i, shell);
		cmd = cmd->next;
	}
}

char	**transform_env(t_env *env)
{
	t_env	*tmp;
	char	**ret;
	int		i;

	i = 0;
	tmp = env;
	ret = (char **)malloc(sizeof(char *) * (ft_lstsize((t_list *)env) + 1));
	if (!ret)
		return (NULL);
	while (tmp)
	{
		ret[i++] = ft_strdup(tmp->str);
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}
