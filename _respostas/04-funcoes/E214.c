// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E214 · ★★☆

#include <stdio.h>

#define DOBRO(x) ((x) * 2)

int total = 0;

int proximo_id(void) {
    static int id = 10;
    id++;
    return id;
}

int soma_ate(int n) {
    total++;
    if (n == 0) {
        return 0;
    }
    return n + soma_ate(n - 1);
}

int altera(int total) { // esconde a global
    total = 99;
    return total;
}

int main(void) {
    printf("id: %d\n", proximo_id());
    int id1 = proximo_id();
    int id2 = proximo_id();
    printf("dois ids somados: %d\n", id1 + id2);
    printf("soma_ate(4) = %d\n", soma_ate(4));
    printf("chamadas: %d\n", total);
    altera(total);
    printf("depois de altera: %d\n", total);
    printf("DOBRO(total + 1) = %d\n", DOBRO(total + 1));
    return 0;
}
