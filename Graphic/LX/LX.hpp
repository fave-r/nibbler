//
// LX.hpp for nibbler in /home/fave_r/rendu/cpp_nibbler/Graphic/LX
//
// Made by Romaric FAVE
// Login   <fave_r@epitech.net>
//
// Started on  Fri Apr  3 17:03:33 2015 Romaric FAVE
// Last update Sun Apr  5 19:31:10 2015 Romaric FAVE
//

#ifndef	LX_HH
#define	LX_HH

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/keysym.h>
#include "IGraphic.hh"

class	LX : public IGraphic
{
private:
  int		       _len;
  int		       _wid;
  Display	       *display;
  int		       screen;
  Window	       win, root;
  unsigned long	       white_pixel, black_pixel;
  Colormap	       colormap;
  GC		       green;
  GC		       red;
  GC		       white;
  GC		       black;
  GC		       cyan;
  GC		       yellow;
  XColor               pgreen;
  XColor               pred;
  XColor               pwhite;
  XColor               pblack;
  XColor               pcyan;
  XColor               pyellow;
  XEvent	       report;
  void		       draw_square(const int, const int, const int, const int, const GC);
public:
  LX();
  virtual ~LX();
  bool		       init(const int, const int);
  e_Key		       getkey(const e_Key);
  void		       draw(const std::list<AItem *> &, const int &);
};

extern "C" IGraphic    *getclass();

#endif
