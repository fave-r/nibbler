//
// Food.hpp for nibbler in /home/fave_r/rendu/cpp_nibbler/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Mar 30 16:54:31 2015 romaric
// Last update Sun Apr  5 19:40:43 2015 Romaric FAVE
//

#ifndef	FOOD_HH
#define	FOOD_HH

#include <iostream>
#include <string>
#include "Tail.hh"

class	Food : public AItem
{
private:
  AItem		*collision(std::list<AItem*> &list, const int _x, const int _y);
public:
  Food(std::list<AItem *> &list, const int x_max, const int y_max)
    : AItem(0, 0, FOOD)
  {
    teleport(list, x_max, y_max);
  }
  Food(Food const &cpy) : AItem(cpy.getX(), cpy.getY(), FOOD) {};
  ~Food();
  e_Effect	effect(Snake *) const;
  void		teleport(std::list<AItem *> &list, const int x_max, const int y_max);
};

#endif
