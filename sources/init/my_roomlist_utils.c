/*
** my_roomlist_utils.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Apr 16 00:05:46 2017 Antonin Rapini
** Last update Fri Apr 21 19:26:07 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

void	my_show_roomlist(t_roomlist *rooms)
{
  int	i;

  while (rooms != NULL)
    {
      i = 0;
      my_miniprintf("Name : %s PosX : %i PosY : %i Connections : ", rooms->room->name,
		    rooms->room->pos.x, rooms->room->pos.y);
      while (rooms->room->connections && rooms->room->connections[i])
	{
	  my_miniprintf("%s ", rooms->room->connections[i]->name);
	  i++;
	}
      my_miniprintf("\n");
      rooms = rooms->next;
    }
}
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

int		my_add_to_roomlist(t_room *room, t_roomlist **room_list)
{
  t_roomlist	*item;
  t_roomlist	*start;

  start = (*room_list);
  if ((item = my_init_roomlist_item()) == NULL)
    return (1);
  item->room = room;
  if ((*room_list) == NULL)
    (*room_list) = item;
  else
    {
      while ((*room_list)->next != NULL)
	(*room_list) = (*room_list)->next;
      (*room_list)->next = item;
      (*room_list) = start;
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
  return (room);
}
