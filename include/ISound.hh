//
// ISound.hh for ISound in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Sat Apr  4 14:01:53 2015 Thibaut Lopez
// Last update Sun Apr  5 19:51:18 2015 Romaric FAVE
//

#ifndef	ISOUND_HH
#define	ISOUND_HH

#include <iostream>
#include <string>
#include <stdexcept>

class	ISound
{
public:
  virtual ~ISound(){};
  virtual bool	init() = 0;
  virtual void	play(const std::string &) = 0;
};

#endif
