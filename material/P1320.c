// Lista · Módulo 13 · Busca e ordenação
// Exercício P1320 · ★★☆ · Um selection sort estável
//
// Na lotérica, a fila foi anotada em ordem de chegada com a prioridade de
// cada cliente (1 = mais urgente): A3, B2, C3, D1, E2, F1. O selection sort
// abaixo ordena por prioridade, mas embaralha a ordem de chegada entre
// empatados (o E passa na frente do B).
//
// Escreva selection_estavel: ache o menor de v[i..n-1] como antes, mas em vez
// de TROCAR, guarde o menor, empurre v[i..menor-1] uma casa para a direita e
// grave o menor em v[i]. Ordene uma cópia com cada versão e mostre as duas.
//
//   Saída esperada:
//   com troca  : D1 F1 E2 B2 C3 A3
//   deslocando : D1 F1 B2 E2 A3 C3
//
// Dicas:
// 1. O deslocamento é o mesmo do insertion: for (k = menor; k > i; k--)
//    v[k] = v[k - 1];
// 2. Como o menor é o PRIMEIRO menor (< e não <=), quem empatou com ele e
//    veio antes já saiu; quem vem depois continua depois.
// 3. O preço: em vez de 1 troca por passada, até n - i movimentos. O
//    selection perde a sua única vantagem (poucas escritas).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

typedef struct {
    char nome[8];
    int prioridade;
} Cliente;

void mostra(const char *rotulo, const Cliente v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %s%d", v[i].nome, v[i].prioridade);
    }
    printf("\n");
}

void selection_troca(Cliente v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].prioridade < v[menor].prioridade) {
                menor = j;
            }
        }
        Cliente t = v[i];
        v[i] = v[menor];
        v[menor] = t;
    }
}

void selection_estavel(Cliente v[], int n) {
    // complete aqui
    (void)v;
    (void)n;
}

int main(void) {
    // ordem de chegada
    Cliente fila[] = {{"A", 3}, {"B", 2}, {"C", 3}, {"D", 1}, {"E", 2}, {"F", 1}};
    int n = 6;
    Cliente a[6], b[6];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = fila[i];
    }

    selection_troca(a, n);
    selection_estavel(b, n);
    mostra("com troca  ", a, n);
    mostra("deslocando ", b, n);
    return 0;
}
