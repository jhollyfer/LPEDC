// 0073 · Invariantes de laço e corretude
// Exercício E438 · ★★★
//
// O vetor de pedidos do dia tem valores em reais, e os cancelados aparecem
// como 0. Escreva int remove_zeros(int v[], int n), que tira os zeros do
// vetor, mantendo a ordem dos outros, e devolve quantos sobraram. Regras:
// sem vetor auxiliar e numa passada só (O(n)).
//
// Escreva o invariante do seu laço como comentário e confira com o vetor
// {25, 0, 0, 40, 0, 15, 30, 0}.
//
//   Saída esperada:
//   Sobraram 4: 25 40 15 30
//
// Dicas:
// 1. Use dois índices: j lê todos os elementos; i marca onde escrever o
//    próximo que não é zero.
// 2. Invariante: i <= j e v[0..i-1] são os valores não nulos de v[0..j-1]
//    original, na mesma ordem.
// 3. Se v[j] != 0, copie para v[i] e avance i. Avance j sempre.
// 4. Resposta esperada: Sobraram 4: 25 40 15 30. Uma versão que "puxa" todo
//    mundo uma casa para a esquerda a cada zero também funciona, mas é O(n²).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
