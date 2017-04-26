/*
** lem_in.c for lem_in in /home/antonin.rapini/ModulesTek1/ProgElem/my_Lemin
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 13 15:33:06 2017 Antonin Rapini
** Last update Wed Apr 26 20:26:22 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "sources.h"

#include <stdio.h>

int		 main(void)
{
  t_lemin	*lemin;

  if ((lemin = my_create_lemin()) != NULL)
    {
      my_show_lemin(lemin);
      my_free_lemin(lemin);
      return (0);
    }
  return (84);
}
