#ifndef __ZLOW_H
  #include "zlow.h"
#endif

// for printing
#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __UNISTD_H 
  #include <unistd.h>
#endif

#define zlow_unchar( n ) ( zlow_unchar_c( ' ' , (n)  ) )

static void zlow_char(char curr,long nano){

  putchar(curr);
  fflush(stdout);
  usleep(nano);
  putchar('\b');
  putchar(7);
  fflush(stdout);
}

static void zlow_unchar_c(char c,long nano){
    putchar('\b');
    fflush(stdout);
    usleep(nano);
    putchar(c);
    putchar('\b');
    fflush(stdout);
    usleep(nano);
}

// c == starting character
void zlow_str(char *s,char c,long nano){
  char curr=0;
  while(*s){
    if((*s)==' ' || (*s)=='\n') curr=(*s);
    else {

      /* to balance load processing , direction is backwards for *s<'Z'*/
      if((*s)<='Z') for(curr=126; curr>(*s); curr--) zlow_char(curr,nano);
      else for(curr=c; curr<(*s); curr++) zlow_char(curr,nano);
    }
    putchar(curr);
    ++s;
    fflush(stdout); // to solve some bug (dont' remove it!)
  }
  fflush(stdout); // to solve some bug (dont' remove it!)
}

void zlow_and_back(char *s,char c, long nano,long inbetween){
  char *start=s;
  zlow_str(s,c,nano);
  usleep(inbetween);
  for ( ;*start;++start){
    zlow_unchar(nano*8);
    usleep(nano);
  }

}
