// 0077 · Notação O: como o custo cresce
// Exercício E459 · ★★☆
//
// O cupom fiscal tem códigos de produto de 0 a 999. Você quer saber se algum
// código aparece repetido. Escreva duas funções que devolvem bool e contam
// passos (comparações ou consultas):
//
// - repetido_pares(v, n): compara cada par (i, j) com i < j. O(n²).
// - repetido_marcas(v, n): usa um vetor bool visto[1000] (todo false no
// começo); para cada código, consulta visto[codigo] e marca. O(n).
//
// Teste com n = 100 e n = 1000, com v[i] = (i * 37) % 1000 (que não tem
// repetidos: é o pior caso, as duas vão até o fim).
//
//   Saída esperada:
//   n =  100: pares   4950 passos, marcas  100 passos
//   n = 1000: pares 499500 passos, marcas 1000 passos
//
// Dicas:
// 1. Em repetido_marcas, o passo é cada consulta a visto[v[i]].
// 2. Para zerar o vetor de marcas: bool visto[1000] = {false};
// 3. A versão com marcas troca memória (1000 bools) por tempo. Funciona aqui
//    porque os códigos são pequenos; com CPFs, precisaria de outra ideia
//    (a tabela hash do módulo 15).
// 4. Resposta esperada: a saída acima; as duas respondem "sem repetidos".
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
