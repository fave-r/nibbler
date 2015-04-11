//
// Bonus.cpp for Bonus in /home/lopez_t/cpp_nibbler/src
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Apr  2 16:30:17 2015 Thibaut Lopez
// Last update Sun Apr  5 19:38:23 2015 Romaric FAVE
//

#include "Snake.hh"

Bonus::Bonus(std::list<AItem *> &list, const int xmax, const int ymax)
  : AItem(0, 0, BONUS)
{
  teleport(list, xmax, ymax);
  bonus = static_cast<e_Bonus>(rand() % 3);
  step = (xmax + ymax) / 2;
}

Bonus::Bonus(Bonus const &cpy)
  : AItem(cpy.getX(), cpy.getY(), BONUS)
{
}

Bonus::~Bonus()
{
}

e_Bonus		Bonus::getBonus() const
{
  return (bonus);
}

int		Bonus::getStep() const
{
  return (step);
}

bool		Bonus::decStep()
{
  step--;
  if (step <= 0)
    return (false);
  return (true);
}

e_Effect	Bonus::effect(Snake *snake) const
{
  if (bonus == POINTS)
    snake->addPoints(1000);
  else if (bonus == LSPEED)
    snake->mulSpeed(2);
  else
    snake->divSpeed(2);
  return (UPGRADE);
}

AItem		*Bonus::collision(std::list<AItem*> &list, const int _x, const int _y)
{
  std::list<AItem *>::iterator	first;
  std::list<AItem *>::iterator	last;

  first = list.begin();
  last = list.end();
  while (first != last)
    {
      if ((*first)->getX() == _x && (*first)->getY() == _y)
        return (*first);
      ++first;
    }
  return (NULL);
}

void		Bonus::teleport(std::list<AItem *> &list, int xmax, int ymax)
{
  int		_x;
  int		_y;

  _x = 0;
  _y = 0;
  if (list.size() <= static_cast<unsigned int>(xmax * ymax))
    {
      _x = rand() % xmax;
      _y = rand() % ymax;
      while (collision(list, _x, _y) != NULL)
	{
	  if (_x == (xmax - 1) && _y == (ymax - 1))
	    {
	      _x = 0;
	      _y = 0;
	    }
	  else if (_x < (xmax - 1))
	    _x++;
	  else
	    {
	      _x = 0;
	      _y++;
	    }
	}
      x = _x;
      y = _y;
    }
}
