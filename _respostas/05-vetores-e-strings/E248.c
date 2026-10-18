// 0042 · Lendo strings
// Exercício E248 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    char a[20], b[20], resto[20];

    if (scanf("%19s", a) != 1) {
        return 1;
    }
    printf("1ª leitura: [%s] (%zu)\n", a, strlen(a));

    if (scanf("%4s", b) != 1) { // pula o espaço e para depois de 4 letras
        return 1;
    }
    printf("2ª leitura: [%s] (%zu)\n", b, strlen(b));

    if (fgets(resto, sizeof(resto), stdin) == NULL) { // pega o resto da linha
        return 1;
    }
    size_t com_enter = strlen(resto);
    resto[strcspn(resto, "\n")] = '\0';
    printf("fgets: %zu com o '\\n', limpo: [%s] (%zu)\n", com_enter, resto, strlen(resto));
    return 0;
}
