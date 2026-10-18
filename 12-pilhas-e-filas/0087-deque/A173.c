// A173 · Desfazer com limite: o deque esquece o mais antigo

#include <stdio.h>
#include "deque.h"

#define LIMITE 5 // o editor de fotos só lembra os 5 últimos passos

int main(void) {
    Deque *historico = deque_cria();
    if (historico == NULL) {
        return 1;
    }

    int brilho = 50;
    int ajustes[] = {55, 60, 65, 70, 75, 80, 85};
    for (int i = 0; i < 7; i++) {
        if (deque_tamanho(historico) == LIMITE) {
            int esquecido;
            deque_retira_inicio(historico, &esquecido); // o mais antigo sai pela frente
            printf("Esqueceu o brilho %d\n", esquecido);
        }
        deque_insere_fim(historico, brilho); // o valor antigo entra pelo fundo
        brilho = ajustes[i];
    }
    printf("Brilho atual: %d\n", brilho);

    // desfazer usa o fundo como uma pilha: o mais recente sai primeiro
    printf("Desfazendo:");
    while (deque_retira_fim(historico, &brilho)) {
        printf(" %d", brilho);
    }
    printf("\nNão dá para desfazer mais: o brilho fica em %d\n", brilho);

    deque_libera(historico);
    return 0;
}
// Saída:
// Esqueceu o brilho 50
// Esqueceu o brilho 55
// Brilho atual: 85
// Desfazendo: 80 75 70 65 60
// Não dá para desfazer mais: o brilho fica em 60
