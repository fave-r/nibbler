//
// LX.cpp for nibbler in /home/fave_r/rendu/cpp_nibbler/Music/fmod
// 
// Made by Romaric FAVE
// Login   <fave_r@epitech.net>
// 
// Started on  Sat Apr  4 18:34:34 2015 Romaric FAVE
// Last update Sun Apr  5 13:15:39 2015 Thibaut Lopez
//

#include "my_fmod.hpp"

MY_FMOD::MY_FMOD()
{
}

void    MY_FMOD::play(std::string const &str)
{
  //if (str == NULL)
  //str = "battle.mp3";
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);
  //FMOD_Sound_SetLoopCount(musique, -1);
  resultat = FMOD_System_CreateSound(system, str.c_str(), FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  if (resultat != FMOD_OK)
    {
      std::cerr << "Cannot find " << str << std::endl;
      return;
    }
  FMOD_System_GetChannel(system, 9, &channel);
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
}

bool            MY_FMOD::init()
{
  return true;
}

MY_FMOD::~MY_FMOD()
{
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}


extern "C" ISound			*getsound()
{
  return (new MY_FMOD());
}
