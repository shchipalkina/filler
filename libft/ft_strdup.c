/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 05:19:44 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/10 18:31:59 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*rez;
	int		l;
	char	*str;

	str = (char *)src;
	l = ft_strlen(src);
	if (!(rez = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (*str)
	{
		*rez = *str;
		rez++;
		str++;
	}
	*rez = '\0';
	rez = rez - l;
	return (rez);
}
