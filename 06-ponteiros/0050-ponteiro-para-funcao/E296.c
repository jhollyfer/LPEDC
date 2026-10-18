// 0050 · Ponteiro para função
// Exercício E296 · ★☆☆
//
// Escreva o "forEach" do C:
//
//   void para_cada(int *v, int n, void (*acao)(int *))
//
// que chama acao para o endereço de cada elemento. Escreva também duas
// ações: void dobra(int *x) e void mostra(int *x) (mostra imprime o valor e
// um espaço). No main, com int brindes[4] = {1, 2, 3, 4};, mostre, dobre e
// mostre de novo, sempre via para_cada.
//
//   Saída esperada:
//   1 2 3 4
//   2 4 6 8
//
// Dicas:
// 1. Dentro de para_cada: for (...) acao(&v[i]); (ou acao(v + i)).
// 2. A ação recebe int * porque dobra precisa mudar o elemento.
// 3. Resposta esperada: "1 2 3 4" e "2 4 6 8".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
