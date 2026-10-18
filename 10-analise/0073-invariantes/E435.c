// 0073 · Invariantes de laço e corretude
// Exercício E435 · ★★☆
//
// A função ultima() procura a ÚLTIMA vez que um aluno tirou certa nota,
// andando do fim para o começo. Ela já funciona. Transforme a prova de que
// ela está certa em código:
//
// 1. escreva bool nao_esta(v, ini, fim, x), que devolve true se x não
// aparece em v[ini..fim-1] (pedaço vazio: true);
// 2. dentro do laço, confira com assert o invariante "x não está em
// v[k+1..n-1]";
// 3. depois do laço, confira com assert o término: ou k == -1, ou v[k] == x
// e o invariante ainda vale;
// 4. teste também a nota 7 (que está na posição 0) e um vetor vazio (n = 0).
//
//   Saída esperada:
//   última nota 9: posição 3
//   última nota 5: posição -1
//   última nota 7: posição 0
//   vetor vazio: posição -1
//
// Dicas:
// 1. No começo, k = n - 1: o pedaço v[n..n-1] é vazio, e nao_esta tem de
//    devolver true para ele.
// 2. Para o vetor vazio, basta chamar ultima(notas, 0, 9): o laço nem roda.
// 3. Não inverta a ordem do && no while: com v[k] != x && k >= 0, o k == -1
//    leria v[-1] antes de testar k (o sanitizer acusa).
// 4. Resposta esperada: a saída acima, sem nenhum assert disparando.
//
// Escreva sua resposta abaixo (complete o código):

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Recebe n >= 0, v e x; devolve o maior k tal que v[k] == x, ou -1 se não há.
int ultima(const int v[], int n, int x) {
    int k = n - 1;
    while (k >= 0 && v[k] != x) {
        k--;
    }
    return k;
}

int main(void) {
    int notas[5] = {7, 9, 4, 9, 6};

    printf("última nota 9: posição %d\n", ultima(notas, 5, 9));
    printf("última nota 5: posição %d\n", ultima(notas, 5, 5));
    return 0;
}
