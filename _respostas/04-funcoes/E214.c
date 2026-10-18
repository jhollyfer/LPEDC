// 0036 · A pilha de chamadas
// Exercício E214 · ★★☆
//
// Resposta: "processa: n = 5, r = 11" e "main: n = 5, r = 16".
//
// | Quadro        | n            | r                    |
// | main          | 5            | 16 (no fim)          |
// | processa      | 5            | 11                   |
// | dobro_mais_um | 5, depois 11 | 10                   |
//
// dobro_mais_um muda o n do quadro dela; processa e main nem ficam sabendo.

#include <stdio.h>

int dobro_mais_um(int n) {
    int r = n * 2;
    n = r + 1;
    return n;
}

int processa(int n) {
    int r = dobro_mais_um(n);
    printf("processa: n = %d, r = %d\n", n, r);
    return r + n;
}

int main(void) {
    int n = 5;
    int r = processa(n);
    printf("main: n = %d, r = %d\n", n, r);
    return 0;
}
