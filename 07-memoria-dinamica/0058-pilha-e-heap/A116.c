// A116 · O mapa da memória

#include <stdio.h>
#include <stdlib.h>

int global = 10;     // DADOS (inicializada)
static int contador; // DADOS (zerada, numa parte chamada .bss)

void mostrar_local_da_funcao(void) {
    int fundo = 0; // PILHA: um frame acima do de main
    printf("pilha (função): %p\n", (void *)&fundo);
}

int main(void) {
    const char *frase = "bom dia"; // o texto fica numa área só de leitura
    int local = 20;                // PILHA
    int *bloco = malloc(sizeof(int)); // HEAP
    if (bloco == NULL) {
        return 1;
    }

    printf("literal:        %p\n", (void *)frase);
    printf("global:         %p\n", (void *)&global);
    printf("static:         %p\n", (void *)&contador);
    printf("heap:           %p\n", (void *)bloco);
    printf("pilha (main):   %p\n", (void *)&local);
    mostrar_local_da_funcao();

    free(bloco);
    return 0;
}
// Saída com gcc puro (gcc A116.c -o mapa && ./mapa). Os endereços mudam a
// cada execução; repare na ordem:
// literal:        0x563b12ef101a   <- perto do código, endereços baixos
// global:         0x563b12ef3010
// static:         0x563b12ef3018
// heap:           0x563b3719d2a0   <- logo acima dos dados
// pilha (main):   0x7ffe9c6f2914   <- lá no alto
// pilha (função): 0x7ffe9c6f28f4   <- frame novo, endereço MENOR
//
// Com o rodar, o heap aparece em 0x5020... e as locais em 0x7f...: o
// AddressSanitizer troca o heap e a pilha por versões próprias, vigiadas.
