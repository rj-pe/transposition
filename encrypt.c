// a simple transposition cipher
#include "encrypt.h"

size_t parse_input(char *out)
{
  int char_count;
  char i;
  for(char_count = 0; (i = getchar()) != EOF && char_count < 8193; char_count++)
  {
    if(isspace(i))
    {
      char_count--;
      continue;
    }
    out[char_count] = i;
  }
  if(char_count > 8192)
  {
    printf("input exceeds character limit! please try again:\n");
  }
  return (size_t) char_count;
} //end parse_input

void encrypt(char *in, char *out)
{
  int N = strlen(in);
  if(N < 3)
  {
    strcat(out, in);
    return;
  }
  else
  {
    /* TODO: ensure that this integer division works for inputs with odd length */
    int k = N / 2;
    char arg1[k];
    int a1 = 0;
    for(int i = k; i > 0; i--)
    {
      arg1[a1++] = in[i];
    }
    int a2 = 0;
    char arg2[k];
    int i2 = N-1;
    for(; i2 > k; i2--)
    {
      arg2[a2++] = in[i2];
    }
    encrypt(arg1, out);
    encrypt(arg2, out);
  }
} //end encrypt

/* */
int main()
{
  while(1)
  {
    parsed_input = (char*) malloc( MAXINPUT * sizeof(char));
    input_size = parse_input(parsed_input);
    parsed_input = realloc(parsed_input, input_size * sizeof(char));
    
    if (strlen(parsed_input) <= 8192)
    {
//      output = (char*) malloc(sizeof(char));
      int i = 0;
      encrypt(parsed_input, output);
      printf("%s\n", output);
      printf("34127856\n");
  //    free(output);
      free(parsed_input);
      return 0;
    }
    else
      free(parsed_input);
      continue;
  }
} //end main
