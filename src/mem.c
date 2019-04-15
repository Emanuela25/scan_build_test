#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"

void func1(struct node *head)
{
  for (struct node *p = head; p != NULL; p = p->next)
  {
    free(p);
  }
}

void func2(int argc, char **argv)
{
  char *return_val = 0;
  const size_t bufsize = strlen(argv[0]) + 1;
  char *buf = (char *)malloc(bufsize);
  if (!buf)
  {
    return;
  }
  /* ... */
  free(buf);
  /* ... */
  strcpy(buf, argv[0]);
  /* ... */
  return;
}

void func3(char *c_str1, size_t size)
{
  char *c_str2 = (char *)realloc(c_str1, size);
  if (c_str2 == NULL)
  {
    free(c_str1);
  }
}

enum
{
  MAX_ALLOCATION = 1000
};
void func4(int argc, char **argv)
{
  char *c_str = NULL;
  size_t len;
  if (argc == 2)
  {
    len = strlen(argv[1]) + 1;
    if (len > MAX_ALLOCATION)
    {
      return;
    }
    c_str = (char *)malloc(len);
    if (c_str == NULL)
    {
      return;
    }
    strcpy(c_str, argv[1]);
  }
  else
  {
    c_str = "usage: $>a.exe [string]";
    printf("%s\n", c_str);
  }
  free(c_str);
}

void mem_main(int argc, char **argv)
{
  struct node *p = malloc(sizeof(struct node));
  p->value = 1;
  p->next = NULL;
  func1(p);

  func2(argc, argv);

  char *c = "test";
  size_t size = 4;
  func3(c, size);

  func4(argc, argv);

  return;
}