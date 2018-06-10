#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Impelment some operations on multi-dimensional arrays
 * and check to what extend this is supported in cheri.
 */


int main(int argc, char **argv) {
  char *buffer;
  char *buffer2;
  int r=2, c=2;
  char *arr;

  buffer=malloc(10);
  arr=(char *) malloc(r*c*sizeof(char));
  buffer2=malloc(10);

  printf("Hello Buffers\n\n");
  int i,j,count=0;
  for (i=0;i<r;i++){
    for(j=0;j<c;j++){
	*(arr+i*c+j)=0x41;
    }
  }
  for (i=0;i<r;i++){
    for(j=0;j<c;j++){
	printf("[%d][%d]: %c\n", i, j , *(arr+i*c+j));
    }
  }

  memcpy(arr,argv[1], strlen(argv[1]));
  
  for (i=0;i<r;i++){
    for(j=0;j<c;j++){
	printf("[%d][%d]: %c\n", i, j , *(arr+i*c+j));
    }
  }


  printf("Buffer  @ %p: [%s]\n", buffer,buffer);

  printf("Buffer2 @ %p: [%s]\n", buffer2, buffer2);

  return 0;
}

