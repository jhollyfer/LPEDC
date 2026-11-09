// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2817 · ★★☆ · Quem é estável?
//
// Os pedidos do delivery chegam com número (1 a 8, a ordem de chegada) e
// bairro (código 1 a 3): (1,2) (2,1) (3,2) (4,3) (5,1) (6,3) (7,2) (8,1).
// Ordene cópias pelo bairro com a inserção, com a seleção e com o pigeonhole
// (uma fila por bairro), e escreva estavel(v, n): entre vizinhos de mesmo
// bairro, o número de chegada tem que crescer. Mostre cada resultado como
// numero:bairro e o veredito.
//
//   Saída esperada:
//   inserção:   2:1 5:1 8:1 1:2 3:2 7:2 4:3 6:3 | estável
//   seleção:    2:1 5:1 8:1 1:2 7:2 3:2 4:3 6:3 | não estável
//   casas:      2:1 5:1 8:1 1:2 3:2 7:2 4:3 6:3 | estável
//
// Dicas:
// 1. A seleção troca o menor com a posição i e pode pular por cima de
//    iguais.
// 2. Para o pigeonhole, três vetores (início, fim e próximo) como no
//    pombal.c, ou simplesmente passe 3 vezes pela entrada, uma por bairro,
//    copiando na ordem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
