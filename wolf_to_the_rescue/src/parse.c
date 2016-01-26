/*
** parse.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan 26 14:45:50 2016 marc brout
** Last update Tue Jan 26 15:49:02 2016 marc brout
*/

char			add_obj(t_lvl *lvl, int type, int i)
{
  t_obj			*elem;

  if (!(elem = malloc(sizeof(t_obj))))
    return (1);
  elem->type = type;
  elem->x = i % lvl->width;
  elem->y = i % lvl->width;
  elem->next = lvl->obj;
  lvl->obj = elem;
  return (0);
}

char			parse_objects(t_bunny_scope *scope,
				      t_param * arg, t_lvl *lvl)
{
  int			x;
  int			y;
  int			i;
  const char		*nb;

  y = -1;
  while (++y < lvl->height)
    {
      x = -1;
      while (++x < lvl->width)
	{
	  i = x + (lvl->height - 1 - y) * lvl->width;
	  if ((nb = 
	}
    }
}

char			search_objects(t_param *arg)
{
  t_bunny_scope		*scope;
  int			i;

  i = -1;
  if (!(scope = bunny_ini_first(arg->ini)) ||
      !(scope = bunny_ini_next(arg->ini, scope)))
    return (1);
  while (ini->scope)
    {
      i += 1;
      if (!(BIS(scope, "type", 0)))
	continue;
      parse_objects(arg, arg->lvl[i]);
      arg->lvl[i]->obj = NULL;
      scope = bunny_ini_next(arg->ini, scope);
    }
  return (0);
}
