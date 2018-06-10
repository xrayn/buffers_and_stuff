#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *buffer;
  char *buffer2;

  buffer=malloc(10);
  buffer2=malloc(10);

  //buffer[9]='\0';
  //buffer2[9]='\0';

  printf("Hello Buffers\n\n");

  for (int i=0;i<argc;i++){
    printf("argv[%d]: %s\n", i, argv[i]);

  }

  memcpy(buffer,argv[1], strlen(argv[1]));

  printf("Buffer  @ %p: [%s]\n", buffer,buffer);

  printf("Buffer2 @ %p: [%s]\n", buffer2, buffer2);

  return 0;
}

