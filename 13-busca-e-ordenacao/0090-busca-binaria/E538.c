// 0090 · Busca binária
// Exercício E538 · ★★☆
//
// Busca binária também funciona com strings, desde que estejam em ordem.
// Escreva int busca_nome(const char *v[], int n, const char *nome, int *voltas)
// e teste com as capitais abaixo, procurando "Natal" e "Palmas":
//
//   "Aracaju", "Belém", "Boa Vista", "Cuiabá", "Curitiba", "Florianópolis",
//   "Fortaleza", "Goiânia", "Maceió", "Manaus", "Natal", "Recife",
//   "Salvador", "São Paulo", "Teresina", "Vitória"
//
//   Saída esperada:
//   Natal: posição 10 (4 voltas)
//   Palmas: posição -1 (4 voltas)
//
// Dicas:
// 1. strcmp(a, b) devolve negativo se a vem antes, 0 se iguais, positivo se
//    a vem depois. É o "v[meio] < x" das strings.
// 2. Chame strcmp uma vez por volta e guarde o resultado num int.
// 3. Cuidado com acentos: strcmp compara BYTES. "Belo Horizonte" viria antes
//    de "Belém", porque o 'é' em UTF-8 começa com um byte maior que o 'o'.
//    Esta lista foi escolhida para não cair nessa armadilha.
// 4. Resposta esperada: a saída acima (meios 7, 11, 9 e 10 nas duas buscas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
