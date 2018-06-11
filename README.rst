Excercise Buffer Overflow Stack
-------------------------------


The code we will use for our exploitation is as follows:

.. code:: c

    #include <stdio.h>
    #include <string.h>

    int main(int argc, char **argv) {
      char buffer[16];
      char buffer2[16];

      buffer[15]='\0';
      buffer2[15]='\0';

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


Tasks: The code contains a buffer overflow vulnerability. The goal of this
excercise is to exploit this vulnerability and use it to spawn a shell.

1. Locate the buffer overflow vulnerability inside the code

2. Compile your code as follows:
   `gcc -g stack_variables/stack.c -z execstack -o output/stack_exec_stack`

3. Disable ASLR as follows:
   `./aslr_disable`

4. Play around with the command line arguments and understand what happens
   inside the code

5. Answer the following questions:
   
   #. How many Bytes do you need to overflow until you receive a segmentation
      fault?
   
   #. How many Bytes are available in your buffer?

6. Got to https://www.exploit-db.com/exploits/42179/ or look at the file
   exploit_shellcode.c

7. Locate the shellcode and find a way how to inject this code into your
   buffers.

   - E.g. $(python -c 'print "\x50"')

8. Figure out the padding you will need between your buffer and the return
   address

9. Figure out the correct address that points to your shellcode and overwrite
   the areturn address accordingly. (Note, X86_64 uses little endian byte
   order!)

10. Put everything together in a single command line argument and execute your
    exploit.

11. There is a precompiled version of this program available.
    `stack_exec_root`. use what you learnt and use this program to exploit it.

    - Once you have a shell (this time this is a root shell) 
      read the contents of the file `secret` to get the password for the root account.



