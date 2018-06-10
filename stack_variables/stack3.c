#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char buffer[10];
  char buffer2[10];

  buffer[9]='\0';
  buffer2[9]='\0';

  printf("Hello Buffers\n\n");
  
  for (int i=0;i<argc;i++){
    printf("argv[%d]: %s\n", i, argv[i]);

  }
  memcpy(buffer2,argv[1], strlen(argv[1]));

  printf("Buffer2: [%s]\n", buffer2);

  printf("Buffer : [%s]\n", buffer);

  while(1){
      printf("Hallo\n");
      usleep(1000000); //1sec
  }

  return 0;
}

