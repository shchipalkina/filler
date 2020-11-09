/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:31:58 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 18:42:04 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_filler *game, int x, int y, int *placed)
{
	if (x < 0 || y < 0 || x >= game->x || y >= game->y)
		return (0);
	else if (game->mapa[x][y] == game->enemy ||
			game->mapa[x][y] == ft_toupper(game->enemy))
		return (0);
	else if (*placed && (game->mapa[x][y] == game->my ||
			game->mapa[x][y] == ft_toupper(game->my)))
		return (0);
	else if (game->mapa[x][y] == game->my ||
			game->mapa[x][y] == ft_toupper(game->my))
		*placed = 1;
	return (1);
}

int		place_piece(t_filler *game, int top_x, int top_y)
{
	int		placed;
	int		x;
	int		y;

	x = 0;
	y = 0;
	placed = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (!check(game, top_x + x, top_y + y, &placed))
					return (0);
			y++;
		}
		x++;
	}
	if (placed == 0)
		return (0);
	return (1);
}

int		*is_valid_move(t_filler *game, int i, int j)
{
	int	*ret;
	int x;
	int y;

	ret = malloc(sizeof(int) * 2);
	x = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (place_piece(game, i - x, j - y))
				{
					ret[0] = i - x;
					ret[1] = j - y;
					return (ret);
				}
			y++;
		}
		x++;
	}
	return (NULL);
}

t_list	*get_legal_moves(t_filler *game)
{
	t_list	*moves;
	int		x;
	int		y;
	int		*ret;

	moves = NULL;
	x = 0;
	while (x < game->x)
	{
		y = 0;
		while (y < game->y && game->mapa[x][y])
		{
			if ((ret = is_valid_move(game, x, y)))
			{
				ft_lstadd(&moves, ft_lstnew((int[]) {ret[0], ret[1]}, 8));
				free(ret);
				ret = NULL;
			}
			y++;
		}
		x++;
	}
	return (moves);
}

int			play(t_filler *game)
{
    t_list	*moves;
	
	get(game);
    moves = get_legal_moves(game);
    if (!moves)
    {
        write(1, "0 0 \n", 4);
        exit (1);
    }
	make_move(game, moves);
	free_array(&(game->mapa));
	free_array(&(game->piece));
	return (1);
}
