// 0036 · Juntando tudo: o caixa da lanchonete
// Exercício E214 · ★★☆
//
// Resposta: 11, 25, 10, 5, 12.
// proximo_id: id é static, 11; depois 12 + 13 = 25 (a ordem das duas chamadas
// não importa para a soma). soma_ate(4) = 4 + 3 + 2 + 1 + 0 = 10, com 5
// chamadas, e cada uma soma 1 na global total: 5. Em altera, o parâmetro total
// esconde a global e o 99 vai para a cópia. DOBRO(total + 1) = ((5 + 1) * 2).

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

int altera(int total) {
    total = 99;
    return total;
}

int main(void) {
    printf("%d\n", proximo_id());
    printf("%d\n", proximo_id() + proximo_id());
    printf("%d\n", soma_ate(4));
    printf("%d\n", total);
    altera(total);
    printf("%d\n", DOBRO(total + 1));
    return 0;
}
