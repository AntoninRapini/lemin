/*
** my_strcnmp.c for my_strncmp in /home/antonin.rapini/CPool_Day06/tests
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 10 10:19:01 2016 Antonin Rapini
** Last update Mon Apr 17 18:18:19 2017 Antonin Rapini
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
