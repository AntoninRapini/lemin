/*
** disp_stdarg.c for disp_stdarg in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_printf_bootstrap
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov  8 15:51:15 2016 Antonin Rapini
** Last update Fri Apr 21 19:32:16 2017 Antonin Rapini
*/

#include "my_miniprintf.h"

static t_format const formats[] =
  {
    {'i', 0},
    {'c', 1},
    {'s', 2},
    {'\0', -1},
  };

void my_print(va_list *list, int id)
{
  if (id == 0)
    my_put_nbr(va_arg(*list, int));
  else if (id == 1)
    my_putchar(va_arg(*list, int));
  else if (id == 2)
    my_putstr(va_arg(*list, char *));
}

int	my_call_printfnc(va_list *list, char *s)
{
  int	i;

  i = 0;
  while (formats[i].key)
    {
      if (formats[i].key == *(s + 1))
	{
	  my_print(list, formats[i].id);
	  return (2);
	}
      i++;
    }
  my_putchar(*s);
  return (1);
}

int		my_miniprintf(char *s, ...)
{
  va_list	list;

  va_start(list, s);
  while (*s)
    {
      if (*s == '%' && *(s + 1))
	s += my_call_printfnc(&list, s);
      else
	{
	  my_putchar(*s);
	  s++;
	}
    }
  va_end(list);
  return (0);
}
