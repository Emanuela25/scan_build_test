#include <stdio.h>
#include <stdlib.h>
#include "dcl.h"
//DCL30
const char *p_dcl;

void dont_do_this() {
  const char c_str[] = "This will change";
  p_dcl = c_str; /* Dangerous */
}

void innocuous() {
  printf("%s\n", p_dcl);
}

void dcl_main() {
    dont_do_this();
    innocuous();
}
