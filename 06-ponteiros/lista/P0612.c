// Lista · Módulo 06 · Ponteiros
// Exercício P0612 · ★★☆ · O qsort numa matriz de char
//
// Os bairros de Manaus estão numa matriz de char (cada linha é uma string de
// até 19 letras), não num vetor de ponteiros:
//
//   char bairros[6][20] = {"Flores", "Adrianopolis", "Compensa",
//                          "Aleixo", "Educandos", "Cachoeirinha"};
//
// Ordene com qsort em ordem alfabética. Cuidado: aqui cada elemento é uma
// LINHA de 20 bytes, não um char *. O tamanho do elemento é sizeof
// bairros[0], e o que chega na comparação é o endereço do primeiro char da
// linha. Mostre também quantos bytes o qsort move a cada troca:
//
//   Saída esperada:
//   1. Adrianopolis
//   2. Aleixo
//   3. Cachoeirinha
//   4. Compensa
//   5. Educandos
//   6. Flores
//   Cada elemento tem 20 bytes
//
// Dicas:
// 1. int compara(const void *a, const void *b) { return strcmp((const char *)
//    a, (const char *) b); } — o endereço da linha JÁ é o endereço da string.
// 2. Compare com o vetor de ponteiros (const char *v[]): lá o elemento é um
//    ponteiro, e a comparação precisa de *(const char **) a.
// 3. qsort(bairros, 6, sizeof bairros[0], compara);
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char bairros[6][20] = {"Flores", "Adrianopolis", "Compensa",
                           "Aleixo", "Educandos", "Cachoeirinha"};
    (void) bairros; // apague esta linha quando escrever

    return 0;
}
