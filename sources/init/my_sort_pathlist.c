/*
** my_sort_pathlist.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 27 03:56:04 2017 Antonin Rapini
** Last update Thu Apr 27 04:29:43 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"

void		my_swap_paths(t_pathlist *a, t_pathlist *b)
{
  int		tmp_size;
  t_path	*tmp_path;

  tmp_path = a->path;
  tmp_size = a->size;
  a->path = b->path;
  a->size = b->size;
  b->path = tmp_path;
  b->size = tmp_size;
}

void		my_sort_pathlist(t_pathlist **paths)
{
  t_pathlist	*curr;
  int		sorted;

  sorted = 0;
  if (*paths != NULL)
    {
      while (!sorted)
	{
	  curr = (*paths);
	  sorted = 1;
	  while (curr->next != NULL)
	    {
	      if (curr->size > curr->next->size)
		{
		  my_swap_paths(curr, curr->next);
		  sorted = 0;
		}
	      curr = curr->next;
	    }
	}
    }
}
