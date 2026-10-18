// 0046 · Strings
// Exercício E273 · ★★☆

#include <stdio.h>

int meu_strlen(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void meu_strcat(char dest[], const char orig[]) {
    int fim = meu_strlen(dest);
    int i;
    for (i = 0; orig[i] != '\0'; i++) {
        dest[fim + i] = orig[i];
    }
    dest[fim + i] = '\0';
}

int meu_strcmp(const char a[], const char b[]) {
    int i = 0;
    while (a[i] == b[i] && a[i] != '\0') {
        i++;
    }
    return a[i] - b[i];
}

int main(void) {
    char usuario[30] = "joao";

    meu_strcat(usuario, ".silva");
    printf("%s (%d)\n", usuario, meu_strlen(usuario));
    printf("igual a \"joao.silva\"? %s\n", meu_strcmp(usuario, "joao.silva") == 0 ? "sim" : "não");
    printf("\"ana\" antes de \"bia\"? %s\n", meu_strcmp("ana", "bia") < 0 ? "sim" : "não");
    printf("\"bia\" antes de \"bianca\"? %s\n", meu_strcmp("bia", "bianca") < 0 ? "sim" : "não");
    return 0;
}
