// A127 · A balança da feira

#include <stdio.h>

// um produto da feira é vendido por unidade OU por quilo, nunca pelos dois
typedef union {
    int unidades;
    double quilos;
} Quantidade;

// a mesma informação numa struct: os dois campos ocupam espaço sempre
typedef struct {
    int unidades;
    double quilos;
} QuantidadeStruct;

int main(void) {
    Quantidade q;

    q.unidades = 12; // uma dúzia de ovos
    printf("unidades: %d\n", q.unidades);

    q.quilos = 2.5;  // agora 2,5 kg de tomate: os mesmos bytes, reescritos
    printf("quilos: %.1f\n", q.quilos);
    // 2.5 em double é 0x4004000000000000; num PC little-endian, os 4 bytes
    // que o int lê são os de baixo, todos zero
    printf("unidades agora: %d (lixo: a dúzia sumiu)\n", q.unidades);

    printf("union: %zu bytes, struct: %zu bytes\n", sizeof(Quantidade),
           sizeof(QuantidadeStruct));
    printf("1000 produtos: %zu contra %zu bytes\n", 1000 * sizeof(Quantidade),
           1000 * sizeof(QuantidadeStruct));
    printf("mesmo endereço? %s\n", (void *)&q.unidades == (void *)&q.quilos ? "sim" : "não");
    return 0;
}
// Saída (num PC Intel/AMD ou ARM):
// unidades: 12
// quilos: 2.5
// unidades agora: 0 (lixo: a dúzia sumiu)
// union: 8 bytes, struct: 16 bytes
// 1000 produtos: 8000 contra 16000 bytes
// mesmo endereço? sim
