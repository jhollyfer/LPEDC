// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0513 · ★★☆ · Busca binária nos CEPs
//
// A transportadora guarda 10 CEPs de entrega em ordem crescente:
//
//   int ceps[10] = {69005010, 69020030, 69040000, 69050010, 69053000,
//                   69057040, 69060000, 69075351, 69083000, 69097290};
//
// Num vetor ORDENADO dá para buscar sem olhar um por um: compare com o do
// meio; se o procurado for menor, descarte a metade de cima; se for maior, a
// de baixo. Escreva int busca_binaria(const int v[], int n, int x, int
// passos[1]), que devolve a posição de x (ou -1) e guarda em passos[0]
// quantas comparações com o meio fez. Procure 69075351, 69005010 e 69099999:
//
//   Saída esperada:
//   CEP 69075351: posição 7 em 2 passos
//   CEP 69005010: posição 0 em 3 passos
//   CEP 69099999: não atendido (4 passos)
//
// Dicas:
// 1. Use ini = 0 e fim = n - 1. Enquanto ini <= fim: meio = (ini + fim) / 2.
// 2. Se v[meio] == x, achou. Se x < v[meio], fim = meio - 1; senão,
//    ini = meio + 1.
// 3. Conte um passo a cada volta do while (cada vez que olha o meio).
// 4. Com 10 itens, a busca linear chega a 10 comparações; a binária, no pior
//    caso, a 4.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int ceps[10] = {69005010, 69020030, 69040000, 69050010, 69053000,
                    69057040, 69060000, 69075351, 69083000, 69097290};
    (void) ceps; // apague esta linha quando escrever

    return 0;
}
