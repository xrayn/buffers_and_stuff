#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char buffer[10];
  char buffer2[10];

  buffer[9]='\0';
  buffer2[9]='\0';
  memcpy(buffer2,argv[1], strlen(argv[1]));
  return 0;
}

