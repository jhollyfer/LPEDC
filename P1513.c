// Lista · Módulo 15 · Tabelas hash
// Exercício P1513 · ★★☆ · Quantos pares fecham o vale-presente
//
// Você ganhou um vale de R$ 100 e quer saber quantos PARES de produtos da
// vitrine custam exatamente R$ 100 juntos. Os preços (com repetidos) são
// 20, 30, 50, 30, 70, 20, 80, 50, 45. Conte os pares i < j em O(n) com uma
// tabela hash que guarda, para cada preço, QUANTAS VEZES ele já apareceu:
// para cada preço p, na ordem, some à resposta quantos (100 - p) já foram
// vistos e só então registre p.
//
// Use endereçamento aberto com m = 17 e sondagem linear, em dois vetores
// globais: int chave[17] (VAZIO = -1) e int vezes[17]. Mostre cada preço que
// fecha algum par e, no fim, compare com a força bruta (dois laços).
//
//   Saída esperada:
//   R$ 70 com os R$ 30 anteriores: +2
//   R$ 80 com os R$ 20 anteriores: +2
//   R$ 50 com os R$ 50 anteriores: +1
//   pares com hash: 5, força bruta: 5
//
// Dicas:
// 1. Escreva posicao(k), que devolve onde k está ou onde ele entraria;
//    quantas(k) e soma_um(k) usam essa mesma função.
// 2. Registrar DEPOIS de consultar evita contar o par (j, j): o segundo 50
//    acha só o primeiro.
// 3. A força bruta é O(n²); a versão com hash é O(n) em média.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 17
#define VAZIO -1

int chave[M], vezes[M];

int main(void) {

    return 0;
}
