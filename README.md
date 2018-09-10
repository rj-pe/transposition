transposition

Project Description: The program takes a string and encrypts it. Encryption occurs in the following pattern: If the input is 1 or 2 characters, the characters are returned unchanged. Otherwise the text is split into two even pieces (each piece is reversed in order) which are fed back into the algorithm.

Compiling instructions: Compile with gcc.

Sample Run:
// running using input redirection
$ cat sample.txt
12345678

$ gcc -o test encrypt.c
$ ./test < sample.txt
34127856

// running with stdin
$ gcc -o test encrypt.c
$ ./test
(manually enter the text to be encrypted)
 12345678
(when done, if on windows press CTRL + Z, if on linux press CTRL + D)
34127856

Known Bugs: None.
