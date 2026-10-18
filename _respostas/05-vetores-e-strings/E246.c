// 0041 · Strings
// Exercício E246 · ★★★

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int capitalizar(char s[]) {
    bool anterior_espaco = true;
    int palavras = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            anterior_espaco = true;
        } else {
            if (anterior_espaco) {
                s[i] = (char) toupper(s[i]);
                palavras++;
            } else {
                s[i] = (char) tolower(s[i]);
            }
            anterior_espaco = false;
        }
    }
    return palavras;
}

int main(void) {
    char titulo[] = "  o SENHOR   dos aneis ";

    int n = capitalizar(titulo);
    printf("[%s]\n", titulo);
    printf("%d palavras\n", n);
    return 0;
}
