// a simple transposition cipher
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXINPUT 8192

size_t input_size;
char *parsed_input;
char output[MAXINPUT];
size_t parse_input(char *out);
void encrypt(char *in, char *out);
