//
// GLib.cpp for GLib in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 08:43:16 2015 Thibaut Lopez
// Last update Sun Apr  5 19:49:00 2015 Romaric FAVE
//

#include "GLib.hh"

GLib::GLib()
  : ALib("getclass")
{
}

GLib::~GLib()
{
}

void		GLib::init(const int &_l, const int &_w, std::list<std::string> &args)
{
  l = _l;
  w = _w;
  ALib::init(args);
}

bool		GLib::loadNext()
{
  bool		ret;

  ret = false;
  if (libNames.size() <= 1 && lib != NULL)
    return (true);
  while (ret == false)
    {
      try
	{
	  ALib::loadNext();
	  if (lib->init(l, w) == false)
	    throw std::runtime_error("Can't init");
	  ret = true;
	}
      catch (const std::runtime_error &err)
	{
	  std::cerr << err.what() << std::endl;
	  libNames.pop_front();
	  lib = NULL;
	  if (libNames.size() == 0)
	    return (false);
	}
    }
  return (ret);
}

e_Key		GLib::getkey(const e_Key dir)
{
  return (lib->getkey(dir));
}

void		GLib::draw(const std::list<AItem *> &list, const int &score)
{
  return (lib->draw(list, score));
}
