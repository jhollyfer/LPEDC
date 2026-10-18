// 0053 · Pilha e heap
// Exercício E315 · ★★☆
//
// Na prática cabem menos chamadas: cada frame guarda também o endereço de
// retorno, registros salvos e outras locais; e a pilha já tem o frame de
// main e as variáveis de ambiente antes da primeira chamada.

#include <stdio.h>

int main(void) {
    size_t pilha = 8 * 1024 * 1024; // 8 MiB
    size_t com_int = 2000 * sizeof(int);
    size_t com_double = 2000 * sizeof(double);

    printf("int: cada chamada usa pelo menos %zu bytes\n", com_int);
    printf("int: cabem no máximo %zu chamadas\n", pilha / com_int);
    printf("double: cada chamada usa pelo menos %zu bytes\n", com_double);
    printf("double: cabem no máximo %zu chamadas\n", pilha / com_double);
    return 0;
}
// Saída:
// int: cada chamada usa pelo menos 8000 bytes
// int: cabem no máximo 1048 chamadas
// double: cada chamada usa pelo menos 16000 bytes
// double: cabem no máximo 524 chamadas
