// 0042 · Lendo strings
// Exercício E252 · ★★★

#include <stdio.h>
#include <string.h>

int main(void) {
    char s[6];
    int leituras = 0;
    int linhas = 0;
    int letras_da_linha = 0;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        leituras++;
        int n = (int) strcspn(s, "\n"); // letras antes do '\n' (ou todas)
        letras_da_linha += n;

        printf("pedaço %d: [%.*s", leituras, n, s);
        if (s[n] == '\n') { // este pedaço fecha a linha
            linhas++;
            printf("\\n] fim da linha %d (%d letras)\n", linhas, letras_da_linha);
            letras_da_linha = 0;
        } else {
            printf("]\n");
        }
    }
    printf("%d leituras, %d linhas\n", leituras, linhas);
    return 0;
}
