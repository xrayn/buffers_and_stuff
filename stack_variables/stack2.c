#include <stdio.h>
#include <string.h>


char secret[]="StacKSmack123!!";

void print_secret(){
  printf("The secret is [%s]\n", secret);
}

int main(int argc, char **argv) {
  int check=0;
  char buffer[16];

  printf("check  is @ [%p]\n", &check);
  printf("buffer is @ [%p]\n", &buffer);
  printf("Your input: ");
  gets(buffer);

  printf("Your input was: %s\n", buffer);
  printf("Good Bye!\n");
  if (check == 0x41424344){
	  //printf("Got me.\n");
	  print_secret();
  }
  else {
	printf("Better luck next time.\n");
	printf("%x\n",check);
  }

  return 0;
}

