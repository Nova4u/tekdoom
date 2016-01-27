/*
** cliK.c for clik in
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Jan 27 00:48:48 2016 benjamin duhieu
** Last update Wed Jan 27 03:13:35 2016 benjamin duhieu
*/

#include "tekdoom.h"

t_bunny_response		main_click(UNUSED t_bunny_event_state state,
					   UNUSED t_bunny_mousebutton button,
					   void	*data)
{
  const bool			*mouse;
  t_param			*doom;
  int				cac;

  doom = data;
  mouse = bunny_get_mouse_button();
  if (mouse[BMB_LEFT])
    {
      if (doom->inter.gun.i == 0)
	bunny_sound_play(doom->sound->shotgun);
      if (doom->inter.gun.i == 1)
	bunny_sound_play(doom->sound->knife);
      if (doom->inter.gun.i == 2)
	bunny_sound_play(doom->sound->bazook);
      if (doom->inter.gun.i == 3)
	bunny_sound_play(doom->sound->sulf);
      if (doom->inter.gun.i == 4)
	{
	  cac = rand() % 2;
	  if (!cac)
	    bunny_sound_play(doom->sound->cac);
	  else
	    bunny_sound_play(doom->sound->cac2);
	}
    }
  return (GO_ON);
}
