##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Fri Apr 21 19:04:07 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include -g3

SRC	=	sources/init/my_lemin_utils.c		\
		sources/init/my_parse_file.c		\
		sources/init/my_roomlist_utils.c	\
		sources/init/my_room_utils.c		\
		sources/init/my_tunnel_utils.c		\
		utils/my_display_utils.c		\
		utils/my_miniprintf.c			\
		utils/get_next_line.c			\
		utils/my_getnbr.c			\
		utils/my_nbrlen.c			\
		utils/my_strcmp.c			\
		utils/my_strncmp.c			\
		utils/my_strndup.c			\
		lem_in.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	lem_in

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
