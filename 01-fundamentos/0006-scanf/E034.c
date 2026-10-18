// 0006 · scanf
// Exercício E034 · ★★☆
//
// A lanchonete pergunta quantos lanches e se é para viagem (V) ou para comer
// aqui (A). Este programa compila sem aviso, mas não funciona: rode com
// printf '3\nV\n' | ~/LPEDC/rodar E034.c e veja a opção sair vazia. Explique
// o que aconteceu e conserte mudando UM caractere.
//
//   Saída esperada (depois de consertar), com 3 e V:
//   Quantidade: Opção (V/A): 3 lanche(s), opção V (código 86)
//
// Dicas:
// 1. O código mostrado na saída errada é 10. Que caractere tem código 10?
// 2. Depois do 3 você apertou Enter. Quem leu esse Enter?
// 3. Resposta esperada: o %d leu o 3 e deixou o '\n' na fila; o %c, que não
//    pula nada, leu o '\n' (código 10). Conserto: scanf(" %c", &opcao), com
//    um espaço antes do %c, que manda pular espaços e Enters.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int quantidade = 0;
    char opcao = '?';

    printf("Quantidade: ");
    scanf("%d", &quantidade);
    printf("Opção (V/A): ");
    scanf("%c", &opcao);

    printf("%d lanche(s), opção %c (código %d)\n", quantidade, opcao, opcao);
    return 0;
}
