// Lista · Módulo 06 · Ponteiros
// Exercício P0625 · ★★★ · Conserte a escala de folgas
//
// O programa da escala de folgas tem TRÊS erros de propósito, e o gcc não
// avisa de nenhum. Ele deveria: trocar o primeiro e o último da equipe de
// lugar, ordenar a equipe em ordem alfabética e montar o crachá do primeiro
// da lista. Rode com o rodar e compare com a saída esperada: a troca não
// troca e a ordem sai errada. Conserte esses dois; aí o AddressSanitizer
// passa a acusar o terceiro (é comum um erro esconder o outro). No fim, o
// programa mostra:
//
//   Saída esperada:
//   Trocados: Wellington Rui Mirela Edson Joana
//   Em ordem: Edson Joana Mirela Rui Wellington
//   Crachá do último: Wellington
//
// Dicas:
// 1. A troca recebe cópias dos dois ponteiros: trocar as cópias não muda o
//    vetor. Ela precisa receber o endereço das gavetas (const char **).
// 2. No qsort de um vetor de const char *, cada elemento é um PONTEIRO: a
//    comparação recebe o endereço da gaveta e precisa de *(const char **) a
//    para chegar na string.
// 3. Conte as letras de "Wellington" e o tamanho do crachá.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(const char *a, const char *b) {
    const char *aux = a;
    a = b;
    b = aux;
}

int compara(const void *a, const void *b) {
    return strcmp((const char *) a, (const char *) b);
}

void mostrar(const char *titulo, const char **v, int n) {
    printf("%s:", titulo);
    for (int i = 0; i < n; i++) {
        printf(" %s", v[i]);
    }
    printf("\n");
}

int main(void) {
    const char *equipe[5] = {"Joana", "Rui", "Mirela", "Edson", "Wellington"};

    troca(equipe[0], equipe[4]);
    mostrar("Trocados", equipe, 5);
    qsort(equipe, 5, sizeof equipe[0], compara);
    mostrar("Em ordem", equipe, 5);

    char cracha[8];
    strcpy(cracha, equipe[4]);
    printf("Crachá do último: %s\n", cracha);
    return 0;
}
