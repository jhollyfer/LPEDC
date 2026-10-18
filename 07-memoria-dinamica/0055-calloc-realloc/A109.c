// A109 · A lista que nasce do NULL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *itens[] = {"arroz", "leite", "banana", "ovos"};
    char *lista = NULL; // ainda não existe bloco nenhum
    size_t tamanho = 0; // bytes do bloco atual

    for (int i = 0; i < 4; i++) {
        // + 2 para o ", " entre os itens (só a partir do segundo);
        // + 1 para o '\0' entra só no primeiro, quando tamanho ainda é 0
        size_t extra = strlen(itens[i]) + (i == 0 ? 1 : 2);

        // realloc(NULL, n) funciona como malloc(n): a primeira volta cria o
        // bloco; as outras aumentam e PRESERVAM o que já estava escrito.
        char *maior = realloc(lista, tamanho + extra);
        if (maior == NULL) {
            free(lista);
            return 1;
        }
        lista = maior;
        if (i == 0) {
            lista[0] = '\0'; // bloco novo vem com lixo: vira string vazia
        } else {
            strcat(lista, ", ");
        }
        strcat(lista, itens[i]);
        tamanho += extra;
        printf("%2zu bytes: %s\n", tamanho, lista);
    }

    free(lista);
    return 0;
}
// Saída:
//  6 bytes: arroz
// 13 bytes: arroz, leite
// 21 bytes: arroz, leite, banana
// 27 bytes: arroz, leite, banana, ovos
//
// Cada linha tem strlen + 1 bytes, nem um a mais: o bloco cresce no tamanho
// exato de cada item. Começar com o ponteiro em NULL evita um malloc separado
// antes do laço.
