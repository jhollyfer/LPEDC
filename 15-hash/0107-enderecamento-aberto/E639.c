// 0107 · Endereçamento aberto
// Exercício E639 · ★★☆
//
// Os armários da escola usam endereçamento aberto com 7 posições e marca de
// removido. Guardaram 14, 21 e 28 (todos com hash 0: vão para 0, 1 e 2), e
// depois o 21 foi retirado, deixando a posição 1 como REMOVIDA. Complete a
// função busca: ela conta as sondagens, para ao achar a chave (true) ou uma
// posição LIVRE (false), passa reto pelas REMOVIDAS e nunca dá mais de M
// passos.
//
//   Saída esperada:
//   28: achou, sondagens: 3
//   35: não está, sondagens: 4
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdbool.h>

#define M 7

typedef enum { LIVRE, OCUPADA, REMOVIDA } Estado;

typedef struct {
    int chave;
    Estado estado;
} Armario;

void guarda(Armario t[], int chave) {
    int i = chave % M;
    while (t[i].estado == OCUPADA) {
        i = (i + 1) % M;
    }
    t[i].chave = chave;
    t[i].estado = OCUPADA;
}

bool busca(const Armario t[], int chave, int *sondagens) {
    *sondagens = 0;
    (void)t;     // apague estas duas linhas
    (void)chave; // quando usar os parâmetros

    // complete aqui

    return false;
}

int main(void) {
    Armario t[M] = {{0, LIVRE}};
    guarda(t, 14);
    guarda(t, 21);
    guarda(t, 28);
    t[1].estado = REMOVIDA; // o 21 foi retirado

    int procurar[] = {28, 35};
    for (int k = 0; k < 2; k++) {
        int s;
        bool achou = busca(t, procurar[k], &s);
        printf("%d: %s, sondagens: %d\n", procurar[k], achou ? "achou" : "não está", s);
    }
    return 0;
}
