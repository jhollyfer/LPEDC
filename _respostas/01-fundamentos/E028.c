// 0005 · printf
// Exercício E028 · ★★☆
//
// Resposta: (1) "format '%f' expects argument of type 'double', but argument
// 2 has type 'int'": quantidade é int, use %d; (2) "format '%d' expects
// argument of type 'int', but argument 2 has type 'double'": preco é double,
// use %.2f; (3) "format '%f' expects a matching 'double' argument": faltou
// passar total. Sem conserto, o printf lê bytes que não são os seus e mostra
// lixo.

#include <stdio.h>

int main(void) {
    int quantidade = 3;
    double preco = 45.90;
    double total = 137.70;

    printf("Pizzas: %d\n", quantidade);
    printf("Preço: R$ %.2f\n", preco);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
