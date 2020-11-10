/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:27:43 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/10 18:48:01 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_best_move(int *pos, int oldx, int oldy, int *dir)
{
	int		old;
	int		new;

	new = ft_abs(dir[0] - pos[0]) + ft_abs(dir[1] - pos[1]);
	old = ft_abs(dir[0] - oldx) + ft_abs(dir[1] - oldy);
	return ((new > old));
}

int			*max_distance(t_filler *game, int mi_x, int mi_y)
{
	int		*ret;
	int		x;
	int		y;

	x = 0;
	ret = malloc(sizeof(int) * 2);
	while (game->mapa[x])
	{
		y = 0;
		while (game->mapa[x][y])
		{
			if (game->mapa[x][y] == '.')
				if (is_best_move((int[]){x, y}, ret[0], ret[1],
										(int[]) {mi_x, mi_y}))
				{
					ret[0] = x;
					ret[1] = y;
				}
			y++;
		}
		x++;
	}
	return (ret);
}

static void	init_params(int *count, int *x, int *y)
{
	*count = 0;
	*x = 0;
	*y = 0;
}

int			*get_best_direction(t_filler *game, int my_x, int my_y)
{
	int	count;
	int x;
	int y;

	init_params(&count, &x, &y);
	while (game->mapa[x])
	{
		while (game->mapa[x][y])
		{
			if (game->mapa[x][y] == game->my ||
				game->mapa[x][y] == ft_toupper(game->my))
			{
				my_x += x;
				my_y += y;
				count++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	my_x /= count;
	my_y /= count;
	return (max_distance(game, my_x, my_y));
}

void		make_move(t_filler *game, t_list *moves)
{
	t_list	*head;
	int		x;
	int		y;
	int		*dir;

	dir = get_best_direction(game, 0, 0);
	x = ((int *)(moves->content))[0];
	y = ((int *)(moves->content))[1];
	head = moves;
	while (moves)
	{
		if (!is_best_move(moves->content, x, y, dir))
		{
			x = ((int *)(moves->content))[0];
			y = ((int *)(moves->content))[1];
		}
		moves = moves->next;
	}
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
	free(head);
}
