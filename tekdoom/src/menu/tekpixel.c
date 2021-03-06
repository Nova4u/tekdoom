/*
** tekpixel.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1/src
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Nov 18 19:39:56 2015 Mathieu Sauvau
** Last update Mon Jan 25 15:04:35 2016 maud marel
*/

#include "menu.h"

void			tekpixel(t_bunny_pixelarray *pix_ar,
				 t_bunny_position pos,
				 unsigned int color)
{
  t_color		*col;
  int			new_pos;

  col = pix_ar->pixels;
  new_pos = pix_ar->clipable.clip_width * pos.y  + pos.x;
  if (new_pos >= 0 &&
      new_pos < pix_ar->clipable.clip_width * pix_ar->clipable.clip_height)
    col->full = color;
}
