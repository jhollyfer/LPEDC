// 0120 · Counting sort
// Exercício E720 · ★★★

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e a rainha ficou brava";
    int freq[26] = {0};
    int n = (int) strlen(frase);

    // 1) frequência de cada letra
    for (int i = 0; i < n; i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            freq[frase[i] - 'a']++;
        }
    }
    int maior = 0;
    for (int l = 0; l < 26; l++) {
        if (freq[l] > maior) {
            maior = freq[l];
        }
    }

    // 2) counting sort das 26 letras com chave = maior - freq (decrescente);
    //    as letras entram em ordem alfabética e o sort é estável, então os
    //    empates saem em ordem alfabética
    int c[64] = {0};                  // maior <= 57, o tamanho da frase
    for (int l = 0; l < 26; l++) {
        c[maior - freq[l]]++;
    }
    for (int x = 1; x <= maior; x++) {
        c[x] += c[x - 1];
    }
    int ranking[26];
    for (int l = 25; l >= 0; l--) {
        int x = maior - freq[l];
        c[x]--;
        ranking[c[x]] = l;
    }

    for (int i = 0; i < 26 && freq[ranking[i]] > 0; i++) {
        printf("%c:%d%s", 'a' + ranking[i], freq[ranking[i]],
               i + 1 < 26 && freq[ranking[i + 1]] > 0 ? " " : "\n");
    }
    return 0;
}
