/*
** my_strdup.c for my_strdup in /home/brout_m/dev/piscine/PJ8
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Oct  7 10:24:46 2015 marc brout
** Last update Tue Jan 26 22:09:18 2016 maud marel
*/

#include "tekdoom.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = bunny_malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
