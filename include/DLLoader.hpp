//
// DLLoader.hpp for nibbler in /home/polydo_s/Epitech/cpp_nibbler/tp
// 
// Made by Swann Polydor
// Login   <polydo_s@epitech.net>
// 
// Started on  Wed Apr  1 13:23:57 2015 Swann Polydor
// Last update Fri Apr  3 17:49:24 2015 Thibaut Lopez
//

#ifndef DLLOADER_H
#define DLLOADER_H

#include <stdexcept>
#include <string>
#include <dlfcn.h>

template <typename T>
class DLLoader {

private:
  void		*handler;

public:
  DLLoader()
  {
    this->handler = NULL;
  }

public:
  T	       	getInstance(const std::string &lib, const std::string &symbol)
  {
    T		(*instance)();

    this->handler = dlopen(lib.c_str(), RTLD_LAZY);
    if (!this->handler)
      throw std::runtime_error(dlerror());
    instance = reinterpret_cast<T(*)()>(dlsym(this->handler, symbol.c_str()));
    if (!instance)
      throw std::runtime_error(dlerror());
    return (instance());
  }

  void		close()
  {
    if (this->handler)
      dlclose(this->handler);
  }
};

#endif
