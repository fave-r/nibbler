//
// LX.cpp for nibbler in /home/fave_r/rendu/cpp_nibbler/Graphic/LX
//
// Made by Romaric FAVE
// Login   <fave_r@epitech.net>
//
// Started on  Fri Apr  3 17:09:44 2015 Romaric FAVE
// Last update Sun Apr  5 21:23:36 2015 Romaric FAVE
//

#include "LX.hpp"

LX::LX()
{
}

bool            LX::init(const int len, const int wid)
{
  this->_wid = wid;
  this->_len = len;
  if ((this->display = XOpenDisplay(NULL)) == NULL)
      throw std::runtime_error("Not possible to initialize xlib");

  this->screen = DefaultScreen(this->display);
  this->root = RootWindow(this->display, this->screen);
  this->white_pixel = WhitePixel(this->display, this->screen);
  this->black_pixel = BlackPixel(this->display, this->screen);
  this->win = XCreateSimpleWindow(this->display, this->root, 0, 0, (this->_wid + 2) * 20, (this->_len + 2) * 20, 2, black_pixel, white_pixel);

  XMapWindow(this->display, this->win);
  colormap = DefaultColormap(display, 0);

  this->green = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#00FF00", &this->pgreen);
  XAllocColor(this->display, this->colormap, &this->pgreen);
  XSetForeground(this->display, this->green, pgreen.pixel);

  this->red = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#ff0000", &this->pred);
  XAllocColor(this->display, this->colormap, &this->pred);
  XSetForeground(this->display, this->red, pred.pixel);

  this->white = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#FFFFFF", &this->pwhite);
  XAllocColor(this->display, this->colormap, &this->pwhite);
  XSetForeground(this->display, this->white, pwhite.pixel);

  this->black = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#000000", &this->pblack);
  XAllocColor(this->display, this->colormap, &this->pblack);
  XSetForeground(this->display, this->black, pblack.pixel);

  this->cyan = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#00ffff", &this->pcyan);
  XAllocColor(this->display, this->colormap, &this->pcyan);
  XSetForeground(this->display, this->cyan, pcyan.pixel);

  this->yellow = XCreateGC(this->display, this->win, 0, 0);
  XParseColor(display, colormap, "#ffff00", &this->pyellow);
  XAllocColor(this->display, this->colormap, &this->pyellow);
  XSetForeground(this->display, this->yellow, pyellow.pixel);


  XSelectInput(this->display, this->win, ExposureMask | KeyPressMask | StructureNotifyMask);

  draw_square(20, 20, this->_wid * 20, this->_len * 20, black);
  XFlush(this->display);

  return true;
}

void    LX::draw_square(const int x1, const int y1, const int x2, const int y2, const GC color)
{
  XDrawRectangle(this->display, this->win, color, x1, y1, x2, y2);
  XFillRectangle(this->display, this->win, color, x1, y1, x2, y2);
}

LX::~LX()
{
  XDestroyWindow(this->display, this->win);
  XCloseDisplay(this->display);
}

e_Key		LX::getkey(const e_Key dir)
{
  e_Key         ret;

  ret = STRAIGHT;
  while (ret == STRAIGHT && XEventsQueued(this->display, QueuedAlready) != 0)
    {
      XNextEvent(this->display, &report);
      switch  (report.type)
        {
	case DestroyNotify:
	  ret = QUIT;
	  break;
        case KeyPress:
	  switch (XLookupKeysym(&report.xkey, 0))
	    {
	    case XK_Escape:
	      ret = QUIT;
	      break;
	    case XK_Tab:
	      ret = TAB;
	      break;
	    case 'm':
	      ret = MUSIC;
	      break;
	    case 'M':
	      ret = MUSIC;
	      break;
	    case XK_Up:
              if (dir > DOWN)
                ret = UP;
              break;
            case XK_Down:
              if (dir > DOWN)
                ret = DOWN;
              break;
            case XK_Left:
              if (dir <= DOWN)
                ret = LEFT;
              break;
            case XK_Right:
              if (dir <= DOWN)
                ret = RIGHT;
              break;
            default:
              break;
	    }
          break;
        }
    }
  return ret;
}

void	LX::draw(const std::list<AItem *> &map, const int &score)
{
  std::list<AItem *>::const_iterator	it;
  int				x;
  int				y;
  std::stringstream		ss;

  draw_square(20, 20, this->_wid * 20, this->_len * 20, black);
  it = map.begin();
  ss << "Score: " << score;
  XStoreName(this->display, this->win, ss.str().c_str());
  while (it != map.end())
    {
      y = ((*it)->getX() * 20) + 20;
      x = ((*it)->getY() * 20) + 20;
      switch((*it)->getType())
	{
	case WALL :
	  draw_square(x, y, 20, 20, white);
	  break;
	case HEAD :
	  draw_square(x, y, 20, 20, red);
	  break;
	case TAIL :
	  draw_square(x, y, 20, 20, green);
	  break;
	case FOOD :
	  draw_square(x, y, 20, 20, yellow);
	  break;
	case BONUS :
	  draw_square(x, y, 20, 20, cyan);
	  break;
	default :
	  break;
	}
      ++it;
    }
  XFlush(this->display);
}

extern "C" IGraphic			*getclass()
{
  return (new LX());
}
