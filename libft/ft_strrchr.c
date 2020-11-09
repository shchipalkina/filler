/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:13:21 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:20:02 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;
	char	*find;

	len_s = ft_strlen(s);
	find = (char *)(s + len_s);
	len_s += 1;
	while (len_s--)
	{
		if (*find == (unsigned char)c)
			return (find);
		find--;
	}
	return (0);
}
