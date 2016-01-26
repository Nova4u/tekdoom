 /*
** move.c for move in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 24 13:50:06 2016 benjamin duhieu
** Last update Mon Jan 25 01:23:04 2016 benjamin duhieu
*/

#include "main.h"

void            move(t_main *doom, t_lvl *lvl, double ang, double speed)
{
  /* double	test; */
  t_mov		vec;

  vec.x = doom->calc.ang.cosi[(int)(lvl->pla + ang) * 10] * speed;
  vec.y = doom->calc.ang.sinu[(int)(lvl->pla + ang) * 10] * speed;
  lvl->ply += vec.y;
  lvl->plx += vec.x;
  printf("ply = %f, plx = %f, pla = %f, vecx = %f, vecy = %f\n", lvl->ply, lvl->plx, lvl->pla, vec.x, vec.y);
}