#include <stdio.h>
#include <stdlib.h>
#include "exp.h"
//EXP33
void set_flag(int number, int *sign_flag) {
    if (sign_flag == NULL) {
        return;
    }
    if (number > 0) {
        *sign_flag = 1;
    }
    else if (number < 0) {
        *sign_flag = -1;
    }
}

int is_negative(int number) {
    int sign;
    set_flag(number, &sign);
    return sign;
}

//EXP34
void f_exp(const char *input_str) {
    size_t size = strlen(input_str) + 1;
    char *c_str = (char *)malloc(size);
    memcpy(c_str, input_str, size);
    free(c_str);
    c_str = NULL;
}


void exp_main(int n) {
    printf("%d\n", is_negative(n));

    const char* instr = "test string";
    f_exp(instr);

    return;
}