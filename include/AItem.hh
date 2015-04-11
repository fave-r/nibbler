//
// AItem.hh for AItem in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Fri Mar 27 17:22:42 2015 Thibaut Lopez
// Last update Sun Apr  5 19:35:05 2015 Romaric FAVE
//

#ifndef	AITEM_HH
#define	AITEM_HH

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <limits>

enum e_Type
  {
    WALL = 1,
    HEAD,
    TAIL,
    FOOD,
    BONUS,
    EMPTY
  };

enum e_Effect
  {
    NOTHING,
    KILL,
    EAT,
    UPGRADE
  };

class	Snake;

class	AItem
{
protected:
  int		x;
  int		y;
  e_Type	type;

public:
  AItem(const int, const int, const e_Type);
  AItem(AItem const &);
  virtual ~AItem();
  virtual AItem const	&operator=(AItem const &);
  int			getX() const;
  void			setX(int);
  int			getY() const;
  void			setY(int);
  e_Type		getType() const;
  virtual e_Effect	effect(Snake *) const = 0;
};

#endif
