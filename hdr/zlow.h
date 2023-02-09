#ifndef __ZLOW_H
  #define __ZLOW_H 1
  #define ZLOW_NORMAL 0
  #define ZLOW_AND_BACK 1
#endif

#define zlow(x, nano ) ( zlow_str( (x) , 33 , (nano) ) )

/* print from ascii-index c to each character in s, delay nano secs with each print*/
void zlow_str(char *s,char c,long nano);

/* zlow_str's a string then removes it after wainting inbetween nano sec*/
void zlow_and_back(char *s,char c,long nano,long inbetween);
