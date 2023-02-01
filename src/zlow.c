#ifndef __ZLOW_H
  #include "../h/zlow.h"
#endif

// for printing
#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __UNISTD_H 
  #include <unistd.h>
#endif

static void zlow_char(char curr,long nano){

  putchar(curr);
  fflush(stdout);
  usleep(nano);
  putchar('\b');
  putchar(7);
  fflush(stdout);
}

/* delay not yet taken into account */
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
  }

}
