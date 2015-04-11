//
// Bonus.hh for Bonus in /home/lopez_t/cpp_nibbler/src
// 
// Made by Thibaut Lopez
// Login   <lopez_t@epitech.net>
// 
// Started on  Thu Apr  2 16:30:13 2015 Thibaut Lopez
// Last update Sun Apr  5 19:38:38 2015 Romaric FAVE
//

#ifndef	BONUS_HH
#define	BONUS_HH

#include <iostream>
#include <string>
#include "Tail.hh"

enum e_Bonus
  {
    POINTS,
    LSPEED,
    GSPEED
  };

class	Bonus : public AItem
{
private:
  e_Bonus	bonus;
  int		step;
  AItem		*collision(std::list<AItem*> &, const int, const int);
public:
  Bonus(std::list<AItem *> &, const int, const int);
  Bonus(Bonus const &);
  virtual ~Bonus();
  e_Bonus	getBonus() const;
  int		getStep() const;
  bool		decStep();
  e_Effect	effect(Snake *) const;
  void		teleport(std::list<AItem *> &, const int, const int);
};

#endif
