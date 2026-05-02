#include <stdio.h>

#define FLAG1 (1 << 0) // bit 0
#define FLAG2 (1 << 1) // bit 1
#define FLAG3 (1 << 2) // bit 2

int main() {
    int flags = 0; //00000000

    // Ativar FLAG2
    flags |= FLAG2;
    printf("Flags: %d\n", flags); // 2

    // Ativar FLAG1
    flags |= FLAG1;
    printf("Flags: %d\n", flags); // 3

    // Verificar se FLAG2 está ativo
    if (flags & FLAG2) {
        printf("FLAG2 está ativo!\n");
    }

    return 0;
}
