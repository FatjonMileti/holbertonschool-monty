
![Monty](https://user-images.githubusercontent.com/105599575/185717069-d67965d2-5a72-4d44-9797-fe31cc22110d.jpeg)


### [MONTY](https://montyscoconut.github.io/)

Monty 0.98 is a **scripting language that is first compiled into Monty byte codes** (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### Description
This program is built to interpret Monty-like scripted files according to operation codes provided by Holberton School.

### Allowed opcodes and what they do:

| opcode | objective |
| --- | --- |
| **push** | adds element to the 'top' of stack and 'end' of queue |
| **pop** | remove element from 'top' of stack and 'end' of queue|
| **pall** | prints every member of the structure |
| **pint** | prints the member value at the top of stack |
| **swap** | swaps the order  of the 1st and 2nd elements in stack |
| **add** | adds top two member values |
| **sub** | subtracts the top element from the 2nd top element |
| **div** | divides the 2nd element by the top element |
| **mul** | multiplys the top two elements of the stack |
| **mod** | the remainder when the 2nd element is divided by the top element |
| **comment** | there is the ability to parse comments found in bytecode ->'#'|
| **pchar** | prints character at the top of the stack |
| **pstr** | prints the character at the top of the stack|
| **rotl** | moves element at the top to the bottom of the stack |
| **rotr** | the bottom of the stack becomes the top |
| **queue, stack** | similar to the the doubly link list implementation style |
| **nop** | does nothing |


Examples:


```
$ cat opcodetestfile.m
push 1
push 2
push 3
pall

$ ./montyfile opcodetestfile.m
3
2
1
$
```
---

```
$ ./montyfile opcodetestfile.m
3
2
1
2
1
3

```
---


 ### Code explained
 
 **1 - [monty.h](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/monty.h)** - Header file, containing the libraries to be used, functions & data structures
 
 **2 - [main.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/main.c)** - Main function that checks for the number of arguments
 
  **3 - [execute_commands.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/execute_commands.c)** - Function that opens, reads & executes given command
  
  **4 - [opcodes.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/opcodes.c)** - This is the function that will preform the operation
  
  **5 - [print_op.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/print_op.c)** - This file contains the following the functions:
  
  * `_pchar` : Function that prints character at the top of stack
  * `_pstr` : Function that prints the string at the top of stack
  *  `_mul` : function that multiplies the top element of stack with the second top
  *  `_mod` : Function that gives the module off the second top element from the first top
  
**6 - [stack.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/stack.c)** - This file contains the following the functions:

  * `push_stack` : Function that adds a node at the top of a list
  * `pall_stack` : function that prints all elements of a stack
  * `pint_stack` : Function that prints top element of the stack
  * `pop_stack` : Function that deletes the first element of the stack
  * `free_stack` : Function that frees the given list 


**7 - [stack2.c](https://github.com/FatjonMileti/holbertonschool-monty/blob/main/stack2.c)** - This file contains the following the functions:

* `_swap` : Function that swaps the fist 2 elements os a stack
* `_add` : Function that adds 2 top elements of the stack
* `_sub` : Function that substacts the firt top element form the second top
* `_div` : Function that devides the first top element of stack by second
* `_nop` : Function that does nothing

####
Authors

:octocat: Tiziana Hoxha - https://github.com/tizihoxha

:octocat: FatjonMileti - https://github.com/FatjonMileti
