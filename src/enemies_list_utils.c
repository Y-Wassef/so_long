/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:20:37 by jwadie-a          #+#    #+#             */
/*   Updated: 2024/01/06 16:20:38 by jwadie-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_enemy	*list_get_last(t_enemy *list);

void	append_to_enemy_list(t_enemy **list, int x, int y, int direction)
{
	t_enemy	*last;
	t_enemy	*new;

	new = malloc(sizeof(t_enemy));
	new->position = (t_point){x, y};
	new->destination = get_enemy_destination(new->position, direction);
	new->status = IDLE;
	new->offset = 0;
	new->direction = direction;
	if (direction == UP || direction == RIGHT)
		new->orientation = RIGHT;
	else
		new->orientation = LEFT;
	new->counter = 0;
	new->next = NULL;
	last = list_get_last(*list);
	if (last == NULL)
		*list = new;
	else
		last->next = new;
}

t_point	get_enemy_destination(t_point point, int direction)
{
	t_point	destination;

	destination.x = point.x;
	destination.y = point.y;
	if (direction == UP)
		destination.y = point.y - 1;
	else if (direction == DOWN)
		destination.y = point.y + 1;
	else if (direction == RIGHT)
		destination.x = point.x + 1;
	else if (direction == LEFT)
		destination.x = point.x - 1;
	return (destination);
}

static t_enemy	*list_get_last(t_enemy *list)
{
	t_enemy	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	clear_enemy_list(t_enemy **list)
{
	t_enemy	*current_node;
	t_enemy	*next_node;

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
