##
## Makefile for nibbler in /home/fave_r/rendu/cpp_nibbler
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Fri Mar 27 11:58:49 2015 romaric
## Last update Sun Apr  5 13:43:25 2015 Romaric FAVE
##

CXX=		g++

RM=		rm -f

G_DIR=		Graphic

CPPFLAGS=	-W -Wall -Wextra -I./include -ldl -std=c++11

SDL_FLAGS=	$(CPPFLAGS) -fPIC -lSDL -shared

NC_FLAGS=	$(CPPFLAGS) -fPIC -lncurses -shared

LX_FLAGS=	$(CPPFLAGS) -fPIC -shared -lXext -lX11 -L/usr/lib64/X11 -lm

M_FLAGS=	$(CPPFLAGS) -fPIC -shared

SRC=		src/AItem.cpp			\
		src/Food.cpp 			\
		src/main.cpp 			\
		src/Snake.cpp 			\
		src/Tail.cpp			\
		src/Bonus.cpp			\
		src/GLib.cpp			\
		src/SLib.cpp			\
		src/Wall.cpp			\
		src/Game.cpp

SDL_SRC=	src/AItem.cpp			\
		$(G_DIR)/SDL/Sdl.cpp

NC_SRC=		src/AItem.cpp 			\
		$(G_DIR)/NCurses/NCurses.cpp

LX_SRC=		src/AItem.cpp 			\
		$(G_DIR)/LX/LX.cpp

M_SRC=		Music/fmod/my_fmod.cpp

NAME=		nibbler

SDL_NAME=	$(G_DIR)/lib_nibbler_sdl.so

NC_NAME=	$(G_DIR)/lib_nibbler_ncurses.so

LX_NAME=	$(G_DIR)/lib_nibbler_lx.so

M_NAME= 	Music/lib_nibbler_fmod.so

OBJ=		$(SRC:.cpp=.o)

SDL_OBJ=	$(SDL_SRC:.cpp=.o)

NC_OBJ=		$(NC_SRC:.cpp=.o)

LX_OBJ=		$(LX_SRC:.cpp=.o)

M_OBJ=		$(M_SRC:.cpp=.o)

all:		$(NAME) $(SDL_NAME) $(NC_NAME) $(LX_NAME) $(M_NAME)

ncurse:		$(NAME) $(NC_NAME) $(M_NAME)

sdl:		$(NAME) $(SDL_NAME) $(M_NAME)

xlib:		$(NAME) $(LX_NAME) $(M_NAME)

wm_sdl:		$(NAME) $(SDL_NAME)

wm_ncurse:	$(NAME) $(NC_NAME)

wm_xlib:	$(NAME) $(NC_NAME)

$(SDL_NAME):	$(SDL_OBJ)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) -o $@ $(SDL_OBJ) $(SDL_FLAGS)

$(NC_NAME):	$(NC_OBJ)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) -o $@ $(NC_OBJ) $(NC_FLAGS)

$(LX_NAME):	$(LX_OBJ)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) -o $@ $(LX_OBJ) $(LX_FLAGS)

$(M_NAME):	$(M_OBJ)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) -o $@ $(M_OBJ) $(M_FLAGS) Music/fmod/libfmod/api/lib/libfmodex64.so

$(NAME):	$(OBJ)
		@echo -e "\033[32m[Building] \033[0m" | tr -d '\n'
		$(CXX) -o $@ $(OBJ) $(CPPFLAGS)

%.o:		%.cpp
		@echo -e "\033[33m[Doing object] \033[0m" | tr -d '\n'
		$(CC) $(CPPFLAGS) -fPIC -c -o $@ $<

clean:
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(OBJ)
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(SDL_OBJ)
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(NC_OBJ)
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(LX_OBJ)
		@echo -e "\033[31m[Cleaning] \033[0m" | tr -d '\n'
		$(RM) $(M_OBJ)

fclean:		clean
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(NAME)
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(SDL_NAME)
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(NC_NAME)
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(LX_NAME)
		@echo -e "\033[31m[Filecleaning] \033[0m" | tr -d '\n'
		$(RM) $(M_NAME)

re:		fclean all

.PHONY:		all fclean re
