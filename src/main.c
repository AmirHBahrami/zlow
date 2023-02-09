#ifndef __ZLOW_H
  #include "zlow.h"
#endif

#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __UNISTD_H 
  #include <unistd.h>
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

  // TODO add argeparse support
  // TODO add second and 0.5 second support
  long nano=2000l;
  long inbetween=0l;
  char start_from=33;
  char sep[16];
  int mode=ZLOW_NORMAL;
  
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

    else if(strcmp(*argv,"-i")==0 || strcmp(*argv,"--inbetween")==0){ // NEW
      ++argv;
      inbetween=atol(*argv);
    }

    else if(strcmp(*argv,"-sf")==0 || strcmp(*argv,"--start-from")==0){
      ++argv;
      start_from=**argv;
    }

    else if(strcmp(*argv,"-s")==0 || strcmp(*argv,"--seperator")==0){
      ++argv;
      strcpy(sep,*argv); // can be a string now!
    }
    
    // for now only normal and zlow_and_back modes are supported
    else if(strcmp(*argv,"-b")==0 || strcmp(*argv,"--zlow-and-back")==0){ // NEW
      mode=ZLOW_AND_BACK;

      /* set some default value */
      // if(!inbetween) inbetween=300000l;
    }

    else {
      inputs[inputs_i]=*argv;
      ++inputs_i;
    }

  }
  
  for (int i=0;i<inputs_i;i++){

    switch(mode){
      
      case ZLOW_NORMAL:
        zlow_str(inputs[i],start_from,nano);
        usleep(inbetween);
        printf("%s",sep);
        putchar('\n');
      break;
      
      case ZLOW_AND_BACK:
        zlow_and_back(inputs[i],start_from,nano,inbetween);
      break;

      default:
        zlow("you don't really have to be seeing this!\n",nano);
      break;
    }
  }

  return 0;
}

void print_h(){
  printf("zlow : print inputs like it's a movie!\nusage: zlow [options] input\n\t-h\t|| --help\t\tprint this help\n\t-d  [n] || --delay [n]\t\tdefault=2000\tn nano seconds between each word\n\t-b \t|| --zlow-and-back\tdefault=[not given]\tclears the screen after each entry\n\t-i  [n] || --inbetween [n]\tdefault=300k\twait before writing the next word\n\t-sf [a] || --start-from [a]\tdefault='0'\tstart from ascii character 'a'\n\t-s  [a] || --seperator [a]\tdefault=' '\tseperator between each word\n" );
}
