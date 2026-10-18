// 0055 · calloc e realloc
// Exercício E327 · ★★☆
//
// Leia números inteiros do teclado até aparecer 0 (o 0 não entra). Guarde
// num vetor que começa com capacidade 2 e dobra quando enche. No fim,
// mostre os números na ordem contrária e a capacidade final.
//
//   Exemplo de uso:
//   Números (0 para parar): 5 8 2 9 4 0
//   Ao contrário: 4 9 2 8 5
//   Capacidade final: 8
//
// Para testar: printf '5 8 2 9 4 0\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. Duas variáveis de controle: quantidade e capacidade. Encheu quando
//    quantidade == capacidade.
// 2. Use o realloc com ponteiro temporário, como no A109.
// 3. Resposta esperada: "Ao contrário: 4 9 2 8 5" e "Capacidade final: 8"
//    (a capacidade foi 2, 4 e 8). Também trate o fim da entrada: se o scanf
//    não devolver 1, pare como se fosse o 0.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
