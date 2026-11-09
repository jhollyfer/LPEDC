// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1925 · ★★★ · A poda que corta demais
//
// Este programa tem um erro de propósito. A ONG do bairro recebeu doações
// de cestas básicas com 18, 14, 11, 9, 7, 5 e 3 kg e quer montar um lote de
// exatamente 30 kg. O backtracking abaixo lista todos os lotes, com as
// cestas em ordem decrescente e uma poda "se a cesta i não cabe, pare". Ele
// compila sem aviso e roda limpo, mas acha só 1 lote. Conserte a poda sem
// tirá-la: ela ainda deve cortar o ramo de LEVAR a cesta que não cabe.
//
//   Saída esperada:
//   Lote 1: 18 9 3
//   Lote 2: 18 7 5
//   Lote 3: 14 11 5
//   Lote 4: 14 9 7
//   Lote 5: 11 9 7 3
//   Total: 5 lotes
//
// Dicas:
// 1. Acrescente um printf no começo de busca(i, soma) e veja: quando a
//    cesta de 14 não cabe junto com a de 18, o programa desiste de tudo,
//    inclusive de seguir SEM a de 14 e tentar a de 11.
// 2. Não caber a cesta i não impede que as próximas (menores) caibam. O
//    certo é pular só o ramo "levo a cesta i".
// 3. Resposta esperada: troque o return da poda por um if em volta do ramo
//    de levar. Saem os 5 lotes de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define N 7
#define ALVO 30

const int cesta[N] = {18, 14, 11, 9, 7, 5, 3};
int leva[N];
int lotes = 0;

void busca(int i, int soma) {
    if (soma == ALVO) {
        lotes++;
        printf("Lote %d:", lotes);
        for (int j = 0; j < N; j++) {
            if (leva[j]) {
                printf(" %d", cesta[j]);
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    if (soma + cesta[i] > ALVO) {
        return; // a cesta i não cabe: poda
    }
    leva[i] = 1;
    busca(i + 1, soma + cesta[i]);
    leva[i] = 0;
    busca(i + 1, soma);
}

int main(void) {
    busca(0, 0);
    printf("Total: %d lotes\n", lotes);
    return 0;
}
