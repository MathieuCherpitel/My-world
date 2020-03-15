##
## EPITECH PROJECT, 2019
## emacs
## File description:
## Makefile for screensaver
##

SRC=	src/display/compute_line.c							\
		src/display/draw_line.c								\
		src/display/framebuffer.c							\
		src/display/pixel.c									\
		src/editor/draw_editor.c							\
		src/editor/inputs.c									\
		src/editor/map_computing.c 							\
		src/editor/check_hard_inputs.c						\
		src/editor/map_movement.c							\
		src/editor/altitude_tool.c							\
		src/editor/reset_tool.c								\
		src/editor/texture_tool.c 							\
		src/editor/tooltips.c 								\
		src/event/check_event.c								\
		src/hud/editor_scene/editor_button_handler.c 		\
		src/hud/editor_scene/editor_button_trigger.c 		\
		src/hud/editor_scene/editor_slider_handler.c		\
		src/hud/editor_scene/editor_slider_trigger.c		\
		src/hud/editor_scene/editor_tools_button_handler.c 	\
		src/hud/editor_scene/editor_tools_button_trigger.c 	\
		src/hud/load_map_scene/get_map_from_save.c 			\
		src/hud/load_map_scene/load_map_button_handler.c	\
		src/hud/load_map_scene/load_map_button_trigger.c	\
		src/hud/load_map_scene/parse_save_file.c 			\
		src/hud/new_scene/new_button_handler_2.c 			\
		src/hud/new_scene/new_button_handler.c 				\
		src/hud/new_scene/new_button_trigger_2.c			\
		src/hud/new_scene/new_button_trigger.c				\
		src/hud/utils/button.c 								\
		src/hud/utils/check_slider_button.c 				\
		src/hud/utils/create_rectangle_button.c 			\
		src/hud/utils/create_slide_button.c 				\
		src/hud/utils/create_sprite_button.c 				\
		src/hud/utils/create_text.c							\
		src/load/load_assets.c								\
		src/load/load_buttons.c 							\
		src/load/load_sprites.c 							\
		src/main_functions/free_scenes.c 					\
		src/main_functions/free_window_data.c 				\
		src/main_functions/game_loop.c 						\
		src/main_functions/main.c 							\
		src/main_functions/my_world.c 						\
		src/main_functions/state_machine.c					\
		src/main_functions/usage.c							\
		src/scenes/editor_scene/editor_buttons.c 			\
		src/scenes/editor_scene/editor_game_obj.c 			\
		src/scenes/editor_scene/editor_scene.c 				\
		src/scenes/load_map/load_map_buttons.c 				\
		src/scenes/load_map/load_map_scene.c 				\
		src/scenes/loading_scene/loading_scene.c 			\
		src/scenes/menu_scene/menu_buttons.c 				\
		src/scenes/menu_scene/menu_scene.c 					\
		src/scenes/new_scene/new_buttons.c 					\
		src/scenes/new_scene/new_game_obj.c 				\
		src/scenes/new_scene/new_scene.c 					\
		src/scenes/utils/create_scenes.c 					\
		src/scenes/utils/draw_scene.c 						\
		src/scenes/utils/draw_special.c						\


OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

CGRAPHFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-audio -g -lm

CFLAGS =	-Wall -Wextra -W -g -I./include

all:	$(NAME) $(TEST)

$(NAME):	$(OBJ)
	@make -s -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(CGRAPHFLAGS) $(OBJ) -L./lib/my -lmy

test:
	make
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	@make -s -C lib/my fclean

re:	fclean all
	@make -s -C lib/my re

.PHONY:	clean
