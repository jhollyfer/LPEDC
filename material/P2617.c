// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2617 · ★★☆ · CPF repetido no cadastro
//
// O cadastro da academia tem 5000 sócios, cada um com um código de 0 a
// 9999 (gerado no programa). Existe código repetido? Escreva duas versões,
// contando passos e bytes extras:
// - pares: compara todos os pares i < j, para no primeiro repetido;
// - tabela: um vetor de 10000 char (calloc) marca os códigos já vistos;
//   para no primeiro que já estava marcado.
// Mostre o primeiro código repetido que cada uma acha (pela ordem em que
// acham), os passos e os bytes:
//
//   Saída esperada:
//   pares:  repetido 8249,   15994 passos,     0 bytes
//   tabela: repetido 3716,      81 passos, 10000 bytes
//
// Dicas:
// 1. Na versão pares, o "primeiro" é o primeiro j para o menor i que tem par.
// 2. Na tabela, um passo por sócio olhado; os bytes são 10000.
// 3. Θ(n²) e Θ(1) de espaço contra Θ(n) e Θ(k) de espaço, com k = 10000
//    códigos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o programa):

#include <stdio.h>
#include <stdlib.h>

#define N 5000
#define K 10000

unsigned semente = 77;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    static int codigo[N];
    for (int i = 0; i < N; i++) {
        codigo[i] = sorteia(K);
    }
    // seu código aqui: as duas versões
    printf("primeiro sócio: código %d\n", codigo[0]);
    return 0;
}
