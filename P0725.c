// Lista · Módulo 07 · Memória dinâmica
// Exercício P0725 · ★★★ · Conserte a lista de convidados
//
// O programa da festa junina guarda os nomes dos convidados em cópias no
// heap e um vetor de ponteiros, também no heap. Ele tem TRÊS erros de
// propósito. O gcc desconfia de dois (leia os warnings) e o AddressSanitizer
// acusa o terceiro assim que o programa roda. Conserte os três sem mudar a
// ideia
// do programa. Ele deve mostrar:
//
//   Saída esperada:
//   1. Zefinha
//   2. Tião
//   3. Mariazinha
//   4. Chico Bento
//   4 convidados
//
// Dicas:
// 1. O vetor guarda char *, então cada casa tem sizeof(char *) bytes (8),
//    e não sizeof(char) (1). Use n * sizeof *lista.
// 2. Uma função não pode devolver o endereço de um vetor local: ele some no
//    return. A cópia tem que ir para o heap: malloc(strlen(s) + 1).
// 3. Liberar o vetor e DEPOIS ler lista[i] para liberar cada nome é ler
//    memória já devolvida. A ordem é: cada nome, e só então o vetor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copia(const char *s) {
    char buf[32];
    strcpy(buf, s);
    return buf;
}

int main(void) {
    const char *nomes[4] = {"Zefinha", "Tião", "Mariazinha", "Chico Bento"};
    int n = 4;
    char **lista = malloc(n * sizeof(char));
    if (lista == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        lista[i] = copia(nomes[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, lista[i]);
    }
    printf("%d convidados\n", n);

    free(lista);
    for (int i = 0; i < n; i++) {
        free(lista[i]);
    }
    return 0;
}
