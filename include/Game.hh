//
// Game.hh for Game in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Apr  2 18:09:20 2015 Thibaut Lopez
// Last update Sun Apr  5 19:47:11 2015 Romaric FAVE
//

#ifndef	GAME_HH
#define	GAME_HH

#include <iostream>
#include <string>
#include "Snake.hh"
#include "GLib.hh"
#include "SLib.hh"
#include "Wall.hh"

class	Game
{
private:
  GLib			glib;
  SLib			slib;
  Snake			*snake;
  std::list<AItem *>	list;
  std::list<Bonus *>	bons;
  Food			*food;
  int			init_lib(const int, const int, std::list<std::string> &, std::list<std::string> &);
  void			bonus_timer(const int, const int);
  void			add_wall(const int, const int, const int);

public:
  Game();
  virtual ~Game();
  int			play(const int, const int, std::list<std::string> &, std::list<std::string> &);
};

#endif
