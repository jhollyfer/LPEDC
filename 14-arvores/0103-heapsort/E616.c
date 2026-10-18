// 0103 · Heapsort
// Exercício E616 · ★★☆
//
// O heapsort percebe quando o vetor já vem arrumado? Meça. Modifique desce
// para devolver quantas trocas fez e complete testa(nome, v, n): ela roda o
// heapsort somando as trocas do desce em cada fase (a troca do v[0] com o
// v[fim] da fase 2 não entra na conta) e mostra os totais e o vetor final.
// O main testa um vetor crescente, um decrescente e um com tudo igual:
//
//   Saída esperada:
//   crescente:   fase 1: 4 trocas, fase 2: 6 trocas -> 1 2 3 4 5 6 7
//   decrescente: fase 1: 0 trocas, fase 2: 5 trocas -> 1 2 3 4 5 6 7
//   iguais:      fase 1: 0 trocas, fase 2: 0 trocas -> 5 5 5 5 5 5 5
//
// Dicas:
// 1. Em desce, crie int trocas = 0, some 1 a cada troca e devolva no fim
//    (troque o void por int).
// 2. Em testa, faça fase1 += desce(v, n, i) no laço dos pais e
//    fase2 += desce(v, fim, 0) no laço da fase 2. Para o rótulo alinhado,
//    use printf("%-12s ...", nome).
// 3. Resposta esperada: a saída acima. Vetor crescente é o "contrário" de um
//    heap: a fase 1 trabalha. O decrescente já é heap, mas a fase 2 trabalha
//    do mesmo jeito: o heapsort não aproveita a ordem que o vetor já tinha.
//
// Escreva sua resposta abaixo (modifique desce e complete testa):

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void testa(const char *nome, int v[], int n) {
    (void)nome; // apague estas três linhas quando escrever a função
    (void)v;
    (void)n;
}

int main(void) {
    int crescente[] = {1, 2, 3, 4, 5, 6, 7};
    int decrescente[] = {7, 6, 5, 4, 3, 2, 1};
    int iguais[] = {5, 5, 5, 5, 5, 5, 5};

    testa("crescente:", crescente, 7);
    testa("decrescente:", decrescente, 7);
    testa("iguais:", iguais, 7);
    return 0;
}
