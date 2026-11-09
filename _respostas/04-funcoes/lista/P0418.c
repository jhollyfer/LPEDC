// Lista · Módulo 04 · Funções e modularização
// Exercício P0418 · ★★☆ · O imposto de cada estado

#include <stdio.h>

#define ESTADO 1 // 1 = Amazonas, 2 = São Paulo, outro = demais

#if ESTADO == 1
#define ICMS 0.20
#define NOME_ESTADO "Amazonas"
#elif ESTADO == 2
#define ICMS 0.18
#define NOME_ESTADO "São Paulo"
#else
#define ICMS 0.17
#define NOME_ESTADO "outro estado"
#endif

#define MOSTRAR(expr) printf("%s = %.2f\n", #expr, (expr))

int main(void) {
    double preco = 100.00;

    printf("Estado: %s\n", NOME_ESTADO);
    MOSTRAR(preco * (1 + ICMS));
    MOSTRAR(preco * ICMS);
    return 0;
}
