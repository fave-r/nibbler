//
// Snake.cpp for Snake in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Fri Mar 27 17:02:06 2015 Thibaut Lopez
// Last update Sun Apr  5 20:00:55 2015 Romaric FAVE
//

#include "Snake.hh"

Snake::Snake(const int _x, const int _y, std::list<AItem*> &list)
  : AItem(_x / 2, _y / 2 + 2, HEAD), xmax(_x), ymax(_y), points(0), speed(200000), dir(RIGHT)
{
  pushBack(new Tail(x, y - 1), list);
  pushBack(new Tail(x, y - 2), list);
  pushBack(new Tail(x, y - 3), list);
}

Snake::~Snake()
{
}

e_Effect	Snake::effect(Snake *snake) const
{
  (void)snake;
  return (NOTHING);
}

int		Snake::getSpeed() const
{
  return (speed);
}

void		Snake::addSpeed(const int _speed)
{
  speed += _speed;
  if (speed < 0)
    speed = 0;
}

void		Snake::mulSpeed(const int _speed)
{
  if (_speed <= 0)
    return ;
  speed *= _speed;
}

void		Snake::divSpeed(const int _speed)
{
  if (_speed <= 0)
    return ;
  speed /= _speed;
}

int		Snake::getPoints() const
{
  return (points);
}

void		Snake::addPoints(const int _points)
{
  points += _points;
  if (points < 0)
    points = 0;
}

int		Snake::getLen() const
{
  return (tails.size());
}

void		Snake::pushBack(AItem *to_add, std::list<AItem *> &list)
{
  tails.push_back(dynamic_cast<Tail *>(to_add));
  list.push_back(to_add);
}

void		Snake::move_snake(int &oldx, int &oldy)
{
  std::list<Tail *>::iterator	first;
  std::list<Tail *>::iterator	last;
  int		tmpx;
  int		tmpy;

  first = tails.begin();
  last = tails.end();
  while (first != last)
    {
      tmpx = (*first)->getX();
      tmpy = (*first)->getY();
      (*first)->setX(oldx);
      (*first)->setY(oldy);
      oldx = tmpx;
      oldy = tmpy;
      ++first;
    }
}

AItem		*Snake::collision(std::list<AItem*> &list)
{
  std::list<AItem *>::iterator	first = list.begin();
  std::list<AItem *>::iterator	last = list.end();

  while (first != last)
    {
      if ((*first)->getX() == x && (*first)->getY() == y && (*first)->getType() != HEAD)
	return (*first);
      ++first;
    }
  return (NULL);
}

void		Snake::popBonus(std::list<AItem*> &list, std::list<Bonus *> &bons, AItem *col)
{
  std::list<AItem *>::iterator	ita = list.begin();
  std::list<Bonus *>::iterator	itb = bons.begin();

  while (ita != list.end() && (*ita) != col)
    ++ita;
  while (itb != bons.end() && (*itb) != dynamic_cast<Bonus *>(col))
    ++itb;
  delete col;
  list.erase(ita);
  bons.erase(itb);
}

bool		Snake::goForward(std::list<AItem*> &list, GLib &glib, SLib &slib, std::list<Bonus *> &bons)
{
  e_Key		key;
  e_Effect	eff;
  AItem		*col;
  int		oldx;
  int		oldy;

  usleep(speed);
  key = glib.getkey(dir);
  if (key == QUIT)
    return (false);
  else if (key == MUSIC)
    {
      if (slib.loadNext() == false)
	return (false);
    }
  else if (key != STRAIGHT && key != TAB)
    dir = key;
  oldx = this->x;
  oldy = this->y;
  x = (dir == UP) ? x - 1 : (dir == DOWN) ? x + 1 : x;
  y = (dir == LEFT) ? y - 1 : (dir == RIGHT) ? y + 1 : y;
  if (x < 0 || x >= xmax || y < 0 || y >= ymax)
    {
      std::cout << "Game over" << std::endl;
      return (false);
    }
  move_snake(oldx, oldy);
  col = collision(list);
  if (col != NULL)
    {
      eff = col->effect(this);
      if (eff == KILL)
	{
	  std::cout << "Game over" << std::endl;
	  return (false);
	}
      else if (eff == EAT)
	{
	  pushBack(new Tail(oldx, oldy), list);
	  dynamic_cast<Food *>(col)->teleport(list, xmax, ymax);
	}
      else if (eff == UPGRADE)
	popBonus(list, bons, col);
    }
  if (key == TAB)
    if (glib.loadNext() == false)
      return (false);
  try
    {
      glib.draw(list, points);
    }
  catch (const std::runtime_error &err)
    {
      std::cerr << err.what() << std::endl;
      return (false);
    }
  return (true);
}
