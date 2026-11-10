// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2417 · ★★☆ · Várias palavras numa passada
//
// O Rabin-Karp tem uma vantagem quando há MUITOS padrões do mesmo tamanho:
// a janela rola uma vez só pelo texto, e cada hash é comparado com os
// hashes de todos os padrões. Escreva o programa do zero: base 256,
// Q = 1000003, padrões "caju", "acai", "cedo" e "doce" no texto do
// esqueleto. Mostre cada ocorrência na ordem do texto, o total de cada
// padrão e quantas conferências letra a letra foram feitas.
//
//   Saída esperada:
//   caju em 12
//   acai em 35
//   caju em 43
//   cedo em 67
//   caju: 2
//   acai: 1
//   cedo: 1
//   doce: 0
//   Janelas: 68; conferências letra a letra: 4
//
// Dicas:
// 1. Calcule os quatro hp[] antes do laço. Para cada janela, percorra os
//    padrões; só com ht == hp[p] faça o strncmp.
// 2. Use long long nas contas: 1000002 × 256 passa do limite de um int
//    de 32 bits.
// 3. Resposta esperada: caju 2, acai 1, cedo 1, doce 0; só 4 conferências
//    em 68 janelas (nenhum falso positivo).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *texto = "a feira tem caju, jambu, cupuacu e acai; o caju e o jambu acabaram cedo";
    printf("%d letras\n", (int)strlen(texto));
    return 0;
}
