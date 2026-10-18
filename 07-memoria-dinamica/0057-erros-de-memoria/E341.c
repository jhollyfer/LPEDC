// 0057 · Erros de memória
// Exercício E341 · ★★★
//
// A lista de presença de uma aula de yoga começa com 2 vagas e a função
// adicionar faz o vetor crescer. Com o rodar, o programa quebra com um
// relatório do AddressSanitizer na 4ª chegada. O erro está de propósito.
// Explique por que o main fica com um ponteiro solto, mesmo que a função
// adicionar esteja "certa" por dentro. Conserte mudando a assinatura de
// adicionar.
//
//   Saída esperada depois do conserto:
//   Presentes: 11 27 35 48
//
// Dicas:
// 1. O parâmetro v é uma cópia do ponteiro do main (passagem por valor,
//    assunto 0029). O realloc muda a cópia, não o original.
// 2. Duas saídas: devolver o ponteiro novo (int *adicionar(...)) ou
//    receber o endereço do ponteiro (int **v, assunto 0049).
// 3. Resposta esperada: na 3ª chegada o realloc mudou o bloco de lugar e
//    liberou o antigo, mas só a cópia local v recebeu o endereço novo; o
//    alunos do main continua apontando para o bloco antigo, de 2 vagas e já
//    liberado. Na 4ª chegada, a função grava alunos[3] lá (o ASan acusa
//    heap-buffer-overflow, porque o endereço cai depois do fim do bloco
//    antigo; se caísse dentro, seria heap-use-after-free). Com
//    int adicionar(int **v, int *qtd, int *cap, int matricula) e
//    *v = maior; dentro, e adicionar(&alunos, ...) no main, a saída fica
//    "Presentes: 11 27 35 48".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

// Devolve 1 se deu certo, 0 se faltou memória.
int adicionar(int *v, int *qtd, int *cap, int matricula) {
    if (*qtd == *cap) {
        int *maior = realloc(v, 2 * *cap * sizeof *v);
        if (maior == NULL) {
            return 0;
        }
        v = maior;
        *cap *= 2;
    }
    v[*qtd] = matricula;
    (*qtd)++;
    return 1;
}

int main(void) {
    int qtd = 0;
    int cap = 2;
    int *alunos = malloc(cap * sizeof *alunos);
    if (alunos == NULL) {
        return 1;
    }
    int chegadas[] = {11, 27, 35, 48};
    for (int i = 0; i < 4; i++) {
        if (!adicionar(alunos, &qtd, &cap, chegadas[i])) {
            free(alunos);
            return 1;
        }
    }
    printf("Presentes:");
    for (int i = 0; i < qtd; i++) {
        printf(" %d", alunos[i]);
    }
    printf("\n");
    free(alunos);
    return 0;
}
