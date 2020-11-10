/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 02:53:05 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/10 18:33:23 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	long	m;
	long	nb;

	nb = n;
	m = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	while (nb / (m * 10) > 0)
		m = m * 10;
	while (m > 0)
	{
		ft_putchar((nb / m + '0'));
		nb = nb % m;
		m = m / 10;
	}
}
