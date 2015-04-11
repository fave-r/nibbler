//
// Wall.cpp for Wall in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 14:24:14 2015 Thibaut Lopez
// Last update Sun Apr  5 19:55:36 2015 Romaric FAVE
//

#include "Wall.hh"

Wall::Wall(std::list<AItem *> &list, const int x_max, const int y_max)
  : AItem(0, 0, WALL)
{
  teleport(list, x_max, y_max);
}

Wall::Wall(Wall const &cpy)
 : AItem(cpy.getX(), cpy.getY(), WALL)
{
}

Wall::~Wall()
{
}

e_Effect	Wall::effect(Snake *snake) const
{
  (void)snake;
  return (KILL);
}

AItem		*Wall::collision(std::list<AItem*> &list, const int _x, const int _y)
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

void		Wall::teleport(std::list<AItem *> &list, int x_max, int y_max)
{
  int	_x = 0;
  int	_y = 0;

  if (list.size() <= static_cast<unsigned int>(x_max * y_max))
    {
      _x = rand() % x_max;
      if (_x == x_max / 2)
	_x++;
      _y = rand() % y_max;
      while (collision(list, _x, _y) != NULL)
	{
	  if (_x == (x_max - 1) && _y == (y_max - 1))
	    {
	      _x = 0;
	      _y = 0;
	    }
	  else if (_x < (x_max - 1))
	    _x += (_x + 1 == x_max / 2) ? 2 : 1;
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
