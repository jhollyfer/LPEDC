// A098 · As gavetas de um vetor

#include <stdio.h>

int main(void) {
    int passos[4] = {8200, 10450, 6300, 12010}; // passos de 4 dias
    double km[4] = {5.7, 7.3, 4.4, 8.4};        // os mesmos dias, em km

    // num vetor as gavetas ficam coladas: cada uma começa onde a outra acaba
    for (int i = 0; i < 4; i++) {
        printf("passos[%d] em %p    km[%d] em %p\n",
               i, (void *)&passos[i], i, (void *)&km[i]);
    }
    printf("int: %zu bytes por gaveta; double: %zu bytes\n", sizeof passos[0], sizeof km[0]);
    printf("o vetor passos inteiro: %zu bytes\n", sizeof passos);
    return 0;
}
// Saída (os endereços mudam a cada execução; repare no final de cada um):
// passos[0] em 0x7fe2a0e00020    km[0] em 0x7fe2a0e00040
// passos[1] em 0x7fe2a0e00024    km[1] em 0x7fe2a0e00048
// passos[2] em 0x7fe2a0e00028    km[2] em 0x7fe2a0e00050
// passos[3] em 0x7fe2a0e0002c    km[3] em 0x7fe2a0e00058
// int: 4 bytes por gaveta; double: 8 bytes
// o vetor passos inteiro: 16 bytes
