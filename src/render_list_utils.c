/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:35 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:38 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_render	*list_get_last(t_render *list);

void	append_to_render(t_game *game, t_point point)
{
	t_render	*last;
	t_render	*new;

	new = malloc(sizeof(t_render));
	new->point = point;
	new->next = NULL;
	last = list_get_last(game->points_to_render);
	if (last == NULL)
		game->points_to_render = new;
	else
		last->next = new;
	game->render = TRUE;
}

static t_render	*list_get_last(t_render *list)
{
	t_render	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	clear_render_list(t_render **list)
{
	t_render	*current_node;
	t_render	*next_node;

	if (*list == NULL)
		return ;
	current_node = *list;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*list = NULL;
}

void	clear_node(t_render **list, t_render *node)
{
	t_render	*previous_node;

	if (*list == NULL)
		return ;
	if (node == *list)
		*list = node->next;
	else
	{
		previous_node = *list;
		while (previous_node->next != node)
			previous_node = previous_node->next;
		previous_node->next = node->next;
	}
	free(node);
}
