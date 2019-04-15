#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include "exp.h"
#include "dcl.h"
#include "mem.h"
#include "msc.h"

int main(int argc, char **argv)
{
    dcl_main();
    exp_main(0);
    arr_main();
    mem_main(argc, argv);
    msc_main();

    return 0;
}