#include <stdio.h>
#include <string.h>

void debug_pointers(char * b1, char *b2, char *b3){
    printf("Well, well, well ... what do we have here?\n");
    printf("------------------------------------------\n");
    printf("Buffer2: @%p [%s]\n", b1, b1);
    printf("Buffer1: @%p [%s]\n", b2, b2);
    printf("Buffer : @%p [%s]\n", b3, b3);
    printf("------------------------------------------\n");
}

int main(int argc, char **argv) {
  char buffer[16];
  char buffer1[4];
  char buffer2[16];

  buffer[15]='\0';
  buffer1[3]='\0';
  buffer2[15]='\0';

  printf("Hello Buffers\n\n");
  if (argc < 2)
      return 1;
  for (int i=0;i<argc;i++){
    printf("argv[%d]: %s\n", i, argv[i]);

  }
  memcpy(buffer2,argv[1], strlen(argv[1]));
  if ((strncmp(buffer1, "ABCD", 4))==0) {
     debug_pointers(buffer2, buffer1, buffer);
  }
  return 0;
}

