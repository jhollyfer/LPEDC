// 0035 · Pré-processador: macros e #ifdef
// Exercício E210 · ★★★

#include <stdio.h>

int falhas = 0;

#define CONFERIR(cond)                                                \
    do {                                                              \
        if (cond) {                                                   \
            printf("ok: %s\n", #cond);                                \
        } else {                                                      \
            printf("FALHOU: %s (linha %d)\n", #cond, __LINE__);       \
            falhas++;                                                 \
        }                                                             \
    } while (0)

double com_desconto(double preco) {
    if (preco >= 100) {
        return preco - preco * 10 / 100;
    }
    return preco;
}

int main(void) {
    CONFERIR(com_desconto(50) == 50);
    CONFERIR(com_desconto(100) == 90);
    CONFERIR(com_desconto(200) == 180);
    CONFERIR(com_desconto(0) == 0);
    CONFERIR(com_desconto(150) == 150); // errado de propósito: o certo é 135
    printf("Falhas: %d\n", falhas);
    return 0;
}
