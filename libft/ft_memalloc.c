/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:45:34 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:17:15 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mall;

	if (!size)
		return (0);
	mall = (unsigned char *)malloc(size);
	if (mall)
	{
		ft_bzero(mall, size);
		return ((void *)mall);
	}
	else
		return (0);
}
