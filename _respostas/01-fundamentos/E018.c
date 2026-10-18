// 0003 · Tipos e limites
// Exercício E018 · ★★★

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int8_t com_sinal = -1;
    uint8_t sem_sinal = com_sinal;   // mesmos bits: 1111 1111
    printf("%d -> %d (0x%X)\n", com_sinal, sem_sinal, sem_sinal);

    com_sinal = -128;
    sem_sinal = com_sinal;           // 1000 0000
    printf("%d -> %d (0x%X)\n", com_sinal, sem_sinal, sem_sinal);

    com_sinal = 127;
    sem_sinal = com_sinal;           // 0111 1111
    printf("%d -> %d (0x%X)\n", com_sinal, sem_sinal, sem_sinal);

    com_sinal = 0;
    sem_sinal = com_sinal;
    printf("%d -> %d (0x%X)\n", com_sinal, sem_sinal, sem_sinal);

    printf("int8_t: %d a %d\n", INT8_MIN, INT8_MAX);
    return 0;
}
