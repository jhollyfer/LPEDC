// 0124 · Juntando tudo
// Exercício E739 · ★☆☆
//
// Use o TAD pix.h (está na pasta) para um teste pequeno antes de rodar com
// um milhão. Gere 8 Pix com pix_gera e a semente 5, ordene pelo horário com
// pix_por_horario e mostre a linha do tempo com pix_mostra. Depois ordene
// pelo valor com pix_por_valor e mostre o Pix de menor e o de maior valor.
//
//   Saída esperada:
//   linha do tempo:
//   #0000001 06:37:44 R$      46,82
//   #0000003 07:00:16 R$      71,08
//   #0000008 07:23:43 R$      88,39
//   #0000002 10:58:31 R$      14,80
//   #0000007 12:02:53 R$      50,89
//   #0000006 14:11:55 R$      87,07
//   #0000005 14:28:08 R$    3960,62
//   #0000004 15:23:46 R$      88,47
//   menor: #0000002 10:58:31 R$      14,80
//   maior: #0000005 14:28:08 R$    3960,62
//
// Dicas:
// 1. As duas ordenações pedem um vetor auxiliar do mesmo tamanho:
//    Pix v[8], aux[8];
// 2. pix_por_horario devolve false se não conseguir memória para os
//    contadores: confira.
// 3. pix_mostra já pula a linha; para o "menor: " ficar na mesma linha,
//    use printf sem \n antes.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pix.h"

int main(void) {

    return 0;
}
