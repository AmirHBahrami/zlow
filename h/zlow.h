#ifndef __ZLOW_H
  #define __ZLOW_H 1
#endif

#define zlow(x) ( zlow_str( (x) ,'0' ,2000l ) )

/* print from ascii-index c to each character in s, delay nano secs with each print*/
void zlow_str(char *s,char c,long nano);
