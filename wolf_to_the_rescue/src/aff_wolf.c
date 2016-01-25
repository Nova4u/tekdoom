/*
** aff_wolf.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 16:11:12 2015 marc brout
** Last update Mon Jan 25 16:33:15 2016 Mathieu Sauvau
*/

#include "wolf.h"

t_bunny_response		my_mouse(const t_bunny_position *pos,
					 void *data)
{
  const t_bunny_position	*abs;
  t_param			*arg;

  arg = data;
  abs = bunny_get_mouse_position();
  if (!arg->mov)
    {
      arg->lvl[arg->curlvl].yangle += pos->y / 3;
      arg->lvl[arg->curlvl].plangle += pos->x / 3;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle += 359;
      if (arg->lvl[arg->curlvl].plangle >= 359)
	arg->lvl[arg->curlvl].plangle -= 359;
    }
  else
    arg->mov = 0;
  if ((abs->x <= 200 || abs->x >= (arg->WIDTH - 200)) ||
      (abs->y <= 200 || abs->y >= (arg->HEIGHT - 200)))
    {
      bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2, arg->HEIGHT / 2);
      arg->mov = 1;
    }
  return (GO_ON);
}

t_bunny_response	main_wolf(void *data)
{
  t_param		*arg;
  int			i;

  arg = data;
  i = -1;
  if (arg->data->exit)
    return (EXIT_ON_SUCCESS);
  if (arg->speedy)
    {
      move(arg, 0, 0.02);
      arg->speedy--;
    }
  new_hight(arg);
  simple_tap(arg);
  i = sky(arg, i);
  bottom(arg, i);
  calc_walls(arg);
  set_bump(arg, &arg->lvl[arg->curlvl]);
  add_player_to_mini(arg, &arg->lvl[arg->curlvl]);
  put_border(arg, 6, BORDER);
  put_border(arg, 4, BORDERIN);
  put_border(arg, 2, BORDEROU);
  mini_map(arg, &arg->lvl[arg->curlvl]);
  interface(arg);
  bunny_blit(&arg->win->buffer, &arg->pix->clipable, &arg->data->pos);
  bunny_display(arg->win);
  return (GO_ON);
}

int		sky(t_param *arg, int i)
{
  t_color	*pixels;
  int		total;

  total = (arg->WIDTH * arg->HEIGHT) / 2 +
    (int)(arg->lvl[arg->curlvl].yangle - (arg->hight * (34))) * arg->WIDTH;
  pixels = arg->pix->pixels;
  while (++i < total && total)
    pixels[i].full = SKY;
  return (i);
}

void		bottom(t_param *arg, int i)
{
  t_color	*pixels;
  int		realt;

  realt = arg->WIDTH * arg->HEIGHT;
  pixels = arg->pix->pixels;
  while (++i < realt)
    pixels[i].full = FLOOR;
}

char		aff_wolf(t_param *arg)
{
  if ((arg->pix = bunny_new_pixelarray(arg->WIDTH, arg->HEIGHT)) == NULL ||
      (arg->win = bunny_start(arg->WIDTH, arg->HEIGHT,
			      arg->CONFIG->fullscreen, "DOOM")) == NULL)
    return (1);
  arg->curlvl = 0;
  arg->key = &my_keys;
  arg->move = &my_mouse;
  arg->mov = 1;
  set_minimaps(arg);
  interface_init(arg);
  if (load_picture(arg) == -1)
    return (-1);
  bunny_set_loop_main_function(main_wolf);
  bunny_set_move_response(arg->move);
  bunny_set_key_response(arg->key);
  bunny_set_mouse_visibility(arg->win, 0);
  bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2, arg->HEIGHT / 2);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
