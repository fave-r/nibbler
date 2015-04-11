//
// main.cpp for nibbler in /home/fave_r/rendu/cpp_nibbler
//
// Made by romaric
// Login   <fave_r@epitech.net>
//
// Started on  Mon Mar 30 11:47:38 2015 romaric
// Last update Sat Apr  4 21:08:48 2015 Thibaut Lopez
//

#include "Game.hh"

int				getDim(int &l, int &w, std::string lstr, std::string wstr)
{
  std::stringstream		sl;
  std::stringstream		sw;

  sl.str(lstr);
  sl >> l;
  if (!sl)
    {
      if (std::numeric_limits<int>::max() == l)
	{
	  std::cerr << "lenght too big" << std::endl;
	  return (1);
	}
      else if (std::numeric_limits<int>::min() != l)
	{
	  std::cerr << "invalid first argument" << std::endl;
	  return (1);
	}
    }
  if (l < 10)
    {
      std::cerr << "lenght too small" << std::endl;
      return (1);
    }
  sw.str(wstr);
  sw >> w;
  if (!sw)
    {
      if(std::numeric_limits<int>::max() == w)
	{
	  std::cerr << "width too big" << std::endl;
	  return (1);
	}
      else if (std::numeric_limits<int>::min() != w)
	{
	  std::cerr << "invalid second argument" << std::endl;
	  return (1);
	}
    }
  if (w < 10)
    {
      std::cerr << "width too small" << std::endl;
      return (1);
    }
  return (0);
}

bool				getLibs(std::list<std::string> &glib, std::list<std::string> &slib, char **argv)
{
  int				i;
  std::string			gop("-g");
  std::string			sop("-s");

  i = 0;
  while (argv[i] != NULL)
    {
      while (argv[i] != NULL && gop.compare(argv[i]) == 0)
	i++;
      while (argv[i] != NULL && sop.compare(argv[i]) != 0)
	{
	  glib.push_back(argv[i]);
	  i++;
	  while (argv[i] != NULL && gop.compare(argv[i]) == 0)
	    i++;
	}
      while (argv[i] != NULL && sop.compare(argv[i]) == 0)
	i++;
      while (argv[i] != NULL && gop.compare(argv[i]) != 0)
	{
	  slib.push_back(argv[i]);
	  i++;
	  while (argv[i] != NULL && sop.compare(argv[i]) == 0)
	    i++;
	}
      if (argv[i] != NULL)
	i++;
    }
  if (glib.size() == 0)
    {
      std::cerr << "You need at least 1 graphic library" << std::endl;
      return (false);
    }
  return (true);
}

int				main(int ac, char **av)
{
  int				l;
  int				w;
  std::list<std::string>	glib;
  std::list<std::string>	slib;
  Game				game;

  if (ac < 4)
    {
      std::cerr << "usage : ./nibbler lenght width [-g] glib.so [-m [mlib.so]]" << std::endl;
      return (1);
    }
  if (getDim(l, w, av[1], av[2]) == 1)
    return (1);
  if (getLibs(glib, slib, av + 3) == false)
    return (1);
  return (game.play(w, l, glib, slib));
}
