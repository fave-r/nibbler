//
// Wall.hh for Wall in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 14:24:27 2015 Thibaut Lopez
// Last update Sun Apr  5 19:55:48 2015 Romaric FAVE
//

#ifndef	WALL_HH
#define	WALL_HH

#include <iostream>
#include <string>
#include "Tail.hh"

class	Wall : public AItem
{
private:
  AItem		*collision(std::list<AItem*> &, const int, const int);
public:
  Wall(std::list<AItem *> &, const int, const int);
  Wall(Wall const &);
  ~Wall();
  e_Effect	effect(Snake *) const;
  void		teleport(std::list<AItem *> &, const int, const int);
};

#endif
