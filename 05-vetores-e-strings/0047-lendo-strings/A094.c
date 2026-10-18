// A094 · Número, depois texto, e a linha que não coube

#include <stdio.h>
#include <string.h>

// joga fora o que sobrou na linha, até o '\n' (ou o fim da entrada)
void descartar_linha(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {
    int idade;
    char cidade[12]; // cabem 10 letras + '\n' + '\0'

    printf("Idade: ");
    if (scanf("%d", &idade) != 1) {
        printf("Idade inválida.\n");
        return 1;
    }
    descartar_linha(); // sem isto, o fgets leria o '\n' que o scanf deixou

    printf("Cidade: ");
    if (fgets(cidade, sizeof(cidade), stdin) == NULL) {
        return 1;
    }

    size_t pos = strcspn(cidade, "\n");
    if (cidade[pos] == '\n') {
        cidade[pos] = '\0';  // coube: só tira o '\n'
    } else {
        descartar_linha();   // não coube: o resto ainda está na entrada
        printf("(nome longo demais, cortado)\n");
    }

    printf("%d anos, de %s\n", idade, cidade);
    return 0;
}
// Idade: 34
// Cidade: Campina Grande
// (nome longo demais, cortado)
// 34 anos, de Campina Gra
