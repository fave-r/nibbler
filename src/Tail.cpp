//
// Tail.cpp for Tail in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Mar 30 10:31:37 2015 Thibaut Lopez
// Last update Sun Apr  5 19:54:43 2015 Romaric FAVE
//

#include "Tail.hh"

Tail::Tail(const int x, const int y)
  : AItem(x, y, TAIL)
{
}

Tail::Tail(Tail const &cpy)
  : AItem(cpy.getX(), cpy.getY(), TAIL)
{
}

Tail::~Tail()
{
}

Tail const	&Tail::operator=(Tail const &cpy)
{
  if (&cpy != this)
    {
      x = cpy.getX();
      y = cpy.getY();
      type = TAIL;
    }
  return (*this);
}

e_Effect	Tail::effect(Snake *snake) const
{
  (void)snake;
  return (KILL);
}
