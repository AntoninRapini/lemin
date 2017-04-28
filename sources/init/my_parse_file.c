/*
** my_parse_file.c for lemin in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_Lemin/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Apr 15 15:22:01 2017 Antonin Rapini
** Last update Fri Apr 28 16:08:35 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils.h"
#include "sources.h"

int	my_is_comment(char *line)
{
  int	i;

  i = 0;
  while (line[i] == ' ')
    i++;
  return (line[i] == '#');
}

int	my_parse_antcount(int fd, int *antcount)
{
  char	*buffer;
  int	ret;

  while ((buffer = get_next_line(fd)) != NULL)
    {
      if (!my_is_comment(buffer))
	{
	  (*antcount) = my_getnbr(buffer, &ret);
	  free(buffer);
	  return (ret == -1);
	}
      free(buffer);
    }
  return (1);
}

int	my_parse_file(t_lemin *lemin)
{
  char	*buffer;

  buffer = NULL;
  if (my_parse_antcount(0, &(lemin->ants)))
    return (1);
  my_miniprintf("#number_of_ants\n%i\n", lemin->ants);
  if (my_parse_rooms(&buffer, 0, lemin))
    return (1);
  if (my_parse_tunnels(buffer, 0, lemin))
    return (1);
  return (0);
}
