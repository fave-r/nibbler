//
// GLib.hh for GLib in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 08:43:09 2015 Thibaut Lopez
// Last update Sun Apr  5 19:48:49 2015 Romaric FAVE
//

#ifndef	GLIB_HH
#define	GLIB_HH

#include "ALib.hpp"
#include "IGraphic.hh"

class	GLib : public ALib<IGraphic>
{
private:
  int			l;
  int			w;

public:
  GLib();
  virtual ~GLib();
  bool			loadNext();
  void			init(const int &, const int &, std::list<std::string> &);
  e_Key			getkey(const e_Key);
  void			draw(const std::list<AItem *> &, const int &);
};

#endif
