/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:46 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:47 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*norm_4(char **paths, char *ans)
{
	char	*part_path;
	char	*path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin_gnl(paths[i], "/");
		path = ft_strjoin_gnl(part_path, ans);
		if (!access(path, F_OK))
		{
			free(paths);
			return (path);
		}
		free(path);
	}
	return (NULL);
}

char	*pathfinder(char *ans, t_env *env)
{
	char	**paths;
	char	*path;
	t_env	*tmp;

	if (!access(ans, F_OK))
		return (ans);
	tmp = env;
	while (!ft_strnstr(tmp->str, "PATH", 4))
		tmp = tmp->next;
	paths = ft_split(tmp->str + 5, ':');
	path = norm_4(paths, ans);
	if (path)
		return (path);
	free(paths);
	return (NULL);
}

char	*ft_strjoin_mini(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * j);
	if (!res)
		return (NULL);
	res[j] = 0;
	i = -1;
	while (s1 && s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		res[i + j] = s2[j];
	return (res);
}

char	*get_file_name(char *str)
{
	char	*name;
	int		i;

	if (!str)
		return (NULL);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 1));
	if (!name)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 0;
	return (name);
}
