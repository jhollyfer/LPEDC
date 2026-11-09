// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2721 · ★★★ · Calculadora de notação polonesa reversa

#include <stdio.h>

int avaliar(const char *expr, int *resultado) {
    int pilha[32];
    int topo = 0;
    for (const char *p = expr; *p != '\0'; p++) {
        if (*p == ' ') {
            continue;
        }
        if (*p >= '0' && *p <= '9') {
            if (topo == 32) {
                return 0;
            }
            pilha[topo++] = *p - '0';
            continue;
        }
        if (topo < 2) {
            return 0; // operador sem dois operandos
        }
        int dir = pilha[--topo]; // o de cima é o da direita
        int esq = pilha[--topo];
        int r;
        switch (*p) {
        case '+':
            r = esq + dir;
            break;
        case '-':
            r = esq - dir;
            break;
        case '*':
            r = esq * dir;
            break;
        case '/':
            if (dir == 0) {
                return 0;
            }
            r = esq / dir;
            break;
        default:
            return 0;
        }
        pilha[topo++] = r;
    }
    if (topo != 1) {
        return 0;
    }
    *resultado = pilha[0];
    return 1;
}

int main(void) {
    const char *testes[] = {"3 4 + 2 *", "5 1 2 + 4 * + 3 -", "9 2 3 * -", "4 +", "8 0 /"};
    for (int i = 0; i < 5; i++) {
        int r;
        if (avaliar(testes[i], &r)) {
            printf("%s = %d\n", testes[i], r);
        } else {
            printf("%s = expressão inválida\n", testes[i]);
        }
    }
    return 0;
}
