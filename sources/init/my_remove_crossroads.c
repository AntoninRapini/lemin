/*
** my_remove_crossroads.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 27 04:40:33 2017 Antonin Rapini
** Last update Fri Apr 28 22:15:58 2017 Antonin Rapini
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

void		my_remove_doubloons(t_pathlist *paths, t_path *ref)
{
  t_pathlist	*curr;

  ref = ref->next;
  while (ref->next != NULL)
    {
      curr = paths->next;
      while (curr != NULL)
	{
	  if (has_room(curr->path, ref->room))
	    {
	      paths->next = curr->next;
	      my_free_path(curr->path);
	      free(curr);
	      curr = paths->next;
	    }
	  else
	    {
	      paths = curr;
	      curr = curr->next;
	    }
	}
      ref = ref->next;
    }
}

void my_remove_crossroads(t_pathlist *paths)
{
  while (paths != NULL)
    {
      my_remove_doubloons(paths, paths->path);
      paths = paths->next;
    }
}
