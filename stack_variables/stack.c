#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char buffer[10];
  char buffer2[10];

  buffer[9]='\0';
  buffer2[9]='\0';

  printf("Hello Buffers\n\n");

  for (int i=0;i<argc;i++){
    printf("argv[%d]: %s\n", i, argv[i]);

  }
  printf("Buffer2: @%p\n", &buffer2);
  printf("Buffer : @%p\n", &buffer);

  memcpy(buffer2,argv[1], strlen(argv[1]));

  printf("Buffer2: @%p [%s]\n", &buffer2, buffer2);
  printf("Buffer : @%p [%s]\n", &buffer, buffer);

  return 0;
}

