/*
** my_pathlist_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Apr 21 19:47:01 2017 Antonin Rapini
** Last update Wed Apr 26 20:29:45 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

void	my_show_pathlist(t_pathlist *paths)
{
  while (paths != NULL)
    {
      my_show_path(paths->path);
      my_putchar('\n');
      paths = paths->next;
    }
}

void		*my_free_pathlist(t_pathlist *paths)
{
  t_pathlist	*tmp;

  while (paths != NULL)
    {
      tmp = paths;
      paths = paths->next;
      my_free_path(tmp->path);
      free(tmp);
    }
  return (NULL);
}

t_pathlist	*my_init_pathlist_item(t_path *path)
{
  t_pathlist	*item;

  if ((item = malloc(sizeof(t_pathlist))) == NULL)
    return (NULL);
  item->path = path;
  item->next = NULL;
  return (item);
}

void		my_add_path(t_pathlist **paths, t_path *path)
{
  t_pathlist	*new_path;

  if (path != NULL)
    {
      if ((new_path = my_init_pathlist_item(path)) != NULL)
	{
	  new_path->next = *paths;
	  (*paths) = new_path;
	}
    }
}

t_pathlist	*my_create_pathlist(t_lemin *lemin)
{
  t_pathlist	*pathlist;

  pathlist = NULL;
  my_get_paths(&pathlist, lemin->start, lemin->end);
  return (pathlist);
}
