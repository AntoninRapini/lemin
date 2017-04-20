/*
** my_roomlist_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 16 00:05:46 2017 Antonin Rapini
** Last update Mon Apr 17 18:47:00 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"

void		*my_free_roomlist(t_roomlist *rooms)
{
  t_roomlist	*tmp;

  tmp = rooms;
  while (rooms != NULL)
    {
      rooms = rooms->next;
      my_free_room(tmp->room);
      free(tmp);
      tmp = rooms;
    }
  return (NULL);
}

int		my_add_to_roomlist(t_room *room, t_roomlist *room_list)
{
  t_roomlist	*item;

  if ((item = my_init_roomlist_item()) == NULL)
    return (1);
  item->room = room;
  if (room_list == NULL)
    room_list = item;
  else
    {
      while (room_list->next != NULL)
	room_list = room_list->next;
      room_list->next = item;
    }
  return (0);
}

t_roomlist	*my_init_roomlist_item()
{
  t_roomlist	*room;

  if ((room = malloc(sizeof(t_roomlist))) == NULL)
    return (NULL);
  room->room = NULL;
  room->next = NULL;
  return (NULL);
}
