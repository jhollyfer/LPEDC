// 0005 · printf
// Exercício E030 · ★★★

#include <stdio.h>

int main(void) {
    printf("[%5.1f]\n", 3456.78);                   // a largura 5 não corta
    printf("[%.3s]\n", "Brasília");                 // a precisão corta o texto
    printf("[%.2f] [%.20f]\n", 2.675, 2.675);       // 2.67499999... guardado
    printf("[%e]\n", 123456.0);
    printf("[%g] [%g]\n", 0.0001, 0.00001);         // o %g vira científico
    int n = printf("Pão\n");                        // devolve os bytes escritos
    printf("[%d]\n", n);
    return 0;
}
