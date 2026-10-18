// 0164 · Listas autoajustáveis
// Exercício E984 · ★★★

#include <stdio.h>
#include <string.h>

#define ALFABETO "abcdefghijklmnopqrstuvwxyz"

// leva lista[i] para a posição 0; os anteriores andam uma casa
void frente(char lista[], int i) {
    char c = lista[i];
    for (int j = i; j > 0; j--) {
        lista[j] = lista[j - 1];
    }
    lista[0] = c;
}

// devolve quantos códigos escreveu (um por letra)
int codifica(const char *texto, int codigos[]) {
    char lista[27];
    strcpy(lista, ALFABETO);
    int n = 0;
    for (int k = 0; texto[k] != '\0'; k++) {
        int i = (int)(strchr(lista, texto[k]) - lista);
        codigos[n++] = i;
        frente(lista, i);
    }
    return n;
}

void decodifica(const int codigos[], int n, char saida[]) {
    char lista[27];
    strcpy(lista, ALFABETO);
    for (int k = 0; k < n; k++) {
        saida[k] = lista[codigos[k]];
        frente(lista, codigos[k]);
    }
    saida[n] = '\0';
}

int main(void) {
    const char *textos[] = {"banana", "aaabbbaaa"};
    for (int t = 0; t < 2; t++) {
        int codigos[32];
        char volta[33];
        int n = codifica(textos[t], codigos);
        printf("%s:", textos[t]);
        for (int k = 0; k < n; k++) {
            printf(" %d", codigos[k]);
        }
        decodifica(codigos, n, volta);
        printf(" -> %s\n", volta);
    }
    return 0;
}
