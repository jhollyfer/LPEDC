// A111 · Uma troca para qualquer tipo

#include <stdio.h>

// void *: "endereço de qualquer coisa". Como a função não sabe o tipo,
// recebe o tamanho em bytes e troca byte a byte.
void troca_generica(void *a, void *b, size_t tam) {
    unsigned char *x = a; // void * vira outro ponteiro sem cast, em C
    unsigned char *y = b;
    for (size_t i = 0; i < tam; i++) {
        unsigned char tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}

int main(void) {
    int senha_a = 17, senha_b = 42;               // senhas do atendimento
    double preco_a = 12.90, preco_b = 8.50;       // preços na etiqueta

    troca_generica(&senha_a, &senha_b, sizeof senha_a);   // troca 4 bytes
    troca_generica(&preco_a, &preco_b, sizeof preco_a);   // troca 8 bytes

    printf("senhas: %d e %d\n", senha_a, senha_b);
    printf("preços: %.2f e %.2f\n", preco_a, preco_b);
    return 0;
}
// Saída:
// senhas: 42 e 17
// preços: 8.50 e 12.90
