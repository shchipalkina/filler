/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:06:26 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:20:20 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_strline(char **str, char **line)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		if (!(*line = ft_strsub(*str, 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(*str + len + 1)))
			return (-1);
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*stch[MAX_FD];
	char			bfsz[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, bfsz, BUFF_SIZE)) > 0)
	{
		if (!(bfsz[ret] = '\0') && stch[fd] == NULL)
			stch[fd] = ft_strdup(bfsz);
		else
		{
			tmp = ft_strjoin(stch[fd], bfsz);
			stch[fd] ? free(stch[fd]) : 0;
			stch[fd] = tmp;
		}
		if (stch[fd] == NULL)
			return (-1);
		if (ft_strchr(stch[fd], '\n'))
			break ;
	}
	if (ret < 0 || stch[fd] == NULL)
		return (ret < 0 ? -1 : 0);
	return (ft_strline(&stch[fd], line));
}
