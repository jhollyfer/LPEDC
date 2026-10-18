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
// a posição, e devolve quantos itens precisou mover (trocando move 1, ou 0
// quando a posição já é a última). Teste tirando a posição 2 de duas cópias
// das senhas 101 a 108. Depois, para sentir a diferença de custo, esvazie
// as duas cópias tirando SEMPRE a posição 0 e mostre o total de movimentos
// de cada uma:
//
//   Saída esperada:
//   deslocando: [101, 102, 104, 105, 106, 107, 108]  movimentos: 5
//   trocando:   [101, 102, 108, 104, 105, 106, 107]  movimentos: 1
//   esvaziando pela frente: deslocando 21, trocando 6
//
// Dicas:
// 1. Assinatura sugerida: int remove_deslocando(int v[], int *n, int pos).
// 2. Ao final, as duas fazem (*n)--.
// 3. Para esvaziar: while (n > 0) total += remove_xxx(v, &n, 0);
// 4. Resposta esperada: a saída acima. Deslocando, tirar da frente custa
//    6 + 5 + 4 + 3 + 2 + 1 + 0 = 21 movimentos (cresce como n²); trocando,
//    um por item, menos o último. Use deslocando quando a ordem importa
//    (fila de senhas) e trocando quando não importa (itens do carrinho).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
