#ifndef MAIN_H
#define MAIN_H

/* Defined vars */
#define PROMPT "$ "
#define DELIMETER " \n"

/* The imported libraries */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*                printers.c Modules                    */

/*   The printers for the shell                         */
void _putchar(char c);
void _puts(char *s);

/*             input_parsing.c Modules                  */

/*   The input manipulators so the shell can understand */
/*   what the user is typing                            */
int getNumberofTokens(char *lineptr);

/*             string_utils.c Modules                   */
/*   The functions that manipulate the string to get    */
/*   certain outputs from them                          */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
