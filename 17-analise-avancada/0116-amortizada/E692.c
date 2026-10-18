// 0116 · Análise amortizada
// Exercício E692 · ★☆☆
//
// Para comparar estratégias de crescimento, nem precisa alocar memória:
// basta simular. Escreva duas funções que recebem o número de inserções n
// e devolvem quantas cópias as mudanças fariam:
//
// - copias_soma(n, passo): a capacidade começa em passo e, quando enche,
// cresce somando passo (10, 20, 30...);
// - copias_dobra(n): a capacidade começa em 1 e dobra quando enche.
//
// Em cada inserção, se tam == cap, a mudança copia os tam elementos e a
// capacidade cresce; depois tam aumenta. Mostre n = 1000, 10000, 100000
// com passo 10:
//
//   Saída esperada:
//        n      soma 10     dobra
//     1000        49500      1023
//    10000      4995000     16383
//   100000    499950000    131071
//
// Dicas:
// 1. As variáveis da simulação são só cap, tam e copias, todas long.
// 2. Multiplicar n por 10 multiplica as cópias do "soma 10" por 100: é a
//    marca do Θ(n²) no total.
// 3. Resposta esperada: a tabela acima. Com +10, cada inserção custa em
//    média n/20 cópias (O(n) amortizado); dobrando, menos de 2 (O(1)).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
