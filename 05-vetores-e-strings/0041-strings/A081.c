// A081 · A etiqueta que não pode estourar

#include <stdio.h>
#include <string.h>

#define TAM 20 // a etiqueta impressa tem 19 caracteres + o '\0'

int main(void) {
    char etiqueta[TAM] = "SP"; // as outras 18 posições viram '\0'
    char partes[3][12] = {"/Campinas", "/Centro", "/Bloco B"};

    for (int i = 0; i < 3; i++) {
        // antes do strcat, a conta: o que tem + o que vem + 1 do '\0'
        size_t precisa = strlen(etiqueta) + strlen(partes[i]) + 1;
        if (precisa <= sizeof(etiqueta)) {
            strcat(etiqueta, partes[i]);
            printf("+ %-9s -> %s\n", partes[i], etiqueta);
        } else {
            printf("%s não cabe: precisaria de %zu bytes\n", partes[i], precisa);
        }
    }

    // strcmp compara códigos: maiúscula e minúscula são diferentes
    if (strcmp(etiqueta, "SP/Campinas/Centro") == 0) {
        printf("Igual a \"SP/Campinas/Centro\"\n");
    }
    if (strcmp(etiqueta, "sp/campinas/centro") != 0) {
        printf("Diferente de \"sp/campinas/centro\": 'S' é 83, 's' é 115\n");
    }
    return 0;
}
// Saída:
// + /Campinas -> SP/Campinas
// + /Centro   -> SP/Campinas/Centro
// /Bloco B não cabe: precisaria de 27 bytes
// Igual a "SP/Campinas/Centro"
// Diferente de "sp/campinas/centro": 'S' é 83, 's' é 115
