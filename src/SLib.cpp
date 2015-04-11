//
// SLib.cpp for SLib in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 08:43:16 2015 Thibaut Lopez
// Last update Sun Apr  5 19:52:45 2015 Romaric FAVE
//

#include "SLib.hh"

SLib::SLib()
  : ALib("getsound")
{
}

SLib::~SLib()
{
}

void		SLib::init(const std::list<std::string> &args)
{
  ALib::init(args);
}

bool		SLib::loadNext()
{
  bool		ret;

  ret = false;
  if (libNames.size() == 0)
    return (true);
  if (libNames.size() <= 1 && lib != NULL)
    return (true);
  while (ret == false)
    {
      try
	{
	  ALib::loadNext();
	  if (lib->init() == false)
	    throw std::runtime_error("Can't init");
	  ret = true;
	}
      catch (const std::runtime_error &err)
	{
	  std::cerr << err.what() << std::endl;
	  libNames.pop_front();
	  lib = NULL;
	  if (libNames.size() == 0)
	    ret = true;
	}
    }
  play();
  return (ret);
}

void		SLib::play() const
{
  if (lib != NULL)
    lib->play(DIR_MUSIC);
}
