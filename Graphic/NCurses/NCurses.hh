//
// NCurses.hh for NCurses in /home/lopez_t/cpp_nibbler/Graphic/NCurses
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Fri Mar 27 08:37:59 2015 Thibaut Lopez
// Last update Sun Apr  5 19:09:27 2015 Romaric FAVE
//

#ifndef	NCURSES_HH
#define	NCURSES_HH

#include <iostream>
#include <string>
#include <ncurses.h>
#include <sstream>
#include "IGraphic.hh"
#include <map>

class	NCurses : public IGraphic
{
private:
  int			len;
  int			wid;
public:
  NCurses();
  virtual ~NCurses();
  bool		init(const int, const int);
  e_Key		getkey(const e_Key);
  void		draw(const std::list<AItem *> &, const int &);
};

extern "C" IGraphic	*getclass();

#endif
