#include <stdio.h>
#include <stdlib.h>

#include "is_even.h"

int main(int argc, char** argv) {
    if (argc < 2) return -1;
    printf("%b\n", is_even(atoi(argv[1])));
}
