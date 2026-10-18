// 0042 · Lendo strings
// Exercício E250 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char senha[100];

    printf("Senha: ");
    if (fgets(senha, sizeof(senha), stdin) == NULL) {
        return 1;
    }
    senha[strcspn(senha, "\n")] = '\0';

    bool tem_maiuscula = false, tem_minuscula = false, tem_digito = false;
    for (int i = 0; senha[i] != '\0'; i++) {
        unsigned char c = (unsigned char) senha[i];
        if (isupper(c)) {
            tem_maiuscula = true;
        } else if (islower(c)) {
            tem_minuscula = true;
        } else if (isdigit(c)) {
            tem_digito = true;
        }
    }

    bool falhou = false;
    size_t tamanho = strlen(senha);
    if (tamanho < 8) {
        printf("Falta: 8 caracteres (tem %zu)\n", tamanho);
        falhou = true;
    }
    if (!tem_maiuscula) {
        printf("Falta: letra maiúscula\n");
        falhou = true;
    }
    if (!tem_minuscula) {
        printf("Falta: letra minúscula\n");
        falhou = true;
    }
    if (!tem_digito) {
        printf("Falta: dígito\n");
        falhou = true;
    }
    if (!falhou) {
        printf("Senha forte.\n");
    }
    return 0;
}
