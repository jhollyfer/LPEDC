// 0058 · Juntando tudo
// Exercício E344 · ★☆☆
//
// Escreva duas funções para a lista de compras:
//
//   char **criar_lista(const char *itens[], int n);
//   void liberar_lista(char **lista, int n);
//
// criar_lista aloca um vetor de n ponteiros e uma cópia de cada item. Teste
// com "pao", "leite", "cafe" e "manteiga", mostre a lista e calcule quantos
// blocos e quantos bytes foram pedidos ao heap (num PC de 64 bits).
//
//   Saída esperada:
//   - pao
//   - leite
//   - cafe
//   - manteiga
//   5 blocos, 56 bytes
//
// Dicas:
// 1. O vetor de ponteiros é 1 bloco de 4 * 8 = 32 bytes; cada item é mais
//    1 bloco de strlen + 1.
// 2. Some os bytes dentro de criar_lista ou num laço à parte com sizeof e
//    strlen.
// 3. Resposta esperada: 5 blocos e 56 bytes (32 + 4 + 6 + 5 + 9).
//    liberar_lista faz 5 free: cada item e depois o vetor.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
