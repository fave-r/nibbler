//
// Sdl.cpp for nibler in /home/fave_r/rendu/cpp_nibbler/Graphic/SDL
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Fri Mar 27 11:37:31 2015 romaric
// Last update Sun Apr  5 19:09:20 2015 Romaric FAVE
//

#include "Sdl.hh"

SDL::SDL()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw std::runtime_error("Not possible to initialize SDL");
}

SDL::~SDL()
{
  SDL_Quit();
}

bool			SDL::init(const int width, const int height)
{
  const SDL_VideoInfo	*info;

  info = SDL_GetVideoInfo();
  if (width * CASE_SIZE > info->current_w || height * CASE_SIZE > info->current_h)
    {
      std::cerr << "Your screen resolution is not wide enough" << std::endl;
      return (false);
    }
  this->_screen = SDL_SetVideoMode(width * CASE_SIZE, height * CASE_SIZE, 32,
  				   SDL_SWSURFACE | SDL_DOUBLEBUF);
  if (this->_screen == NULL)
    {
      std::cerr << "Not possible to create the SDL Window" << std::endl;
      return (false);
    }
  this->_items[WALL] = SDL_MapRGB(this->_screen->format, 255, 255, 255);
  this->_items[HEAD] = SDL_MapRGB(this->_screen->format, 255, 0, 0);
  this->_items[TAIL] = SDL_MapRGB(this->_screen->format, 0, 255, 0);
  this->_items[FOOD] = SDL_MapRGB(this->_screen->format, 255, 255, 0);
  this->_items[BONUS] = SDL_MapRGB(this->_screen->format, 0, 255, 255);
  this->_items[EMPTY] = SDL_MapRGB(this->_screen->format, 0, 0, 0);
  this->_width = width;
  this->_height = height;
  return (true);
}

e_Key		SDL::getkey(const e_Key dir)
{
  SDL_Event	event;
  e_Key		ret;

  ret = STRAIGHT;
  while (SDL_PollEvent(&event))
    {
      switch(event.type)
	{
	case SDL_QUIT:
	  ret = QUIT;
	  break;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      ret = QUIT;
	      break;
	    case SDLK_m:
	      ret = MUSIC;
	      break;
	    case SDLK_TAB:
	      ret = TAB;
	      break;
	    case SDLK_UP:
	      if (dir > DOWN)
		ret = UP;
	      break;
	    case SDLK_DOWN:
	      if (dir > DOWN)
		ret = DOWN;
	      break;
	    case SDLK_LEFT:
	      if (dir <= DOWN)
		ret = LEFT;
	      break;
	    case SDLK_RIGHT:
	      if (dir <= DOWN)
		ret = RIGHT;
	      break;
	    default:
	      break;
	    }
	}
    }
  return (ret);
}

void				SDL::draw(const std::list<AItem *> &items, const int &score)
{
  std::list<AItem *>::const_iterator	it;
  SDL_Rect			rect;
  int				x;
  int				y;

  SDL_WM_SetCaption(std::string("Score : " + std::to_string(score)).c_str(), NULL);
  SDL_FillRect(this->_screen, NULL, EMPTY);
  it = items.begin();
  while (it != items.end())
    {
      y = ((*it)->getX() * CASE_SIZE);
      x = ((*it)->getY() * CASE_SIZE);
      rect.x = x;
      rect.y = y;
      rect.w = CASE_SIZE;
      rect.h = CASE_SIZE;
      SDL_FillRect(this->_screen, &rect, this->_items[((*it)->getType())]);
      ++it;
    }
  SDL_Flip(this->_screen);
}

extern "C" IGraphic	*getclass()
{
  return (new SDL());
}
