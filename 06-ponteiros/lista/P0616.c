// Lista · Módulo 06 · Ponteiros
// Exercício P0616 · ★★☆ · Ordem alfabética sem ligar para maiúsculas
//
// A lista de convidados foi digitada de qualquer jeito:
//
//   const char *convidados[6] = {"bruna", "Ademir", "carlos", "Beatriz",
//                                "ana", "Caio"};
//
// Com strcmp, as maiúsculas vêm antes de todas as minúsculas ('Z' é 90 e 'a'
// é 97). Escreva int compara_sem_caixa(const char *a, const char *b), que
// compara letra a letra com tolower, andando com os dois ponteiros, e use-a
// numa função de comparação para o qsort. Mostre a lista nas duas ordens:
//
//   Saída esperada:
//   strcmp: Ademir Beatriz Caio ana bruna carlos
//   sem caixa: Ademir ana Beatriz bruna Caio carlos
//
// Dicas:
// 1. Enquanto *a != '\0' e tolower(*a) == tolower(*b), avance os dois. No
//    fim, devolva tolower(*a) - tolower(*b) (use unsigned char nos
//    tolower).
// 2. A comparação do qsort recebe o endereço de cada GAVETA (um const char
//    **): const char *x = *(const char **) pa;
// 3. Escreva duas comparações (uma com strcmp e outra com a sua) e ordene uma
//    cópia do vetor para cada.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    const char *convidados[6] = {"bruna", "Ademir", "carlos", "Beatriz",
                                 "ana", "Caio"};
    (void) convidados; // apague esta linha quando escrever

    return 0;
}
