/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:33:32 by ialousse          #+#    #+#             */
/*   Updated: 2023/11/13 13:34:15 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

/*
**		MAIN FONCLTIONS
*/

char	*ft_check_error(int fd, char **line);
int		get_next_line(int fd, char **line);
char	*ft_linecpy(char *save);
char	*ft_savecpy(char *save);
int		ft_end(int reader, char **line, char *save[FOPEN_MAX], int fd);

/*
**		UTILS FONCLTIONS
*/

char	*ft_strjoin_gnl(const char *s1, const char *s2);
int		ft_isreturn(char *str);
char	*ft_strdup_gnl(char *save);

#endif
