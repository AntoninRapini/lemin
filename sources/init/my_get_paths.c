/*
** my_get_path.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 23 19:03:39 2017 Antonin Rapini
** Last update Tue Apr 25 06:01:32 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

#include <stdio.h>

int my_comp_room(t_room *a, t_room *b)
{
  return (my_strcmp(a->name, b->name));
}

void		my_get_paths(t_pathlist **pathlist, t_room *start, t_room *goal)
{
  t_path	*pathstart;
  t_path	*curr;
  int		iteration;
  int		i;

  iteration = 1;
  if ((pathstart = my_init_path(start)) == NULL)
    return ;
  start->visited = 1;
  curr = pathstart;
  while (curr != NULL)
    {
      i = 0;
      while (curr->room->connections[i])
	{
	  if (!my_comp_room(curr->room->connections[i], goal))
	    {
	      curr->next = my_init_path(goal);
	      curr->next->previous = curr;
	      my_add_path(pathlist, my_copy_path(pathstart));
	    }
	  else if (curr->room->connections[i]->visited > iteration
		   || curr->room->connections[i]->visited == 0)
	    {
	      curr->room->connections[i]->visited = iteration;
	      iteration++;
	      my_free_path(curr->next);
	      curr->next = my_init_path(curr->room->connections[i]);
	      curr->next->previous = curr; 
	      curr = curr->next;
	      i = 0;
	      continue;
	    }
	  i++;
	}
      curr = curr->previous;
      if (curr != NULL)
	{
	  my_free_path(curr->next);
	  curr->next = NULL;
	}
      iteration--;
    }
}
