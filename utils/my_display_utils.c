/*
** my_display_utils.c for minishell2 in /home/antonin.rapini/ModulesTek1/ShellProgramming/PSU_2016_minishell2/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Apr  3 15:14:08 2017 Antonin Rapini
** Last update Mon Apr  3 15:15:06 2017 Antonin Rapini
*/

#include <unistd.h>
#include "utils.h"

void	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while (nb/div >= 10)
    {
      div = div * 10;
    }
  while (div >= 1)
    {
      my_putchar((nb/div) + '0');
      nb = nb % div;
      div = div / 10;
    }
}

void	my_putstr(char *str)
{
  int	index;

  index = 0;
  while (str[index++]);
  write(1, str, index - 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
