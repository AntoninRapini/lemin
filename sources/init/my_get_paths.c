/*
** my_get_path.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 23 19:03:39 2017 Antonin Rapini
** Last update Fri Apr 28 15:57:59 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

int my_comp_room(t_room *a, t_room *b)
{
  return (my_strcmp(a->name, b->name));
}

int my_go_forward(t_path **curr, int *iteration, int i)
{
  if ((*curr)->room->connections[i]->visited > *iteration ||
      (*curr)->room->connections[i]->visited == -1)
    {
      (*curr)->i = (*curr)->i + 1;
      (*curr)->room->connections[i]->visited = *iteration;
      my_free_path((*curr)->next);
      (*curr)->next = my_init_path((*curr)->room->connections[i]);
      (*curr)->next->previous = (*curr);
      (*curr) = (*curr)->next;
      (*iteration)++;
      return (1);
    }
  return (0);
}

void		my_go_back(t_path **curr, int *iteration)
{
  t_path	*tmp;

  if ((tmp = (*curr)->previous) != NULL)
    tmp->next = NULL;
  my_free_path((*curr));
  (*curr) = tmp;
  (*iteration)--;
}

void		my_get_paths(t_pathlist **pathlist, t_room *start, t_room *goal)
{
  t_path	*pathstart;
  t_path	*curr;
  int		iteration;

  iteration = 1;
  if ((pathstart = my_init_path(start)) == NULL)
    return ;
  start->visited = 0;
  curr = pathstart;
  while (curr != NULL)
    {
      while (curr->room->connections && curr->room->connections[curr->i])
	{
	  if (!my_comp_room(curr->room->connections[curr->i], goal))
	    {
	      my_add_path(pathlist, my_copy_path(pathstart, goal), iteration);
	      curr->i = curr->i + 1;
	    }
	  else if (!my_go_forward(&curr, &iteration, curr->i))
	    curr->i = curr->i + 1;
	}
      my_go_back(&curr, &iteration);
    }
}
