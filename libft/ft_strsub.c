/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:27:55 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:20:11 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*mall;

	if (s)
	{
		mall = (char *)malloc(sizeof(char) * (len + 1));
		if (mall)
		{
			ft_memcpy(mall, (s + start), len);
			mall[len] = 0;
			return (mall);
		}
	}
	return (0);
}
