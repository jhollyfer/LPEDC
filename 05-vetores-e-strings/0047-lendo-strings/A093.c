// A093 · O nome completo no cadastro

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[40];

    printf("Nome completo: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) { // NULL: a entrada acabou
        printf("Nada foi digitado.\n");
        return 1;
    }
    printf("Lido: [%s]", nome);                     // o '\n' veio junto

    nome[strcspn(nome, "\n")] = '\0';               // troca o '\n' pelo fim
    printf("Limpo: [%s]\n", nome);

    printf("Olá, %s! Seu nome tem %zu caracteres.\n", nome, strlen(nome));
    return 0;
}
// Nome completo: Maria Clara
// Lido: [Maria Clara
// ]Limpo: [Maria Clara]
// Olá, Maria Clara! Seu nome tem 11 caracteres.
