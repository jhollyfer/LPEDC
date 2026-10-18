// 0137 · Juntando tudo
// Exercício E818 · ★☆☆

#include <stdio.h>

int main(void) {
    FILE *f = fopen("poema.txt", "w");
    if (f == NULL) {
        return 1;
    }
    fputs("Minha terra tem palmeiras,\n"
          "Onde canta o Sabiá;\n"
          "As aves, que aqui gorjeiam,\n"
          "Não gorjeiam como lá.\n", f);
    fclose(f);

    long freq[256] = {0};
    f = fopen("poema.txt", "rb");
    if (f == NULL) {
        return 1;
    }
    int c;
    long total = 0;
    while ((c = fgetc(f)) != EOF) {
        freq[c]++;
        total++;
    }
    fclose(f);
    remove("poema.txt");

    printf("%ld bytes. Os 5 mais frequentes:\n", total);
    for (int k = 0; k < 5; k++) {
        int maior = 0;
        for (int i = 1; i < 256; i++) {
            if (freq[i] > freq[maior]) {
                maior = i;      // empate: fica o de menor código
            }
        }
        if (maior == '\n') {
            printf("  '\\n' %ld\n", freq[maior]);
        } else {
            printf("  '%c' %ld\n", maior, freq[maior]);
        }
        freq[maior] = -1;       // tira da disputa
    }
    return 0;
}
