/*
** my_parse_file.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 15 15:22:01 2017 Antonin Rapini
** Last update Fri Apr 28 15:58:48 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils.h"
#include "sources.h"

void *my_free_room(t_room *room)
{
  if (room != NULL)
    {
      if (room->name != NULL)
	free(room->name);
      if (room->connections != NULL)
	free(room->connections);
      free(room);
    }
  return (NULL);
}

t_room		*my_init_room()
{
  t_room	*room;

  if ((room = malloc(sizeof(t_room))) == NULL)
    return (NULL);
  room->name = NULL;
  room->pos.x = 0;
  room->pos.y = 0;
  room->connections = NULL;
  room->visited = -1;
  room->ant = 0;
  return (room);
}

t_room		*my_getroom(char *buffer)
{
  t_room	*room;
  int		i;
  int		ret;

  i = 0;
  if ((room = my_init_room()) == NULL)
    return (NULL);
  while (buffer[i] && buffer[i] != ' ')
    i++;
  if (buffer[i] == ' ')
    {
      if ((room->name = my_strndup(buffer, i)))
	{
	  i++;
	  room->pos.x = my_getnbr(buffer + i, &ret);
	  if (ret != -1)
	    {
	      i += my_nbrlen(room->pos.x) + 1;
	      room->pos.y = my_getnbr(buffer + i, &ret);
	      if (ret != -1)
		return (room);
	    }
	}
    }
  return (my_free_room(room));
}

int		my_add_room
(t_room *room, t_lemin *lemin, int *is_start, int *is_end)
{
  t_roomlist	*item;

  if ((*is_start))
    {
      if (lemin->start != NULL)
	return (1);
      lemin->start = room;
      (*is_start) = 0;
      my_putstr("##start\n");
    }
  else if ((*is_end))
    {
      if (lemin->end != NULL)
	return (1);
      lemin->end = room;
      (*is_end) = 0;
      my_putstr("##end\n");
    }
  if ((item = my_init_roomlist_item()) == NULL)
    return (1);
  my_miniprintf("%s %i %i\n", room->name, room->pos.x, room->pos.y);
  item->room = room;
  item->next = lemin->rooms;
  lemin->rooms = item;
  return (0);
}

int		my_parse_rooms(char **buffer, int fd, t_lemin *lemin)
{
  int		is_start;
  int		is_end;
  t_room	*curr;

  is_start = 0;
  is_end = 0;
  my_putstr("#rooms\n");
  while (((*buffer) = get_next_line(fd)) != NULL)
    {
      if (my_strcmp((*buffer), START_STR) == 0)
	is_start = 1;
      else if (my_strcmp((*buffer), END_STR) == 0)
	is_end = 1;
      else if (!my_is_comment((*buffer)))
	{
	  if ((curr = my_getroom((*buffer))) == NULL)
	    return (0);
	  if (my_add_room(curr, lemin, &is_start, &is_end))
	    return (1);
	}
      free((*buffer));
    }
  return (0);
}
