// a simple transposition cipher
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXINPUT 8192

char *parsed_input;
size_t parse_input(char *out);
char *encrypt(char *in);
size_t input_size;
