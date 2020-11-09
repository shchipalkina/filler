/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 03:01:07 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:19:15 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			size;
	size_t			i;
	char			*mall;

	mall = 0;
	if (s)
	{
		size = ft_strlen(s);
		mall = (char *)malloc(sizeof(char) * (size + 1));
		if (f && mall)
		{
			i = 0;
			while (i < size)
			{
				mall[i] = (*f)(s[i]);
				i++;
			}
			mall[i] = '\0';
		}
	}
	return (mall);
}
