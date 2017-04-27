/*
** my_remove_crossroads.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 27 04:40:33 2017 Antonin Rapini
** Last update Thu Apr 27 23:05:09 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "sources.h"
#include "utils.h"

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

void		my_remove_doubloons(t_pathlist *paths, t_path *path)
{
  t_pathlist	*curr;
  t_pathlist	*tmp;

  path = path->next;
  while (path->next != NULL)
    {
      curr = paths;
      while (curr && curr->next != NULL)
	{
	  if (has_room(curr->next->path, path->room))
	    {
	      tmp = curr->next;
	      curr->next = curr->next->next;
	      my_free_path(tmp->path);
	      free(tmp);
	    }
	  curr = curr->next;
	}
      path = path->next;
    }
}

void my_remove_crossroads(t_pathlist *paths)
{
  while (paths != NULL && paths->next != NULL)
    {
      my_remove_doubloons(paths, paths->path);
      paths = paths->next;
    }
}
