#ifndef _MEM_H_
#define _MEM_H_

#include <stddef.h>

struct node {
  int value;
  struct node *next;
};

void func1(struct node *head);
void func2(int argc, char **argv);
void func3(char *c_str1, size_t size);
void func4(int argc, char **argv);
void mem_main(int argc, char **argv);

#endif