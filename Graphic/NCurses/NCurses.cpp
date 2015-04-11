//
// NCurses.cpp for NCurses in /home/lopez_t/cpp_nibbler/Graphic/NCurses
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Mar 27 08:38:06 2015 Thibaut Lopez
// Last update Sun Apr  5 19:22:16 2015 Romaric FAVE
//

#include "NCurses.hh"

NCurses::NCurses()
{
  initscr();
  if (has_colors() == FALSE)
    {
      endwin();
      throw std::runtime_error("Your terminal does not support color");
    }
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  curs_set(0);
  init_pair(EMPTY, COLOR_BLACK, COLOR_BLACK);
  init_pair(WALL, COLOR_BLACK, COLOR_WHITE);
  init_pair(HEAD, COLOR_RED, COLOR_RED);
  init_pair(TAIL, COLOR_GREEN, COLOR_GREEN);
  init_pair(FOOD, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(BONUS, COLOR_CYAN, COLOR_CYAN);
  nodelay(stdscr, TRUE);
}

NCurses::~NCurses()
{
  endwin();
}

bool		NCurses::init(const int _len, const int _wid)
{
  int		x;
  int		y;

  len = _len;
  wid = _wid;
  if (len > LINES - 2 || wid > COLS - 2)
    {
      std::cerr << "NCurses: your terminal is of size" << LINES << "x" << COLS << std::endl;
      std::cerr << "Please choose a smaller length and/or width" << std::endl;
      return (false);
    }
  x = 0;
  while (x < len + 2)
    {
      y = 0;
      while (y < wid + 2)
	{
	  if (x == 0 || y == 0 || x == len + 1 || y == wid + 1)
	    {
	      move(x, y);
	      attron(COLOR_PAIR(WALL));
	      addstr(" ");
	    }
	  y++;
	}
      x++;
    }
  attron(A_NORMAL);
  refresh();
  return (true);
}

e_Key		NCurses::getkey(const e_Key dir)
{
  int		key;
  e_Key		ret;

  ret = STRAIGHT;
  while (ret == STRAIGHT && (key = getch()) != ERR)
    {
      switch (key)
	{
	case 27:
	  ret = QUIT;
	  break;
	case '\t':
	  ret = TAB;
	  break;
	case 'm':
	  ret = MUSIC;
	  break;
	case 'M':
	  ret = MUSIC;
	  break;
	case KEY_UP:
	  if (dir > DOWN)
	    ret = UP;
	  break;
	case KEY_DOWN:
	  if (dir > DOWN)
	    ret = DOWN;
	  break;
	case KEY_LEFT:
	  if (dir <= DOWN)
	    ret = LEFT;
	  break;
	case KEY_RIGHT:
	  if (dir <= DOWN)
	    ret = RIGHT;
	  break;
	default:
	  break;
	}
    }
  return (ret);
}

void				NCurses::draw(const std::list<AItem *> &map, const int &score)
{
  std::list<AItem *>::const_iterator	it;
  int				x;
  int				y;
  std::stringstream		ss;

  getmaxyx(stdscr, y, x);
  if (len > x - 2 || wid > y - 2)
    {
      std::cerr << "NCurses: your terminal is of size" << LINES << "x" << COLS << std::endl;
      throw std::runtime_error("Please choose a smaller length and/or width");
    }
  attron(COLOR_PAIR(WALL));
  move(0, 0);
  ss << "Score: " << score;
  addstr(ss.str().c_str());
  x = 1;
  attron(COLOR_PAIR(EMPTY));
  while (x < len + 1)
    {
      move(x, 1);
      y = 1;
      while (y < wid + 1)
	{
	  addstr(" ");
	  y++;
	}
      x++;
    }
  it = map.begin();
  while (it != map.end())
    {
      move((*it)->getX() + 1, (*it)->getY() + 1);
      attron(COLOR_PAIR((*it)->getType()));
      addstr(" ");
      ++it;
    }
  refresh();
}

extern "C" IGraphic			*getclass()
{
  return (new NCurses());
}
