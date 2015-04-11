//
// IGraphic.hh for IGraphic in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Mar 26 10:56:30 2015 Thibaut Lopez
// Last update Sun Apr  5 19:10:39 2015 Romaric FAVE
//

#ifndef	IGRAPHIC_HH
#define	IGRAPHIC_HH

#include <iostream>
#include <string>
#include <stdexcept>
#include "AItem.hh"

enum e_Key
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    TAB,
    MUSIC,
    QUIT,
    STRAIGHT
  };

class	IGraphic
{
public:
  virtual ~IGraphic(){};
  virtual bool	init(const int, const int) = 0;
  virtual e_Key	getkey(const e_Key) = 0;
  virtual void	draw(const std::list<AItem *> &, const int &) = 0;
};

#endif
