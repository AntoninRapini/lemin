/*
** my_path_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Apr 24 18:37:19 2017 Antonin Rapini
** Last update Tue Apr 25 04:26:52 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "utils.h"

void my_show_path(t_path *path)
{
  while (path != NULL)
    {
      my_miniprintf("%s ", path->room->name);
      path = path->next;
    }
}

void		*my_free_path(t_path *path)
{
  t_path	*tmp;

  while (path != NULL)
    {
      tmp = path;
      path = path->next;
      free(tmp);
    }
  return (NULL);
}

t_path		*my_init_path(t_room *room)
{
  t_path	*path;

  if ((path = malloc(sizeof(path))) == NULL)
    return (NULL);
  path->room = room;
  path->next = NULL;
  path->previous = NULL;
  return (path);
}

t_path		*my_copy_path(t_path *original)
{
  t_path	*new_start;
  t_path	*curr;

  if ((new_start = my_init_path(original->room)) == NULL)
    return (NULL);
  curr = new_start;
  original = original->next;
  while (original != NULL)
    {
      if ((curr->next = my_init_path(original->room)) == NULL)
	return (my_free_path(new_start));
      curr = curr->next;
      original = original->next;
    }
  return (new_start);
}
