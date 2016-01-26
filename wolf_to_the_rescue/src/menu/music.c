/*
** music.c for music
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Jan 26 11:11:29 2016 benjamin duhieu
** Last update Tue Jan 26 13:11:25 2016 benjamin duhieu
*/

#include "menu.h"

void    disp_sound(t_data *data)
{
  if (data->sound == 1)
    {
      bunny_sound_play(data->music);
      data->sound = -1;
    }
  bunny_sound_loop(data->music, true);
  bunny_sound_volume(data->music, (double)data->config->volume);
}
