#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "String.h"


bool DEBUG1 = false;
bool DEBUG2  = false;
bool DEBUG3 = false;
bool DEBUG4 = false;
bool DEBUG5 = false;
bool DEBUG6 = true;

int main(int argc, char* argv[])
{
    if(DEBUG1){
      FILE* fp = fopen(argv[1], "r");
      char* s = readfile(fp);
      printf("%s", s);

      char* delims = (char*)calloc(100, sizeof(char));
      strcpy(delims, "\n");
      char** tokens = stringsplit(s, delims);
      if(tokens == NULL){
        printf("Why\n");
      }
      int i = 0;
      while(tokens[i] != NULL){
        printf("%s %d\n",tokens[i], i+1);
        i++;
      }
      destroystringarray(tokens);
      destroystring(s);
      destroystring(delims);
      fclose(fp);


    }
    //TEST COSNTRUCTORS
    if(DEBUG2){
        char* s = createvoidstring();
        char** s1 = createvoidstringarray();
        if(s1 != NULL && s != NULL)
          printf("Success\n");
        destroystring(s);
        destroystringarray(s1);
    }
    //Test DESTROYERS
    if(DEBUG3){
        //char s[100];
        //destroystring(s);
        char** sa = createvoidstringarray();
        destroystringarray(sa);

    }
    //TEST CLONERS
    if(DEBUG4){
      //char* s = createvoidstring();
      //strcpy(s, "Eek a penis");
      //char* clone = stringcopy(s);
      //printf("%s\n", clone);
      //destroystring(s);
      //destroystring(clone);
      char* s = stringcopy("Three times four is 24");
      char* delims = stringcopy(" ");
      char** source = stringsplit(s, delims);
      char** clone = stringarraycopy(source);
      char** part = stringarraysegmentcopy(clone, 2, 9);
      int j = 0;
      while(part[j]!=NULL){
        printf("%s\n", part[j]);
        j++;
      }
      int i = 0;
      while(clone[i]!=NULL){
            printf("%s %s\n", clone[i], source[i]);
            i++;
      }
      destroystring(delims);
      destroystringarray(source);
      destroystringarray(clone);
      char* segment = stringsegmentcopy(s, 7, 16);
      if(badstring(segment))return 0;
      printf("Segment is %s\n", segment);
      destroystring(s);
      destroystring(segment);
      destroystringarray(part);

    }
    //test modifiers
    if(DEBUG5)
    {
      char* dest = NULL;
      char* source = stringcopy("hat");
      printf("Source is %s\n", source);
      dest = stringcat(dest, source);
      printf("Dest is %s\n", dest);
      destroystring(source);
      destroystring(dest);
      source = stringcopy("fat");
      printf("Source is %s\n", source);
      dest = stringcat(dest, source);
      //destroystring(source);
      //destroystring(dest);
      printf("Dest is %s\n", dest);
      destroystring(source);
      source = stringcopy("Balloon");
      printf("Source is %s\n", source);
      dest = stringcat(dest, source);
      printf("dest is %s\n", dest);
      destroystring(dest);
      destroystring(source);
      format type = FLOAT;
      double k = -122.375;
      char* str = tostring(type, &k);
      printf("%s\n", str);
      destroystring(str);
      //destroystring(source);

    }
    //test print function
    if(DEBUG6){
      char* s = stringcopy("I want, to, bang Andrea.");
      char** a = stringsplit(s, " ,");
      char* print = printstringarray(a);
      printf("print is\n\n%s", print);
      destroystring(s);
      destroystring(print);
      destroystringarray(a);
      
    }
     return 0;
}
