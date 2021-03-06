/*
** nav.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:37:15 2016 Mathieu Sauvau
** Last update Tue Jan 26 23:14:41 2016 Mathieu Sauvau
*/

#include "tekdoom.h"

void			up_and_down(t_bunny_event_state state, t_bunny_keysym keysym,
			    t_data *data)
{
  if ((keysym == BKS_UP || keysym == INPUT->key[0]) && state == GO_DOWN
      && !INPUT->change_key && data->menu_index != 2)
    {
      bunny_sound_play(data->menu_nav);
      data->selected_index == 0 ?
      data->selected_index = data->menu_length - 1 : data->selected_index--;
    }
  if ((keysym == BKS_DOWN || keysym == INPUT->key[1]) && state == GO_DOWN
      && !INPUT->change_key && data->menu_index != 2)
    {
      bunny_sound_play(data->menu_nav);
      data->selected_index == data->menu_length - 1 ?
	data->selected_index = 0 : data->selected_index++;
    }
}

void			nav(t_data *data)
{
  if (data->menu_index == 1)
    option_nav(data);
  else if (data->menu_index == 2)
    {
      if (data->selected_index == 0)
	data->menu_index = 0;
    }
  else if (data->menu_index == 3)
    input_nav(data);
}

t_bunny_response	esc(t_bunny_event_state state, t_bunny_keysym keysym,
			    void *my_data)
{
  t_data		*data;

  data = my_data;
  if (keysym == BKS_ESCAPE || data->exit)
    {
      data->exit = true;
      return (EXIT_ON_SUCCESS);
    }
  up_and_down(state, keysym, data);
  if (keysym == BKS_RETURN && state == GO_DOWN)
    {
      if (data->menu_index == 0)
	{
	  if (menu_nav(data) == 1)
	    return (EXIT_ON_SUCCESS);
	}
      else
	nav(data);
      bunny_sound_play(data->menu_select);
    }
  option_nav2(state, keysym, data);
  if (data->menu_index == 3)
    change_key(data);
  return (GO_ON);
}
