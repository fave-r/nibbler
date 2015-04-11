//
// my_fmod.hpp for nibbler in /home/fave_r/rendu/cpp_nibbler/Music/fmod
// 
// Made by Romaric FAVE
// Login   <fave_r@epitech.net>
// 
// Started on  Sat Apr  4 18:37:02 2015 Romaric FAVE
// Last update Sun Apr  5 13:15:43 2015 Thibaut Lopez
//

#ifndef	FMOD_HPP
#define	FMOD_HPP

#include <iostream>
#include <string>
#include "ISound.hh"
#include "fmod.h"

class	MY_FMOD : public ISound
{
private:
  FMOD_SYSTEM *system;
  FMOD_SOUND *musique;
  FMOD_CHANNEL *channel;
  FMOD_RESULT resultat;

public:
  MY_FMOD();
  virtual ~MY_FMOD();
  bool          init();
  void		play(std::string const &);
};

extern "C" ISound	*getclass();

#endif
