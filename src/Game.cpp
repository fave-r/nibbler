//
// Game.cpp for Game in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Apr  2 18:09:24 2015 Thibaut Lopez
// Last update Sun Apr  5 19:47:09 2015 Romaric FAVE
//

#include "Game.hh"

Game::Game()
{
  srand(time(NULL));
}

Game::~Game()
{
}

int		Game::init_lib(const int l, const int w, std::list<std::string> &glibNames
			       , std::list<std::string> &slibNames)
{
  glib.init(l, w, glibNames);
  slib.init(slibNames);
  if (glib.loadNext() == false)
    return (1);
  return (0);
}

void		Game::bonus_timer(const int l, const int w)
{
  std::list<AItem *>::iterator	ita;
  std::list<Bonus *>::iterator	itb;
  std::list<Bonus *>::iterator	itmp;
  Bonus				*new_bon;

  itb = bons.begin();
  while (itb != bons.end())
    {
      itmp = itb;
      ++itmp;
      if ((*itb)->decStep() == false)
	{
	  ita = list.begin();
	  while (ita != list.end() && dynamic_cast<Bonus*>(*ita) != (*itb))
	    ita++;
	  delete (*itb);
	  bons.erase(itb);
	  list.erase(ita);
	}
      itb = itmp;
    }
  if (rand() % 100 <= 5)
    {
      new_bon = new Bonus(list, l, w);
      bons.push_back(new_bon);
      list.push_back(new_bon);
    }
}

void		Game::add_wall(const int l, const int w, int nbWall)
{
  int		i;
  Wall		*wall;

  i = 0;
  while (i < nbWall)
    {
      wall = new Wall(list, l, w);
      list.push_back(wall);
      i++;
    }
}

int		Game::play(const int l, const int w, std::list<std::string> &glibNames
			   , std::list<std::string> &slibNames)
{
  if (init_lib(l, w, glibNames, slibNames) == 1)
    return (1);
  snake = new Snake(l, w, list);
  list.push_back(snake);
  food = new Food(list, l, w);
  list.push_back(food);
  add_wall(l, w, (l + w) / 2);
  while (snake->goForward(list, glib, slib, bons) == true)
    {
      bonus_timer(l, w);
    }
  while (list.size() > 0)
    {
      delete list.front();
      list.pop_front();
    }
  return (0);
}
