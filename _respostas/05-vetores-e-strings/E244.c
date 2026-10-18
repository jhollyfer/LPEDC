// 0041 · Strings
// Exercício E244 · ★★☆

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool eh_palindromo(const char s[]) {
    int i = 0;
    int j = (int) strlen(s) - 1;
    while (i < j) {
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(void) {
    char palavras[5][12] = {"arara", "Reviver", "carro", "Osso", "A"};

    for (int k = 0; k < 5; k++) {
        printf("%s: %s\n", palavras[k], eh_palindromo(palavras[k]) ? "sim" : "não");
    }
    return 0;
}
