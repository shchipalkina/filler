/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:09:09 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:20:13 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s)
	{
		j = ft_strlen(s);
		if (j)
		{
			j -= 1;
			while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i <= j)
				i++;
			while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && i <= j)
				j--;
		}
		return (ft_strsub(s, i, j - i + 1));
	}
	return (0);
}
