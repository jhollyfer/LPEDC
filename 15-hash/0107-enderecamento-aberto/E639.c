// 0107 · Endereçamento aberto
// Exercício E639 · ★★☆
//
// Os armários da escola usam endereçamento aberto com 7 posições (h = k % 7,
// sondagem linear) e o enum Estado { LIVRE, OCUPADA, REMOVIDA }. Escreva
// "guarda" e "bool busca(const Armario t[], int chave, int *sondagens)", que
// conta as sondagens, para ao achar a chave (true) ou uma posição LIVRE
// (false), passa reto pelas REMOVIDAS e nunca dá mais de 7 passos. Guarde 14,
// 21 e 28 (vão para 0, 1 e 2), marque a posição do 21 como REMOVIDA e busque
// 28 e 35.
//
//   Saída esperada:
//   28: achou, sondagens: 3
//   35: não está, sondagens: 4
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

#define M 7

typedef enum { LIVRE, OCUPADA, REMOVIDA } Estado;

typedef struct {
    int chave;
    Estado estado;
} Armario;

int main(void) {

    return 0;
}
