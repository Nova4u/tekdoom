/*
** calc.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Wed Jan 27 08:40:09 2016 marc brout
*/

#include "tekdoom.h"

void		project_k(t_param *arg, t_lvl *lvl, int x, int pix)
{
  int		y;
  int		j;
  int		k;
  double	l;
  unsigned int	*pixelstext;
  unsigned int	*pixels;
  int		total;
  int		size;

  pixels = arg->pix->pixels;
  pixelstext = arg->textures[pix]->pixels;
  k = (int)(arg->textures[pix]->CWID * (DEC(XF) + DEC(YF)))
    % arg->textures[pix]->CWID;
  size = (arg->HEIGHT / (2 * arg->calc.k));
  total = (arg->HEIGHT / 2) + size + lvl->yangle - JUMP / arg->calc.k;
  y = (arg->HEIGHT / 2) - size - 1 + lvl->yangle - JUMP / arg->calc.k;
  l = 0;
  while (++y < total && y < arg->HEIGHT && ++l)
    if (y >= 0)
      {
	j = (int)((l / (size * 2)) * arg->textures[pix]->CHEI) %
	  arg->textures[pix]->CHEI;
	pixels[(int)(x + y * arg->WIDTH)] =
	  pixelstext[k + j * arg->textures[pix]->CWID];
      }
}

void		trace_obj(t_param *arg, int y, int x)
{
  int		i;
  int		j;
  int		k;
  int		l;
  double	len;
  unsigned int  *pixels;
  unsigned int	*sptpixels;

  pixels = arg->pix->pixels;
  sptpixels = arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->pixels;
  len = sqrt(pow(x - arg->lvl[I].playerx, 2) + pow(y - arg->lvl[I].playery, 2));
  j = arg->HEIGHT - len * 40 + 1 + arg->lvl[I].yangle;
  l = arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->CHEI + 1;
  while (--l > 0 && --j > 0 && (k = -1) && j < arg->HEIGHT)
    {
      i = arg->lvl[I].objs[y][x]->x -
	arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->CWID - 1;
      while (++k < arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->CWID
	     && ++i > 0 && i < arg->WIDTH)
	if (sptpixels[0] != sptpixels
	    [k + l * arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->CWID])
	  pixels[i + j * arg->WIDTH] = sptpixels
	    [k + l * arg->sprites[arg->lvl[I].objs[y][x]->type - 1]->CWID];
    }
  arg->lvl[I].objs[y][x]->trace = 0;
}

void		trace_objects(t_param *arg)
{
  int		y;
  int		x;

  y = -1;
  while (++y < arg->lvl[I].height)
    {
      x = -1;
      while (++x < arg->lvl[I].width)
	if (arg->lvl[I].objs[y][x]->trace && arg->lvl[I].objs[y][x]->alive)
	  trace_obj(arg, y, x);
    }
}

void		check_obj(t_param *arg)
{
  if (arg->lvl[I].objs[(int)arg->lvl[I].playery]
      [(int)arg->lvl[I].playerx]->alive)
    {
      bunny_sound_play(arg->sound->burger);
      arg->lvl[I].objs[(int)arg->lvl[I].playery]
	[(int)arg->lvl[I].playerx]->alive = 0;
    }
}

void		calc_walls(t_param *arg, UNUSED t_data *data)
{
  int		x;

  x = -1;
  while (++x < arg->WIDTH)
    {
      basic_to_sec(arg, x);
      get_len(arg, x);
      if ((int)YF >= 0 && (int)YF < arg->lvl[I].height &&
	  (int)XF >= 0 && (int)XF < arg->lvl[I].width)
      project_k(arg, &arg->lvl[I], x, arg->lvl[I].map[(int)YF][(int)XF]);
    }
  trace_objects(arg);
}
