// 0085 · Fila
// Exercício E505 · ★☆☆
//
// Faça o teste de mesa de uma fila circular como a do fila.c, mas com
// CAPACIDADE 4. Para cada operação, anote o vetor (use _ para gaveta nunca
// usada), inicio e n. Quando uma inserção for recusada, diga por quê.
//
//   insere 1, insere 2, retira, insere 3, insere 4,
//   insere 5, insere 6, retira, retira
//
// No fim: quem sobrou na fila, na ordem de saída? Em que gaveta entraria o
// próximo?
//
// Dicas:
// 1. A posição de inserção é (inicio + n) % 4; retirar faz
//    inicio = (inicio + 1) % 4.
// 2. Retirar não apaga a gaveta: o valor velho fica lá.
// 3. Resposta esperada: o 5 entra na gaveta 0 (deu a volta) e o vetor fica
//    [5, 2, 3, 4] com inicio 1 e n 4; o 6 é recusado (n == 4, cheia). As
//    retiradas finais devolvem 2 e 3. Sobram 4 e 5, com inicio 3 e n 2; o
//    próximo entraria na gaveta (3 + 2) % 4 = 1.
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
