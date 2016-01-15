/*
** draw.c for draw in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jan 14 15:14:24 2016 Maud MAREL
** Last update Fri Jan 15 09:54:40 2016 Maud MAREL
*/

#include "interface.h"

void			draw_life_bar(t_data *data)
{
  t_bunny_position	pos_s;
  t_bunny_position	pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_e.x = (WIDTH / 10) + (WIDTH / 5);
  pos_e.y = HEIGHT - (HEIGHT / 75);
  while (++pos_s.x < pos_e.x)
    {
      pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while(++pos_s.y < pos_e.y)
	tekpixel(data->pix, &pos_s, RED);
    }
}

void			draw_square_life_bar(t_data *data)
{
  t_bunny_position	pos_s;
  t_bunny_position	pos_eh;
  t_bunny_position	pos_e;
  t_bunny_position	pos_sh;

  pos_s.x = (WIDTH / 75) - 1;
  pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
  pos_e.x = (WIDTH / 10) + (WIDTH / 5);
  pos_e.y = (HEIGHT - (HEIGHT / 75)) - 1;
  pos_eh.x = pos_e.x;
  pos_eh.y = pos_s.y;
  pos_sh.x = pos_s.x - 1;
  pos_sh.y = pos_e.y;
  while (++pos_s.x <= pos_eh.x)
    tekpixel(data->pix, &pos_s, BLACK);
  while (++pos_eh.y <= pos_e.y)
    tekpixel(data->pix, &pos_eh, BLACK);
  pos_s.x = WIDTH / 75;
  while (++pos_s.y <= pos_e.y)
    tekpixel(data->pix, &pos_s, BLACK);
  while (++pos_sh.x <= pos_e.x)
    tekpixel(data->pix, &pos_sh, BLACK);
}

void			draw_life(t_data *data)
{
  t_bunny_position	pos_s;
  t_bunny_position	pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_e.x = (pos_s.x + (((WIDTH / 10) + (WIDTH / 5)) / 3)) - 1;
  pos_e.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
  while (++pos_s.x < pos_e.x)
    {
      pos_s.y = (((11 * (HEIGHT / 12)) - ((HEIGHT / 65) + (HEIGHT / 65)))) - 1;
      while(++pos_s.y < pos_e.y)
	tekpixel(data->pix, &pos_s, BLUE);
    }
}
