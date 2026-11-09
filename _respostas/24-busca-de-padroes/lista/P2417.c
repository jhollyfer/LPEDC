// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2417 · ★★☆ · Várias palavras numa passada

#include <stdio.h>
#include <string.h>

#define B 256
#define Q 1000003
#define P 4

int main(void) {
    const char *texto = "a feira tem caju, jambu, cupuacu e acai; o caju e o jambu acabaram cedo";
    // o Rabin-Karp de vários padrões pede padrões do MESMO tamanho m
    const char *lista[P] = {"caju", "acai", "cedo", "doce"};
    int m = 4, n = (int)strlen(texto);

    long long pot = 1;
    for (int k = 1; k < m; k++) pot = pot * B % Q;
    long long hp[P];
    for (int p = 0; p < P; p++) {
        hp[p] = 0;
        for (int k = 0; k < m; k++) hp[p] = (hp[p] * B + (unsigned char)lista[p][k]) % Q;
    }
    long long ht = 0;
    for (int k = 0; k < m; k++) ht = (ht * B + (unsigned char)texto[k]) % Q;

    int vezes[P] = {0}, conferencias = 0;
    for (int i = 0; i + m <= n; i++) {
        for (int p = 0; p < P; p++)
            if (ht == hp[p]) {
                conferencias++;
                if (strncmp(texto + i, lista[p], m) == 0) {
                    vezes[p]++;
                    printf("%s em %d\n", lista[p], i);
                }
            }
        if (i + m < n) {
            ht = (ht - (unsigned char)texto[i] * pot % Q + Q) % Q;
            ht = (ht * B + (unsigned char)texto[i + m]) % Q;
        }
    }
    for (int p = 0; p < P; p++) printf("%s: %d\n", lista[p], vezes[p]);
    printf("Janelas: %d; conferências letra a letra: %d\n", n - m + 1, conferencias);
    return 0;
}
