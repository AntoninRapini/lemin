/*
** my_getnbr.c for my_getnbr in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Nov 20 00:36:16 2016 Antonin Rapini
** Last update Fri Apr 28 21:34:48 2017 Antonin Rapini
*/

int my_getnbr_rec(char *str, int nbr, int init, int *ret)
{
  if (*str == '-')
    return (-my_getnbr_rec(str + 1, nbr, init, ret));
  else if (*str >= '0' && *str <= '9')
    return (my_getnbr_rec(str + 1, (nbr * 10) + (*str - 48), 1, ret));
  else if ((*str == '\0' || *str == ' ' || *str == '#') && init > 0)
      return (nbr);
  else
    {
      if (ret)
	(*ret) = -1;
      return (nbr);
    }
}

int my_getnbr(char *str, int *ret)
{
  if (ret)
    (*ret) = 0;
  return (my_getnbr_rec(str, 0, 0, ret));
}
