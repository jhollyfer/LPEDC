// 0040 · Pré-processador: macros e #ifdef
// Exercício E240 · ★★★
//
// Monte um mini-framework de testes em C. Escreva a macro CONFERIR(cond), que mostra
// "ok: <cond>" se a condição for verdadeira e "FALHOU: <cond> (linha N)" se
// for falsa, contando as falhas numa global. Use #cond para virar texto e
// __LINE__ para a linha. Teste a função "double com_desconto(double preco)",
// que dá 10% de desconto acima de R$ 100 (inclusive). No fim, mostre o número
// de falhas.
//
// Escreva os cinco testes abaixo, nesta ordem. O último está errado de
// propósito, para você ver a falha:
//
//   Saída esperada (o número da linha depende do seu arquivo):
//   ok: com_desconto(50) == 50
//   ok: com_desconto(100) == 90
//   ok: com_desconto(200) == 180
//   ok: com_desconto(0) == 0
//   FALHOU: com_desconto(150) == 150 (linha 42)
//   Falhas: 1
//
// Dicas:
// 1. Uma macro de várias linhas termina cada linha com "\". Dá para escrever
//    numa linha só: #define CONFERIR(cond) if (cond) printf(...); else { ... }
// 2. Aquele if solto dentro da macro quebra se alguém usar CONFERIR num
//    if/else sem chaves. O jeito profissional é embrulhar num
//    do { ... } while (0).
// 3. Resposta esperada: 4 ok, 1 falha (com 150 o certo é 135). É o que o
//    assert.h faz: assert(cond) para o programa com o texto e a linha da
//    condição que falhou.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
