// 0041 · Juntando tudo: o caixa da lanchonete
// Exercício E241 · ★☆☆
//
// Escreva "int ler_inteiro_entre(int min, int max)", que pede um número e
// insiste até ele estar entre min e max. Se o scanf falhar (entrada acabou ou
// não é número), devolva min. Use-a para ler uma nota de 0 a 10 e uma
// quantidade de 1 a 5, e mostre as duas.
//
//   Exemplo de uso:
//   Valor entre 0 e 10: 15
//   Valor entre 0 e 10: 8
//   Valor entre 1 e 5: 0
//   Valor entre 1 e 5: 3
//   Nota 8, quantidade 3
//
// Para testar sem digitar:
//   printf '15\n8\n0\n3\n' | ~/LPEDC/rodar 04-funcoes/0041-juntando-tudo/E241.c
//
// Dicas:
// 1. do { printf(...); lidos = scanf("%d", &valor); if (lidos != 1) return min; }
//    while (valor < min || valor > max);
// 2. A mensagem usa os parâmetros: printf("Valor entre %d e %d: ", min, max).
// 3. Resposta esperada: com a entrada acima, "Nota 8, quantidade 3". A mesma
//    função serve para as duas leituras: é para isso que parâmetros existem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
