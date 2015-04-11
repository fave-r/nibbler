//
// Sdl.hh for SDL in /home/polydo_s/Epitech/cpp_nibbler/Graphic/SDL
// 
// Made by Swann Polydor
// Login   <polydo_s@epitech.net>
// 
// Started on  Fri Apr  3 16:16:37 2015 Swann Polydor
// Last update Sun Apr  5 19:10:16 2015 Romaric FAVE
//

#ifndef SDL_HH
#define SDL_HH

#include <iostream>
#include <string>
#include <map>
#include <SDL/SDL.h>
#include "IGraphic.hh"

#define CASE_SIZE (40)

class				SDL : public IGraphic {

private:
  SDL_Surface			*_screen;
  std::map<e_Type, Uint32>	_items;
  int				_width;
  int				_height;

public:
  SDL();
  virtual ~SDL();

public:
  bool				init(const int, const int);
  e_Key				getkey(const e_Key);
  void				draw(const std::list<AItem *> &, const int &);
};

extern "C" IGraphic		*getclass();

#endif
