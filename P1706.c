// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1706 · ★☆☆ · O desfazer do editor: pilha com multipop
//
// Um editor de texto guarda cada tecla digitada numa pilha. "Desfazer k"
// tira k teclas de uma vez (ou todas, se houver menos de k): é o MULTIPOP. O
// custo real de empilhar é 1, e o de desfazer k é min(k, tamanho da pilha).
//
// Complete int multipop(Pilha *p, int k), que devolve quantas teclas tirou,
// e rode a sessão do esqueleto mostrando o custo de cada operação, o maior
// custo de uma operação só, o custo total e o limite 2 · (empilhamentos) da
// análise amortizada.
//
//   Saída esperada:
//   digita "manaux" custo  6 | texto: "manaux"
//   desfaz 1        custo  1 | texto: "manau"
//   digita "s! ok"  custo  5 | texto: "manaus! ok"
//   desfaz 12       custo 10 | texto: ""
//   digita "oi"     custo  2 | texto: "oi"
//   desfaz 1        custo  1 | texto: "o"
//   Empilhadas 13, tiradas 12, total 25 (limite 2 x 13 = 26)
//   Operação mais cara: 10
//
// Dicas:
// 1. multipop: enquanto k > 0 e a pilha não estiver vazia, tire o topo e
//    diminua k. Devolva quantas saíram.
// 2. Uma operação isolada pode custar muito (o "desfazer 12" custa 10), mas
//    cada tecla só sai da pilha se entrou antes: o total de pops não passa
//    do total de pushes.
// 3. Por isso n operações custam no máximo 2n: custo amortizado O(1).
// 4. Resposta esperada: 13 teclas empilhadas, 12 tiradas, total 25, dentro
//    do limite 26; a operação mais cara custou 10.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char item[MAX];
    int topo; // quantos itens há
} Pilha;

void empilha(Pilha *p, char c) { p->item[p->topo++] = c; }

int multipop(Pilha *p, int k) {
    (void)p; // apague e escreva a função
    (void)k;
    return 0;
}

int main(void) {
    Pilha p = {.topo = 0};
    const char *sessao[] = {"manaux", "-1", "s! ok", "-12", "oi", "-1"}; // "-k" = desfazer k

    for (int i = 0; i < 6; i++) printf("%s\n", sessao[i]);
    (void)p; // apague esta linha
    return 0;
}
