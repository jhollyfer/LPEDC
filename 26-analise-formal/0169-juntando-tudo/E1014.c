// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1014 · ★★★
//
// A padaria tem as vendas de 1000 dias e recebe 1000 perguntas do tipo
// "quanto vendemos do dia ini ao dia fim?". Escreva, no main, os dois jeitos
// de responder, contando passos e bytes extras (o esqueleto já gera as vendas
// e as perguntas em ini e fim):
// - sem prefixos: para cada pergunta, some os dias de ini a fim (um passo
//   por dia somado). Θ(n·q) de tempo, Θ(1) de espaço.
// - com prefixos: monte com malloc um vetor prefixo de N + 1 long, com
//   prefixo[k] = soma dos k primeiros dias (um passo por dia), e responda
//   cada pergunta com prefixo[fim + 1] - prefixo[ini] (um passo por
//   pergunta). Θ(n + q) de tempo, Θ(n) de espaço.
// Mostre os dois resultados; os totais (a soma de todas as respostas) têm
// que bater:
//
//   Saída esperada:
//   sem prefixos:  335094 passos,     0 bytes, total 185862850
//   com prefixos:    2000 passos,  8008 bytes, total 185862850
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define Q 1000

int vendas[N], ini[Q], fim[Q];
unsigned semente = 99;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    for (int d = 0; d < N; d++) {
        vendas[d] = 100 + sorteia(900);  // vendas do dia, em reais
    }
    for (int q = 0; q < Q; q++) {
        int a = sorteia(N), b = sorteia(N);
        ini[q] = a < b ? a : b;
        fim[q] = a < b ? b : a;
    }

    return 0;
}
