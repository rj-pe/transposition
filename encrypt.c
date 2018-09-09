// a simple transposition cipher
#include "encrypt.h"

size_t parse_input(char *out)
{
  int char_count;
  char i;
  for(char_count = 0; (i = getchar()) != EOF && char_count < 8193; char_count++)
  {
    out[char_count] = i;
  }
  if(char_count > 8192)
  {
    printf("input exceeds character limit! please try again:\n");
  }
  return (size_t) char_count;
} //end parse_input

char *encrypt(char *in)
{
  int N = strlen(in);
  if(N < 3)
  {
    return in;
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
    for(int i = N; i < k; i--)
    {
      arg2[a2++] = in[i];
    }
    encrypt(arg1);
    encrypt(arg2);
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
      printf("%s\n", encrypt(parsed_input));
      free(parsed_input);
      return 0;
    }
    else
      free(parsed_input);
      continue;
  }
} //end main
