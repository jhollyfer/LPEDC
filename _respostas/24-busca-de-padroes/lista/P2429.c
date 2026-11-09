// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2429 · ★★★ · O verificador que fugiu da frase

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool palindromo(const char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        while (i < j && !isalpha((unsigned char)s[i])) i++; // o conserto: i < j nos dois laços
        while (i < j && !isalpha((unsigned char)s[j])) j--;
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
        i++;
        j--;
    }
    return true;
}

int main(void) {
    const char *frases[] = {"Ame o poema.", "Luz azul!", "A cara rajada da jararaca.", "?!", "Oi, tchau.", "..."};
    for (int k = 0; k < 6; k++) printf("[%s] %s\n", frases[k], palindromo(frases[k]) ? "sim" : "não");
    return 0;
}
