/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 05:20:21 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:17:33 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_new;
	unsigned char *src_new;

	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	if (dst_new == src_new)
		return (dst);
	while (n-- > 0)
		*(dst_new++) = *(src_new++);
	return (dst);
}
