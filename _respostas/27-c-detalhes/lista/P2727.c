// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2727 · ★★★ · O wc de bolso

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *f = fopen("p2727_texto.txt", "w");
    if (f == NULL) {
        printf("não consegui criar o arquivo\n");
        return 1;
    }
    fputs("Bom dia\nfeira no domingo\n\ncafe com pao\n", f);
    fclose(f);

    f = fopen("p2727_texto.txt", "r");
    if (f == NULL) {
        printf("não consegui abrir o arquivo\n");
        return 1;
    }
    int linhas = 0, palavras = 0, bytes = 0;
    int dentro = 0; // estou no meio de uma palavra?
    int c;
    while ((c = fgetc(f)) != EOF) {
        bytes++;
        if (c == '\n') {
            linhas++;
        }
        if (isspace(c)) {
            dentro = 0;
        } else if (!dentro) {
            dentro = 1;
            palavras++;
        }
    }
    fclose(f);
    remove("p2727_texto.txt");
    printf("linhas: %d\npalavras: %d\nbytes: %d\n", linhas, palavras, bytes);
    return 0;
}
