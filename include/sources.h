/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Thu Apr 27 21:12:50 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "lemin.h"

int my_parse_file(t_lemin *);
int my_parse_antcount(int, int *);
int my_is_comment(char *);
void my_remove_crossroads(t_pathlist *);

// Algo
void my_move_ants(t_lemin *lemin);

// Lemin utils
t_lemin *my_create_lemin();
t_lemin *my_init_lemin();
void	*my_free_lemin(t_lemin *);
void	my_show_lemin(t_lemin *);

// Rooms utils
int	my_parse_rooms(char **, int, t_lemin *);
int	my_addroom(t_room*, t_lemin *, int *, int *);
t_room	*my_getroom(char *);
t_room	*my_init_room();
void	*my_free_room(t_room *);

// Roomlist utils
t_roomlist *my_init_roomlist_item();
int	my_add_to_roomlist(t_room *, t_roomlist **);
void	*my_free_roomlist(t_roomlist *);
void	my_show_roomlist(t_roomlist *, t_room *, t_room *);

// Tunnel utils
int	my_add_connection(t_room *, t_room *);
t_room	*my_find_room(char *, int, t_roomlist *);
int	my_add_tunnel(char *, t_lemin *);
int	my_parse_tunnels(char *, int, t_lemin *);

// Find paths
int my_comp_room(t_room *, t_room *);
int my_can_follow(t_path *, int, t_path *);
void my_get_paths(t_pathlist **, t_room *, t_room *);
void my_get_paths_all(t_pathlist **, t_room *, t_room *);

// Path utils
t_path *my_init_path(t_room *);
t_path *my_copy_path(t_path *, t_room *);
void *my_free_path(t_path *);
void my_show_path(t_path *);

// Pathlist utils
t_pathlist *my_create_pathlist(t_lemin *);
t_pathlist *my_init_pathlist_item(t_path *);
void my_add_path(t_pathlist **, t_path *, int);
void *my_free_pathlist(t_pathlist *);
void my_show_pathlist(t_pathlist *);
void my_remove_path(t_pathlist **, t_room *);
void my_sort_pathlist(t_pathlist **);

#endif /* !SOURCES_H_ */
