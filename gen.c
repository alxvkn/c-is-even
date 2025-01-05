#include <stdio.h>
#include <stdint.h>

int main() {
    puts("#include <stdint.h>");
    puts("#include <stdbool.h>");
    puts("bool is_even(uint16_t n) {");

    for (unsigned i = 0; i <= UINT16_MAX; i += 2) {
        printf("    if (n == %d) return true;\n", i);
    }

    puts("    else return false;\n}");
}
