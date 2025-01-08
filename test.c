#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (unsigned short i = 0; i < UINT16_MAX; i++) {
        char command[32];
        sprintf(command, "./is_even %d", i);
        FILE* fd = popen(command, "r");

        char buffer[10];
        fgets(buffer, 10, fd);
        pclose(fd);

        int a = atoi(buffer);
        if (a != (i % 2 == 0)) {
            printf("%d fail\n", i);
            return -1;
        }
    }

    puts("ok");
    return 0;
}
