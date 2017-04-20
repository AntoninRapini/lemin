/*
** utils.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:39 2017 Antonin Rapini
** Last update Tue Apr 18 01:11:03 2017 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

# define READ_SIZE 1048

char *get_next_line(const int);
int my_getnbr(char *, int *);
int my_strcmp(char *, char *);
int my_strncmp(char *, char *, int);
int my_nbrlen(int);
char *my_strndup(char *, int);

#endif /* !UTILS_H_ */
