/*
** my_remove_path.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 27 02:44:56 2017 Antonin Rapini
** Last update Thu Apr 27 03:30:44 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "utils.h"
#include "sources.h"

int has_room(t_path *path, t_room *room)
{
  while (path != NULL)
    {
      if (my_strcmp(path->room->name, room->name) == 0)
	return (1);
      path = path->next;
    }
  return (0);
}

void		my_remove_path(t_pathlist **paths, t_room *room)
{
  t_pathlist	*curr;
  t_pathlist	*tmp;

  curr = (*paths);
  if (has_room(curr->path, room))
    {
      (*paths) = (*paths)->next;
      my_free_path(curr->path);
      free(curr);
      return ;
    }
  while (curr->next != NULL)
    {
      if (has_room(curr->next->path, room))
	{
	  tmp = curr->next;
	  curr->next = curr->next->next;
	  my_free_path(tmp->path);
	  free(tmp);
	  return ;
	}
      curr = curr->next;
    }
}
