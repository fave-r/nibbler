//
// Snake.hh for Snake in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Fri Mar 27 17:01:58 2015 Thibaut Lopez
// Last update Sun Apr  5 20:00:53 2015 Romaric FAVE
//

#ifndef	SNAKE_HH
#define	SNAKE_HH

#include <iostream>
#include <string>
#include "GLib.hh"
#include "SLib.hh"
#include "Food.hpp"
#include "Bonus.hh"

class	Snake : public AItem
{
private:
  int			xmax;
  int			ymax;
  int			points;
  int			speed;
  e_Key			dir;
  std::list<Tail *>	tails;
  void			pushBack(AItem *, std::list<AItem *> &);
  void			move_snake(int &, int &);
  AItem			*collision(std::list<AItem*> &);
  void			popBonus(std::list<AItem*> &, std::list<Bonus *> &, AItem *);

public:
  Snake(const int, const int, std::list<AItem*> &);
  virtual ~Snake();
  e_Effect		effect(Snake *) const;
  int			getSpeed() const;
  void			addSpeed(const int);
  void			mulSpeed(const int);
  void			divSpeed(const int);
  int			getPoints() const;
  void			addPoints(const int);
  int			getLen() const;
  bool			goForward(std::list<AItem*> &, GLib &, SLib &, std::list<Bonus*> &);
};

#endif
