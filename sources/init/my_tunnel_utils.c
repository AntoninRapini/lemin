/*
** my_tunnel_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Apr 17 17:14:24 2017 Antonin Rapini
** Last update Wed Apr 26 21:20:15 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "lemin.h"
#include "utils.h"
#include "sources.h"

int		my_add_connection(t_room *room1, t_room *new_connection)
{
  int		i;
  t_room	**connections;

  i = 0;
  while (room1->connections && room1->connections[i] != NULL)
    {
      if (my_strcmp(new_connection->name, room1->connections[i]->name) == 0)
	return (0);
      i++;
    }
  if ((connections = malloc(sizeof(t_room *) * (i + 2))) == NULL)
    return (1);
  i = 0;
  while (room1->connections && room1->connections[i] != NULL)
    {
      connections[i] = room1->connections[i];
      i++;
    }
  connections[i] = new_connection;
  connections[i + 1] = NULL;
  if (room1->connections)
    free(room1->connections);
  room1->connections = connections;
  return (0);
}

t_room		*my_find_room(char *name, int size, t_roomlist *rooms)
{
  int		check;

  while (rooms != NULL)
    {
      if ((check = size == 0 ?
	   my_strcmp(name, rooms->room->name) :
	   my_strncmp(name, rooms->room->name, size)) == 0)
	{
	  return (rooms->room);
	}
      rooms = rooms->next;
    }
  return (NULL);
}

int		my_add_tunnel(char *buffer, t_lemin *lemin)
{
  int		i;
  t_room	*room1;
  t_room	*room2;

  i = 0;
  while (buffer[i] && buffer[i] != '-')
    i++;
  if (!buffer[i])
    return (1);
  if ((room1 = my_find_room(buffer, i, lemin->rooms)) == NULL)
    return (1);
  i++;
  if ((room2 = my_find_room(buffer + i, 0, lemin->rooms)) == NULL)
    return (1);
  if (my_strcmp(room1->name, room2->name) == 0)
    return (0);
  my_miniprintf("%s-%s\n", room1->name, room2->name);
  my_add_connection(room1, room2);
  my_add_connection(room2, room1);
  return (0);
}

int	my_parse_tunnels(char *buffer, int fd, t_lemin *lemin)
{
  int	err;

  my_putstr("#tunnels\n");
  err = 0;
  if (buffer != NULL)
    {
      if (!my_is_comment(buffer))
	err = my_add_tunnel(buffer, lemin);
      free(buffer);
    }
  while (!err && (buffer = get_next_line(fd)) != NULL)
    {
      if (!my_is_comment(buffer))
	err = my_add_tunnel(buffer, lemin);
      free(buffer);
    }
  return (err);
}
