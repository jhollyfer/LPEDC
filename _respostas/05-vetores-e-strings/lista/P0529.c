// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0529 · ★★★ · Conserte o gerador de etiquetas

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[] = "Benedita Farias";
    char cidade[] = "Boa Vista";
    char uf[] = "RR";
    char tipo[] = "expresso";
    char etiqueta[48]; // 37 caracteres + '\0' cabem com folga

    strcpy(etiqueta, "PARA: ");
    strcat(etiqueta, nome);
    strcat(etiqueta, " - ");
    strcat(etiqueta, cidade); // era strcpy: apagava o começo
    strcat(etiqueta, "/");
    strcat(etiqueta, uf);

    printf("%s\n", etiqueta);
    printf("Tamanho: %zu\n", strlen(etiqueta));
    if (strcmp(tipo, "expresso") == 0) { // == comparava endereços
        printf("Envio expresso: entrega em 2 dias\n");
    } else {
        printf("Envio comum: entrega em 7 dias\n");
    }
    return 0;
}
