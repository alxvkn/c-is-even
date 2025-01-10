#include <stdio.h>
#include <stdint.h>

#include <unistd.h>
#include <sys/wait.h>

#include "is_even.h"

int main() {
    for (unsigned i = 0; i <= UINT16_MAX; i++) {
        if (is_even(i) == (i % 2 == 0)) {
            printf("%5d ok\n", i);
        } else {
            printf("%d fail\n", i);
            return -1;
        }
    }

    puts("ok");
    return 0;
}
