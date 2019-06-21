#include<stdio.h>
#include<string.h>
 
int main()
{
      int str_length, pattern_length, j, i, count = 0;
      char str[30], pattern[30] ;
      printf("\nEnter a String:\t");
      scanf("%s", str);
      printf("\nEnter a Pattern to Match:\t");
      scanf("%s", pattern);
      str_length = strlen(str);
      pattern_length = strlen(pattern);
      printf("\nPattern Matched at Position:\t");
      for(i = 0; i < str_length - pattern_length; i++)
      {
            for(j = 0; j < pattern_length; j++)
            {
                  if(str[i + j] == pattern[j]) count++;
            }
            if(count == pattern_length)
            {
                  printf("%d\t", i);
            }
            count = 0;
      }
      printf("\n");
      return 0;
}
