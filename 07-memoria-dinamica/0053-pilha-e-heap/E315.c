// 0053 · Pilha e heap
// Exercício E315 · ★★☆
//
// No Linux, "ulimit -s" mostra o tamanho da pilha em KiB (em geral, 8192,
// ou seja, 8 MiB). Uma função recursiva guarda o histórico de preços de uma
// ação num vetor local: int historico[2000]; e chama a si mesma.
//
// Escreva um programa que calcule e mostre quantos bytes esse vetor ocupa em
// cada chamada e quantas chamadas, no máximo, cabem numa pilha de 8 MiB.
// Use sizeof para o tamanho do int e divisão inteira.
//
//   Saída esperada:
//   Cada chamada usa pelo menos 8000 bytes
//   Cabem no máximo 1048 chamadas
//
// Responda também: por que o número real de chamadas é um pouco menor?
//
// Dicas:
// 1. 8 MiB = 8 * 1024 * 1024 bytes.
// 2. sizeof devolve size_t; mostre com %zu.
// 3. Resposta esperada: 8000 bytes e 1048 chamadas (8388608 / 8000). Na
//    prática cabem menos: cada frame guarda também o endereço de retorno e
//    outras locais, e a pilha já tem o frame de main e as variáveis de
//    ambiente. Passou do limite, o programa morre com stack overflow.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
