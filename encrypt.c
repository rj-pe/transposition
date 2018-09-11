// a simple transposition cipher
#include "encrypt.h"

/* places input from stdin into a char array, if input exceeds max size returns error message */
size_t parse_input(char *out)
{
  int char_count;
  char i;
  for(char_count = 0; (i = getchar()) != EOF && char_count < 8193; char_count++)
  {
    if(isspace(i) && (i == '\n'))
    {
      char_count--;
      continue;
    }
    out[char_count] = i;
  }
  if(char_count > MAXINPUT)
  {
    printf("input exceeds character limit! please try again:\n");
  }
  return (size_t) char_count;
} //end parse_input

/* encrypts plaintext, recursively builds ciphertext */
void encrypt(char *in, char *out, int input_len)
{
  if(input_len < 3)
  {
    strcat(out, in);
    return;
  }
  else
  {
    /* TODO: ensure that this integer division works for inputs with odd length */
    int k = input_len / 2;
    char first_half[k + 1];
    first_half[k] = '\0';
    char second_half[input_len - (k)];
    second_half[input_len - (k)] = '\0';
    int a1 = 0;
    int a2 = 0;
    for(int i = (k - 1); i >= 0; i--)
    {
      first_half[a1] = in[i];
      a1++;
    }
    for(int i2 = (input_len - 1); i2 >= k; i2--)
    {
      second_half[a2] = in[i2];
      a2++;
    }
    int first_len = strlen(first_half);
    int second_len = strlen(second_half);
    encrypt(first_half, out, first_len);
    encrypt(second_half, out, second_len);
  }
} //end encrypt

/* given plaintext, input, returns ciphertext, output. */
int main()
{
  while(1)
  {
    parsed_input = (char*) malloc(MAXINPUT * sizeof(char));
    input_size = parse_input(parsed_input);
    parsed_input = realloc(parsed_input, input_size * sizeof(char));
    if (strlen(parsed_input) <= 8192)
    {
      int i = 0;
      int in_length = strlen(parsed_input);
      encrypt(parsed_input, output, in_length);
      printf("%ld\n", strlen(output));      
      printf("%s\n", output);
      free(parsed_input);
      return 0;
    }
    else
      free(parsed_input);
      continue;
  }
} //end main
