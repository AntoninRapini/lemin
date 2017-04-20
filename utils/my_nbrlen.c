/*
** my_nbrlen_base.c for my_nbrlen_base in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Nov 20 15:54:52 2016 Antonin Rapini
** Last update Thu Dec  1 13:34:50 2016 Antonin Rapini
*/

int	my_nbrlen(float nbr)
{
  float	div;
  int	negative;
  int	pass;

  pass = 1;
  negative = 0;
  div = 1;
  if (nbr < 0)
    {
      negative = 1;
      nbr = -nbr;
    }
  while (nbr / div >= 10)
    {
      div *= 10;
      pass++;
    }
  return (pass + negative);
}
