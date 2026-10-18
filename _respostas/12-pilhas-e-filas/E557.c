// 0093 · Juntando tudo: a calculadora de expressões
// Exercício E557 · ★★★

#include <stdio.h>
// Na pasta do assunto basta incluir os .h (o rodar compila o pilha.c e o
// fila.c junto). Aqui a resolução inclui as implementações para compilar
// sozinha.
#include "../../12-pilhas-e-filas/0093-juntando-tudo/fila.c"
#include "../../12-pilhas-e-filas/0093-juntando-tudo/pilha.c"

#define VAGAS 4

int main(void) {
    char tipo[] = "EEEEESSSSS";
    int carro[] = {1, 2, 3, 4, 5, 2, 1, 4, 3, 5};
    int manobras[6] = {0};

    Pilha *beco = pilha_cria();
    Pilha *rua = pilha_cria();
    Fila *espera = fila_cria();
    if (beco == NULL || rua == NULL || espera == NULL) {
        return 1; // (num programa maior, libere o que foi criado)
    }

    for (int i = 0; tipo[i] != '\0'; i++) {
        int c = carro[i];
        if (tipo[i] == 'E') {
            if (pilha_tamanho(beco) < VAGAS) {
                pilha_empilha(beco, c);
            } else {
                fila_insere(espera, c);
                printf("Carro %d espera na rua\n", c);
            }
            continue;
        }
        // saída: tira da frente quem estiver bloqueando
        int x;
        while (pilha_desempilha(beco, &x) && x != c) {
            manobras[x]++;
            pilha_empilha(rua, x);
        }
        printf("Carro %d saiu; manobras: %d\n", c, manobras[c]);
        while (pilha_desempilha(rua, &x)) { // voltam na mesma ordem
            pilha_empilha(beco, x);
        }
        if (fila_retira(espera, &x)) { // abriu vaga: entra o primeiro da fila
            pilha_empilha(beco, x);
            printf("Carro %d entrou (vinha da fila)\n", x);
        }
    }

    pilha_libera(beco);
    pilha_libera(rua);
    fila_libera(espera);
    return 0;
}
