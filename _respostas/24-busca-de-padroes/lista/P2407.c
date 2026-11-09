// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2407 · ★☆☆ · A frase que lê dos dois lados

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool palindromo(const char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[j] == ' ') {
            j--;
            continue;
        }
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
        i++;
        j--;
    }
    return true;
}

int main(void) {
    const char *frases[] = {"Socorram me subi no onibus em Marrocos", "A base do teto desaba",
                            "Roma me tem amor", "Bom dia Manaus", "ovo"};
    for (int k = 0; k < 5; k++) printf("%-40s %s\n", frases[k], palindromo(frases[k]) ? "sim" : "não");
    return 0;
}
