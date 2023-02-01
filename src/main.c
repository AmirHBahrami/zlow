#ifndef __ZLOW_H
  #include "../h/zlow.h"
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

/*
#ifndef __CTYPE_H
  #include <ctype.h>
#endif

#ifndef __LOCALE_H
  #include <locale.h>
#endif
// TODO read this shit: https://stackoverflow.com/questions/29477345/how-to-print-special-characters-explicitly-in-c
*/

static char *inputs[32];
static int inputs_i;

void print_h();
int atol(char *s); // in stdlib

int main(int argc,char **argv){

  long nano=2000l;
  char start_from=33;
  char sep=' ';
  
  ++argv; // exclude filename
  for(;*argv;++argv){
    
    if(strcmp(*argv,"-h")==0 || strcmp(*argv,"--help")==0){
      print_h();
      return 0;
    }

    if(strcmp(*argv,"-d")==0 || strcmp(*argv,"--delay")==0){
      ++argv;
      nano=atol(*argv);
    }

    else if(strcmp(*argv,"-sf")==0 || strcmp(*argv,"--start-from")==0){
      ++argv;
      start_from=**argv;
    }

    else {
      inputs[inputs_i]=*argv;
      ++inputs_i;
    }

  }
  
  for (int i=0;i<inputs_i;i++){
    zlow_str(inputs[i],start_from,nano);
    putchar(sep);
  }
  putchar('\n');

  return 0;
}

void print_h(){
  printf("zlow : print inputs like it's a movie\nusage: zlow [options] input\n\t-h\t|| --help\t\tprint this help\n\t-d  [n] || --delay [n]\t\tdefault=2000\tn nano seconds between each word\n\t-sf [a] || --start-from [a]\tdefault='0'\tstart from ascii character 'a'\n\t-s  [a] || --seperator [a]\tdefault=' '\tseperator between each word\n" );
}
