/*
** my_get_path.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 23 19:03:39 2017 Antonin Rapini
** Last update Thu Apr 27 03:55:14 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

int my_room_cmp(t_room *a, t_room *b)
{
  return (my_strcmp(a->name, b->name));
}

int is_in_path(t_path *path, t_room *room)
{
  while (path != NULL)
    {
      if (my_room_cmp(path->room, room) == 0)
	return (1);
      path = path->next;
    }
  return (0);
}

int my_move_forward(t_path *start, t_path **curr, int i)
{
  if (!is_in_path(start, (*curr)->room->connections[i]))
    {
      (*curr)->i = (*curr)->i + 1;
      my_free_path((*curr)->next);
      (*curr)->next = my_init_path((*curr)->room->connections[i]);
      (*curr)->next->previous = (*curr);
      (*curr) = (*curr)->next;
      return (1);
    }
  return (0);
}

void		my_move_back(t_path **curr)
{
  t_path	*tmp;
  
  if ((tmp = (*curr)->previous) != NULL)
    tmp->next = NULL;
  my_free_path((*curr));
  (*curr) = tmp;
}

void		my_get_paths_all(t_pathlist **pathlist, t_room *start, t_room *goal)
{
  t_path	*pathstart;
  t_path	*curr;

  if ((pathstart = my_init_path(start)) == NULL)
    return ;
  start->visited = 0;
  curr = pathstart;
  while (curr != NULL)
    {
      while (curr->room->connections[curr->i])
	{
	  if (!my_room_cmp(curr->room->connections[curr->i], goal))
	    {
	      my_add_path(pathlist, my_copy_path(pathstart, goal), 0);
	      curr->i = curr->i + 1;
	    }
	  else if (!my_move_forward(pathstart, &curr, curr->i))
	    curr->i = curr->i + 1;
	}
      my_move_back(&curr);
    }
}
