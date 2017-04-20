/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Mon Apr 17 18:52:27 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "lemin.h"

int my_parse_file(t_lemin *);
int my_parse_antcount(int, int *);
int my_is_comment(char *);

// Lemin
t_lemin *my_create_lemin();
t_lemin *my_init_lemin();
void	*my_free_lemin(t_lemin *);

// Rooms
int	my_parse_rooms(char *, int, t_lemin *);
int	my_addroom(t_room*, t_lemin *, int *, int *);
t_room	*my_getroom(char *);
t_room	*my_init_room();
void	*my_free_room(t_room *);

// Roomlist
t_roomlist *my_init_roomlist_item();
int	my_add_to_roomlist(t_room *, t_roomlist *);
void	*my_free_roomlist(t_roomlist *);

// Tunnel
int my_add_connection(t_room *, t_room *);
t_room *my_find_room(char *, int, t_roomlist *);
int my_add_tunnel(char *, t_lemin *);
int my_parse_tunnels(char *, int, t_lemin *);

#endif /* !SOURCES_H_ */
