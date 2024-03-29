/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:15 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:46:16 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset_first_env_var(t_mini *shell, char *name)
{
	t_env	*tmp;

	tmp = shell->env;
	if (ft_strncmp(name, shell->env->str, ft_strlen(name)))
		return (0);
	tmp = shell->env->next;
	shell->env->next = NULL;
	free(shell->env);
	shell->env = tmp;
	return (1);
}

void	unset_name(char *name, t_env *og_env, t_mini *shell)
{
	t_env	*env;
	t_env	*tmp;

	env = og_env;
	if (!ft_strncmp(name, "_", 1))
		;
	else if (unset_first_env_var(shell, name))
		;
	else
	{
		while (env && env->next)
		{
			if (!ft_strncmp(name, env->next->str, ft_strlen(name)))
			{
				tmp = env->next->next;
				free(env->next->str);
				free(env->next);
				env->next = tmp;
			}
			env = env->next;
		}
	}
}

int	unset(char **arg, t_env *env, t_mini *shell)
{
	int	i;
	int	j;

	i = 0;
	while (arg[++i])
	{
		j = 0;
		if (ft_isalpha(arg[i][0]) || arg[i][0] == '_')
		{
			while (ft_isalnum(arg[i][j]) || arg[i][j] == '_')
				j++;
		}
		if ((!ft_isalpha(arg[i][0]) || arg[i][j])
		&& ft_strncmp(arg[i], "_", 1))
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(arg[i], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		else
			unset_name(arg[i], env, shell);
	}
	return (0);
}
