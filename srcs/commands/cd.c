/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:45:42 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:45:44 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	replace_oldpwd(t_env *env)
{
	t_env	*tmp;
	char	*old_pwd;

	tmp = env;
	old_pwd = get_env_val(env, "PWD");
	while (tmp)
	{
		if (!ft_strncmp("OLDPWD", tmp->str, 6))
		{
			free(tmp->str);
			tmp->str = ft_strjoin("OLDPWD=", old_pwd);
			free(old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	free(old_pwd);
}

static void	replace_pwd(t_env *env)
{
	t_env	*tmp;
	char	new_pwd[200];

	getcwd(new_pwd, 200);
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("PWD", tmp->str, 3))
		{
			free(tmp->str);
			tmp->str = ft_strjoin("PWD=", new_pwd);
		}
		tmp = tmp->next;
	}
}

int	cd(t_mini *shell, char **cmd)
{
	char	*env_val;

	env_val = get_env_val(shell->env, "HOME");
	if (!cmd[1])
		chdir(env_val);
	else
	{
		free(env_val);
		env_val = ft_strdup(cmd[1]);
	}
	if (chdir(env_val) < 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(env_val);
		free(env_val);
		return (1);
	}
	free(env_val);
	replace_oldpwd(shell->env);
	replace_pwd(shell->env);
	return (0);
}
