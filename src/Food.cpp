//
// Food.cpp for nibbler in /home/fave_r/rendu/cpp_nibbler/src
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Wed Apr  1 14:41:22 2015 romaric
// Last update Thu Apr  2 19:29:52 2015 Thibaut Lopez
//

#include "Snake.hh"

Food::~Food()
{
}

e_Effect	Food::effect(Snake *snake) const
{
  snake->addSpeed(-10000);
  snake->addPoints(50);
  return (EAT);
}

AItem		*Food::collision(std::list<AItem*> &list, const int _x, const int _y)
{
  std::list<AItem *>::iterator   first = list.begin();
  std::list<AItem *>::iterator   last = list.end();

  while (first != last)
    {
      if ((*first)->getX() == _x && (*first)->getY() == _y)
        return (*first);
      ++first;
    }
  return (NULL);
}

void		Food::teleport(std::list<AItem *> &list, int x_max, int y_max)
{
  int	_x = 0;
  int	_y = 0;

  if (list.size() <= static_cast<unsigned int>(x_max * y_max))
    {
      _x = rand() % x_max;
      _y = rand() % y_max;
      while (collision(list, _x, _y) != NULL)
	{
	  if (_x == (x_max - 1) && _y == (y_max - 1))
	    {
	      _x = 0;
	      _y = 0;
	    }
	  else if (_x < (x_max - 1))
	    _x++;
	  else
	    {
	      _x = 0;
	      _y++;
	    }
	}
      this->x = _x;
      this->y = _y;
    }
}
