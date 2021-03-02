##
## EPITECH PROJECT, 2020
## bistro
## File description:
## yannis.alouache@epitech.eu
##

SRC	= final_screen/draw_btn.c\
	final_screen/final_score.c\
	final_screen/final_screen.c\
	final_screen/final_txt.c\
	map_handler/check_map_char.c\
	map_handler/get_elem_nb.c\
	map_handler/map.c\
	map_handler/check_map_error.c\
	menu/menu.c\
	menu/text.c\
	menu/title.c\
	obstacle/draw_gato.c\
	obstacle/draw_ghost.c\
	obstacle/draw_obstacle.c\
	obstacle/draw_spike.c\
	obstacle/draw_tomb.c\
	parralax/draw_parralax.c\
	parralax/graveyard.c\
	parralax/init_parralax.c\
	parralax/mountain1.c\
	parralax/mountain2.c\
	player/collide_checker/check_collide_obstacle.c\
	player/collide_checker/collide_spike_tomb_ghost_gato.c\
	player/animation.c\
	player/hitbox.c\
	player/jump.c\
	player/player.c\
	player/win_or_loose.c\
	state_manager/game_manager.c\
	state_manager/loose_manager.c\
	state_manager/menu_manager.c\
	state_manager/state_manager.c\
	state_manager/win_manager.c\
	./camera.c\
	./create_obj.c\
	./grass.c\
	./init_app.c\
	./main.c\
	./music.c\
	./print_h.c\
	./score.c\
	./utilis.c\
	./window.c\

LIB_NAME = libmy.a
INC_NAME = my.h

NAME = my_runner

all: $(NAME)

$(NAME):
	make -C lib/my
	gcc $(SRC) -g -Wall -Wextra -Llib -lmy -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -I include -o $(NAME) -g

clean:
	rm -f *.o
	rm -f $(LIB_NAME)

fclean:
	make -C lib/my clean
	make clean
	rm -f $(NAME)

re:
	make -C lib/my fclean
	make -C lib/my all
	make fclean
	make all
	make clean
	make -C lib/my clean
