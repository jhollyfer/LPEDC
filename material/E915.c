// 0153 · Prim: a árvore que cresce
// Exercício E915 · ★★☆
//
// Seis estações de bicicleta (índices 0 a 5: Rodoviária, Praça, Museu, Orla,
// Feira e Estádio) podem ser ligadas por ciclovias de mão dupla, com a
// distância em km:
//
//   Rodoviária-Praça 5   Rodoviária-Feira 3   Praça-Museu 4   Praça-Feira 6
//   Museu-Orla 2         Feira-Orla 7         Orla-Estádio 8  Museu-Estádio 9
//   Feira-Estádio 10
//
// Começar o Prim por outra estação muda alguma coisa? Escreva prim(origem), na
// versão sem heap (O(V²)), que mostra a origem, a ordem em que as estações
// entram na rede e o total, e chame-a para cada uma das seis origens.
//
//   Saída esperada:
//   Rodoviária: Rodoviária Feira Praça Museu Orla Estádio | 22
//   Praça: Praça Museu Orla Rodoviária Feira Estádio | 22
//   Museu: Museu Orla Praça Rodoviária Feira Estádio | 22
//   Orla: Orla Museu Praça Rodoviária Feira Estádio | 22
//   Feira: Feira Rodoviária Praça Museu Orla Estádio | 22
//   Estádio: Estádio Orla Museu Praça Rodoviária Feira | 22
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define INFINITO INT_MAX

int main(void) {

    return 0;
}
