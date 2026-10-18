// 0075 · Vetor dinâmico
// Exercício E448 · ★★☆
//
// Existem dois jeitos de tirar um item do meio de uma lista sequencial:
//
//   deslocando: puxa todos os de depois uma casa para a esquerda (mantém a
//               ordem; custa O(n))
//   trocando:   copia o ÚLTIMO item para o buraco e diminui o tamanho
//               (bagunça a ordem; custa O(1))
//
// Escreva as duas funções. Cada uma recebe o vetor, o endereço do tamanho e
// a posição, e devolve quantos itens precisou mover. Teste tirando a posição
// 2 de duas cópias das senhas 101 a 108:
//
//   Saída esperada:
//   deslocando: [101, 102, 104, 105, 106, 107, 108]  movimentos: 5
//   trocando:   [101, 102, 108, 104, 105, 106, 107]  movimentos: 1
//
// Depois responda: qual das duas você usaria para a fila de senhas do
// posto de saúde? E para os itens de um carrinho de compras?
//
// Dicas:
// 1. Assinatura sugerida: int remove_deslocando(int v[], int *n, int pos).
// 2. Ao final, as duas fazem (*n)--.
// 3. Resposta esperada: a saída acima. Na fila, a ordem é a regra do jogo:
//    deslocando. No carrinho, a ordem não importa: trocando, que é O(1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
