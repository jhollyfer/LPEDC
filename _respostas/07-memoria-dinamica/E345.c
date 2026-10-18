// 0058 · Pilha e heap
// Exercício E345 · ★★☆
//
// Por que cabem menos chamadas na prática: cada frame guarda também o
// endereço de retorno, registros salvos e outras locais; e a pilha já tem o
// frame de main e as variáveis de ambiente antes da primeira chamada.

#include <stdio.h>

int main(void) {
    size_t pilha = 8 * 1024 * 1024;     // 8 MiB
    size_t por_chamada = 2000 * sizeof(int);

    printf("Cada chamada usa pelo menos %zu bytes\n", por_chamada);
    printf("Cabem no máximo %zu chamadas\n", pilha / por_chamada);
    return 0;
}
// Saída:
// Cada chamada usa pelo menos 8000 bytes
// Cabem no máximo 1048 chamadas
