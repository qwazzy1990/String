#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "utilities.h"

#include "DynamicString.h"

bool DEBUG0 = false;
bool DEBUG1 = false;
bool DEBUG2  = false;
bool DEBUG3 = false;
bool DEBUG4 = false;
bool DEBUG5 = true;
bool DEBUG6 = false;
bool DEBUG7 = false;
bool DEBUG8 = false;
bool DEBUG9 = false;

int main(int argc, String argv[])
{

    if(DEBUG0){
    	String a = NULL;
      a = createvoidstring();
      forall(10){
        a[x] = 'x';
      }
      printf("%s\n", a);
	    destroystring(a);
      if(a == NULL)printf("Success\n");
    }	
    if(DEBUG1){
      FILE* fp = fopen(argv[1], "r");
      String s = readfile(fp);
      printf("%s", s);

      String delims = (String)calloc(100, sizeof(char));
      strcpy(delims, "\n");
      Strings tokens = stringsplit(s, delims);
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
        String s = createvoidstring();
        Strings s1 = createvoidstringarray();
        if(s1 != NULL && s != NULL){
          printf("Success\n");
        }
        destroystring(s);
        destroystringarray(s1);
    }
    //Test DESTROYERS
    if(DEBUG3){
        //char s[100];
        //destroystring(s);
        Strings sa = createvoidstringarray();
        destroystringarray(sa);

    }
    //TEST CLONERS
    if(DEBUG4){
      //String s = createvoidstring();
      //strcpy(s, "Eek a penis");
      //String clone = stringcopy(s);
      //printf("%s\n", clone);
      //destroystring(s);
      //destroystring(clone);
      String s = stringcopy("Three times four is 24");
      String delims = stringcopy(" ");
      Strings source = stringsplit(s, delims);
      Strings clone = stringarraycopy(source);
      Strings part = stringarraysegmentcopy(clone, 2, 9);
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
      String segment = stringsegmentcopy(s, 7, 16);
      if(badstring(segment))return 0;
      printf("Segment is %s\n", segment);
      destroystring(s);
      destroystring(segment);
      destroystringarray(part);

    }
    //test modifiers
    if(DEBUG5)
    {
      String dest = NULL;
      String source = stringcopy("hat");
      printf("Source is %s\n", source);
      dest = stringcat(dest, source);
      printf("Dest is %s\n", dest);
      destroystring(source);
      //destroystring(dest);
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
      Primitive type = FLOAT;
      double k = -122.375;
      String str = tostring(type, &k);
      printf("%s\n", str);
      destroystring(str);
      destroystring(source);
      destroystring(dest);

    }
    //test print function
    if(DEBUG6){
      String s = stringcopy("I want, to, bang Andrea.");
      Strings a = stringsplit(s, " ,");
      remove_from_stringarray(a, "want");
      String print = printstringarray(a);
      printf("print is\n\n%s", print);
      destroystring(print);
      destroystringarray(a);
      if(a == NULL && print == NULL){
        printf("Destroyers succeeded\n");
      }
      char test = getch(s, 100);
      printf("test is %c\n", test);
      destroystring(s);

      
    }
    if(DEBUG7){
      String test = stringcopy("There is a demon");
      int* indecies = indecies_of_char(test, 'z');
      int i = 0;
      while(indecies[i] != -1){
        printf("%d\n", indecies[i]);
        i++;
      }
      free(indecies);
      destroystring(test);
      String test2 = stringcopy("the cat and the bat and the hat");
      Strings a = stringsplit(test2, " ");
      indecies = indecies_of_string(a, "the");
      i = 0;
      while(indecies[i] != -1){
        printf("array %d\n", indecies[i]);
        i++;
      }
      free(indecies);
      destroystringarray(a);
      destroystring(test2);
    
    }
    
    if(DEBUG8){

      String a = stringcopy("bat");
      String b = stringcopy("Bat");
      printf("%d\n", strequal(a, b, CASE_INSENSITIVE));
      printf("%d\n", strequal(a, b, CASE_SENSITIVE));
      destroystring(a);
      destroystring(b);
      String c = to_upper("bAt");
      printf("%s\n", c);
      destroystring(c);
    }

    //Concatenation and String conversion debug
    if(DEBUG9)
    {
      String a = stringcopy("Hello");
      //Preprocessor directives ignores space
      //a = stringcat(a, 3, $( World), $( Jesus), $( Christ));
      P("%s\n", a); 
      if(a == NULL)printf("A is NULL\n");
      clear(a);
      P("%s\n", $(j));

    }

     return 0;
}
