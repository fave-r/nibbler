//
// AItem.cpp for AItem in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Fri Mar 27 17:22:49 2015 Thibaut Lopez
// Last update Sun Apr  5 19:35:08 2015 Romaric FAVE
//

#include "AItem.hh"

AItem::AItem(const int _x, const int _y, const e_Type _type)
  : x(_x), y(_y), type(_type)
{
}

AItem::AItem(AItem const &cpy)
  : x(cpy.getX()), y(cpy.getY()), type(cpy.getType())
{
}

AItem::~AItem()
{
}

AItem const	&AItem::operator=(AItem const &cpy)
{
  if (&cpy != this)
    {
      x = cpy.getX();
      y = cpy.getY();
      type = cpy.getType();
    }
  return (*this);
}

int		AItem::getX() const
{
  return (x);
}

void		AItem::setX(int _x)
{
  x = _x;
}	

int		AItem::getY() const
{
  return (y);
}

void		AItem::setY(int _y)
{
  y = _y;
}	

e_Type		AItem::getType() const
{
  return (type);
}
