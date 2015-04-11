//
// ALib.hpp for ALib in /home/lopez_t/cpp_nibbler
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Fri Apr  3 08:43:09 2015 Thibaut Lopez
// Last update Sun Apr  5 19:36:22 2015 Romaric FAVE
//

#ifndef	ALIB_HH
#define	ALIB_HH

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include "DLLoader.hpp"

template <typename T>
class	ALib
{
protected:
  DLLoader<T *>			loader;
  std::list<std::string>	libNames;
  T				*lib;
  std::string			getName;

public:
  ALib(std::string const &toGet)
    : lib(NULL), getName(toGet)
  {
  }

  virtual ~ALib()
  {
    if (lib != NULL)
      {
	delete lib;
	loader.close();
      }
  }

  void				init(const std::list<std::string> &args)
  {
    libNames = args;
  }

  void				loadNext()
  {
    std::list<std::string>::iterator	it;

    if (libNames.size() == 0)
      return ;
    if (libNames.size() == 1 && lib != NULL)
      return ;
    it = libNames.begin();
    ++it;
    if (lib != NULL)
      {
	delete lib;
	loader.close();
	std::rotate(libNames.begin(), it, libNames.end());
      }
    lib = loader.getInstance(libNames.front(), getName.c_str());
  }
};

#endif
