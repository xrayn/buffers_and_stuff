gcc -g -fstack-protector stack_variables/stack4_dop_with_canary.c -o stack4_dop_with_canary
gcc -g stack_variables/stack.c -o output/stack
gcc -g -fstack-protector stack_variables/stack.c -o output/stack_canary


gcc -g -fstack-protector stack_variables/stack_no_output.c -o output/stack_no_output_canary
gcc -g stack_variables/stack_no_output.c -o output/stack_no_output

