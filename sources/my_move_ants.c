/*
** my_move_ants.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Apr 26 21:21:14 2017 Antonin Rapini
** Last update Fri Apr 28 16:07:14 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "utils.h"
#include "sources.h"

void my_move_ants_on_path(int *ants_arrived, t_path *path)
{
  while (path->next != NULL)
    path = path->next;
  while (path->previous != NULL)
    {
      if (path->room->ant != 0)
	{
	  my_miniprintf("P%i-%s ", path->room->ant, path->next->room->name);
	  if (path->next->next != NULL)
	    path->next->room->ant = path->room->ant;
	  else
	    (*ants_arrived)++;
	  path->room->ant = 0;
	}
      path = path->previous;
    }
}

void		my_place_ants
(int *ants_left, t_pathlist *paths, int ants, int *ants_arrived)
{
  t_pathlist	*start;

  start = paths;
  while (paths != NULL && *ants_left)
    {
      if (paths->path->next->room->ant == 0)
	{
	  if (paths->path->next->next == NULL)
	    {
	      (*ants_left)--;
	      (*ants_arrived)++;
	      paths->path->next->room->ant = 0;
	      my_miniprintf("P%i-%s ", ants - (*ants_left),
			    paths->path->next->room->name);
	    }
	  else if (paths->size - (*ants_left) < start->size)
	    {
	      (*ants_left)--;
	      paths->path->next->room->ant = ants - (*ants_left);
	      my_miniprintf("P%i-%s ", paths->path->next->room->ant,
			    paths->path->next->room->name);
	    }
	}
      paths = paths->next;
    }
}

void	my_play_round(int *ants_arrived, t_pathlist *paths)
{
  while (paths != NULL)
    {
      my_move_ants_on_path(ants_arrived, paths->path);
      paths = paths->next;
    }
}

void	my_move_ants(t_lemin *lemin)
{
  int	ants_left;
  int	ants_arrived;

  ants_left = lemin->ants;
  ants_arrived = 0;
  my_putstr("#moves\n");
  while (ants_arrived < lemin->ants)
    {
      my_play_round(&ants_arrived, lemin->paths);
      my_place_ants(&ants_left, lemin->paths, lemin->ants, &ants_arrived);
      my_putchar('\n');
    }
}
