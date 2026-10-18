// A072 · Testando as peças do caixa

#include <stdio.h>

#include "cardapio.h"

int falhas = 0;

#define CONFERIR(cond)                                          \
    do {                                                        \
        if (cond) {                                             \
            printf("ok: %s\n", #cond);                          \
        } else {                                                \
            printf("FALHOU: %s (linha %d)\n", #cond, __LINE__); \
            falhas++;                                           \
        }                                                       \
    } while (0)

int proxima_nota(int nota) {
    switch (nota) {
    case 10000: return 5000;
    case 5000: return 2000;
    case 2000: return 1000;
    case 1000: return 500;
    case 500: return 200;
    case 200: return 100;
    case 100: return 50;
    case 50: return 25;
    case 25: return 10;
    case 10: return 5;
    default: return 1;
    }
}

// quantas notas e moedas o troco usa (recursiva, igual a dar_troco)
int contar_notas(int centavos, int nota) {
    if (centavos == 0) {
        return 0;
    }
    if (centavos >= nota) {
        return 1 + contar_notas(centavos - nota, nota);
    }
    return contar_notas(centavos, proxima_nota(nota));
}

int main(void) {
    CONFERIR(preco_centavos(1) == 1850);
    CONFERIR(preco_centavos(9) == 0);
    CONFERIR(itens_vendidos() == 1); // o código 9 não conta
    CONFERIR(proxima_nota(10000) == 5000);
    CONFERIR(contar_notas(776, 10000) == 5);  // 5 + 2 + 0.50 + 0.25 + 0.01
    CONFERIR(contar_notas(18600, 10000) == 6); // 100 + 50 + 20 + 10 + 5 + 1
    printf("Falhas: %d\n", falhas);
    return 0;
}
// Saída:
// ok: preco_centavos(1) == 1850
// ok: preco_centavos(9) == 0
// ok: itens_vendidos() == 1
// ok: proxima_nota(10000) == 5000
// ok: contar_notas(776, 10000) == 5
// ok: contar_notas(18600, 10000) == 6
// Falhas: 0
