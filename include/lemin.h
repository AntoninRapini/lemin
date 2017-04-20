/*
** my_map.h for lem_in in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Apr 13 17:07:23 2017 Antonin Rapini
** Last update Mon Apr 17 18:42:53 2017 Antonin Rapini
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <stdbool.h>
#include "vector2.h"

# define START_STR "##start"
# define END_STR "##end"

typedef struct	s_room
{
  char		*name;
  t_vector2	pos;
  struct s_room	**connections;
  bool		passed_through;
}		t_room;

typedef struct	s_path
{
  char		*name;
  struct s_path	*next;
  bool		has_ant;
}		t_path;

typedef struct		s_roomlist
{
  t_room		*room;
  struct s_roomlist	*next;
}			t_roomlist;

typedef	struct		s_pathlist
{
  t_path		*path;
  struct s_pathlist	*next;
}			t_pathlist;

typedef struct	s_lemin
{
  int		ants;
  t_pathlist	*paths;
  t_roomlist	*rooms;
  t_room	*start;
  t_room	*end;
}		t_lemin;

#endif /* !LEMIN_H_ */
