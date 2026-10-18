// 0126 · Permutações
// Exercício E754 · ★★☆
//
// Cinco atletas correm a final: Ana, Bia, Cris, Dani e Edu. O programa abaixo
// conta todas as ordens de chegada (5! = 120). Mas a premiação só liga para
// o PÓDIO: ouro, prata e bronze, nessa ordem. Estenda o programa para contar
// os pódios possíveis e quantos deles têm a Bia (em qualquer dos três
// lugares). Não gere as 120 ordens e depois filtre: pare a recursão quando
// as 3 primeiras posições estiverem decididas.
//
//   Saída esperada:
//   120 ordens de chegada
//   60 pódios possíveis
//   Bia aparece em 36
//
// Dicas:
// 1. Escreva uma segunda função, podios(v, i), igual a ordens, mas com a
//    folha em i == 3 em vez de i == N. Isso é um ARRANJO: 5 × 4 × 3 = 60.
// 2. Na folha, olhe só v[0], v[1] e v[2] para saber se a Bia está lá.
// 3. Confira a conta: pódios sem a Bia são 4 × 3 × 2 = 24, e 60 - 24 = 36.
// 4. Resposta esperada: as 3 linhas acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>
#include <string.h>

#define N 5

int contagem = 0;

void troca(const char **a, const char **b) {
    const char *t = *a;
    *a = *b;
    *b = t;
}

void ordens(const char *v[], int i) {
    if (i == N) {
        contagem++;
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);
        ordens(v, i + 1);
        troca(&v[i], &v[j]);
    }
}

int main(void) {
    const char *atletas[N] = {"Ana", "Bia", "Cris", "Dani", "Edu"};
    ordens(atletas, 0);
    printf("%d ordens de chegada\n", contagem);
    return 0;
}
