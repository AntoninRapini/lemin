/*
** lem_in.c for lem_in in /home/antonin.rapini/ModulesTek1/ProgElem/my_Lemin
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 13 15:33:06 2017 Antonin Rapini
** Last update Thu Apr 27 21:14:46 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "sources.h"

int		 main(void)
{
  t_lemin	*lemin;

  if ((lemin = my_create_lemin()) != NULL)
    {
      my_move_ants(lemin);
      my_free_lemin(lemin);
      return (0);
    }
  return (84);
}
