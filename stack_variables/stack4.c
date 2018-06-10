#include <stdio.h>
#include <string.h>


char secret[]="StacKSmack123!!";

void print_secret(){
  printf("The secret is [%s]\n", secret);
}

int main(int argc, char **argv) {
  char buffer2[8];
  char check[16];
  char buffer[8];
  
  buffer[7]='\0';
  buffer2[7]='\0';
  printf("check   is @ [%p]\n", &check);
  printf("buffer  is @ [%p]\n", &buffer);
  printf("buffer2 is @ [%p]\n", &buffer2);
  printf("Your input: ");
  gets(buffer);

  printf("buffer  is @ [%p] %s\n", &buffer, buffer);
  printf("buffer2 is @ [%p] %s\n", &buffer2, buffer2);

  
  if (!strcmp(check, "ABCD")){
	  //printf("Got me.\n");
	  print_secret();
  }
  else {
	printf("Better luck next time.\n");
	printf("%s\n",check);
  }

  return 0;
}

