#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators


//function to split lines and tokenize 

char **line_split(char *lines)
{
  int buffer = MAX_ARGS, position = 0;
  char **symbols = malloc(buffer * sizeof(char*));
  char *symbol;

  symbol = strtok(lines, SEPARATORS);
  while (symbol != NULL) {
    symbols[position] = symbol;
    position++;

    if (position >= buffer) {
      buffer += MAX_ARGS;
      symbols = realloc(symbols, buffer * sizeof(char*));
    }

    symbol = strtok(NULL, SEPARATORS);
  }
  symbols[position] = NULL;
  return symbols;
}

