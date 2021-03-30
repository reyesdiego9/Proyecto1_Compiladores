#include <stdio.h>
#include <ctype.h>


string reservada[50] = {"IF", "THEN", "ELSE","BEGIN", "END",
 "FOR","REPEAT", "WHILE", "VARIABLE", "CONST", 
 "PROGRAM", "INCLUDE", "UNTIL", "FOREACH", 
 "SPLIT", "CASE", "SWITCH"};

int main (void)
{
   static const char filename[] = "lectura.txt";
   FILE *file = fopen(filename, "r");
   if ( file != NULL )
   {
      int ch, word = 0;
      while ( (ch = fgetc(file)) != EOF )
      {
         if ( isspace(ch) || ispunct(ch) )
         {
            if ( word )
            {
               word = 0;
               putchar('\n');
            }
         }
         else
         {
            word = 1;
            putchar(ch);
         }
      }
      fclose(file);
   }
   return 0;
}
