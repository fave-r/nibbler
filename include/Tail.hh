//
// Tail.hh for Tail in /home/lopez_t/cpp_nibbler/src
//
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
//
// Started on  Mon Mar 30 10:31:33 2015 Thibaut Lopez
// Last update Sun Apr  5 19:54:40 2015 Romaric FAVE
//

#ifndef	TAIL_HH
#define	TAIL_HH

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "IGraphic.hh"

class	Tail : public AItem
{
public:
  Tail(const int, const int);
  Tail(Tail const &);
  virtual ~Tail();
  virtual Tail const	&operator=(Tail const &);
  e_Effect		effect(Snake *) const;
};

#endif
