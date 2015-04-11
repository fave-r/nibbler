//
// SLib.hh for SLib in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 08:43:09 2015 Thibaut Lopez
// Last update Sun Apr  5 19:52:49 2015 Romaric FAVE
//

#ifndef	SLIB_HH
#define	SLIB_HH
#define	DIR_MUSIC	"Music/music.mp3"

#include "ALib.hpp"
#include "ISound.hh"

class	SLib : public ALib<ISound>
{
public:
  SLib();
  virtual ~SLib();
  void			init(const std::list<std::string> &);
  bool			loadNext();
  void			play() const;
};

#endif
