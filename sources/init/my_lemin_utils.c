/*
** my_lemin_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 15 15:12:42 2017 Antonin Rapini
** Last update Mon Apr 17 18:45:22 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "sources.h"

void *my_free_lemin(t_lemin *lemin)
{
  if (lemin != NULL)
    {
      /*     if (lemin->paths != NULL)
	my_free_pathlist(lemin->paths);*/
      if (lemin->rooms != NULL)
	my_free_roomlist(lemin->rooms);
      if (lemin->start != NULL)
	my_free_room(lemin->start);
      if (lemin->end != NULL)
	my_free_room(lemin->end);
      free(lemin);
    }
  return (NULL);
}

t_lemin		*my_init_lemin()
{
  t_lemin	*lemin;

  if ((lemin = malloc(sizeof(t_lemin))) == NULL)
    return (NULL);
  lemin->ants = 0;
  lemin->paths = NULL;
  lemin->rooms = NULL;
  lemin->start = NULL;
  lemin->end = NULL;
  return (lemin);
}

t_lemin		*my_create_lemin()
{
  t_lemin	*lemin;

  if ((lemin = my_init_lemin()) == NULL)
    return (NULL);
  if (my_parse_file(lemin))
    return (my_free_lemin(lemin));
  return (lemin);
}
