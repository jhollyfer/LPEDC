// A343 · O sizeof que é calculado na hora

#include <stdio.h>

// uma barra do gráfico de vendas: o tamanho do vetor muda a cada chamada
void barra(const char *dia, int vendas) {
    char linha[vendas + 1]; // as estrelas + o '\0'
    for (int i = 0; i < vendas; i++) {
        linha[i] = '#';
    }
    linha[vendas] = '\0';
    printf("%s %-9s (sizeof linha = %zu)\n", dia, linha, sizeof linha);
}

int main(void) {
#ifdef __STDC_NO_VLA__
    printf("este compilador não tem VLA\n");
    return 1;
#else
    printf("este compilador tem VLA\n");
#endif

    const char *dias[] = {"seg", "ter", "qua", "qui"};
    int vendas[] = {3, 7, 5, 8};
    for (int i = 0; i < 4; i++) {
        barra(dias[i], vendas[i]); // cada chamada cria e destrói o seu VLA
    }

    // sizeof de um tipo VLA também é uma conta em tempo de execução
    int n = 6;
    printf("sizeof(int[n]) com n = %d: %zu\n", n, sizeof(int[n]));
    printf("sizeof(double[n][2]):      %zu\n", sizeof(double[n][2]));
    return 0;
}
// Saída:
// este compilador tem VLA
// seg ###       (sizeof linha = 4)
// ter #######   (sizeof linha = 8)
// qua #####     (sizeof linha = 6)
// qui ########  (sizeof linha = 9)
// sizeof(int[n]) com n = 6: 24
// sizeof(double[n][2]):      96
