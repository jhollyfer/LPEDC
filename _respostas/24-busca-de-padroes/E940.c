// 0157 · Força bruta
// Exercício E940 · ★★☆

#include <stdio.h>
#include <string.h>

// as m letras de padrao aparecem em texto a partir da posição i?
int casa_em(const char *texto, int i, const char *padrao, int m) {
    int j = 0;
    while (j < m && texto[i + j] == padrao[j]) {
        j++;
    }
    return j == m;
}

// copia texto para saida trocando cada velho por novo; devolve quantas trocas
int substitui(const char *texto, const char *velho, const char *novo,
              char saida[], int cap) {
    int n = (int) strlen(texto);
    int m = (int) strlen(velho);
    int tam_novo = (int) strlen(novo);
    int trocas = 0;
    int k = 0;                          // próxima posição livre em saida
    int i = 0;
    while (i < n) {
        if (i <= n - m && casa_em(texto, i, velho, m)) {
            if (k + tam_novo >= cap) {
                break;                  // não cabe: para antes de estourar
            }
            for (int c = 0; c < tam_novo; c++) {
                saida[k++] = novo[c];
            }
            i += m;                     // pula o pedaço trocado
            trocas++;
        } else {
            if (k + 1 >= cap) {
                break;
            }
            saida[k++] = texto[i++];
        }
    }
    saida[k] = '\0';
    return trocas;
}

int main(void) {
    const char *msg = "vc vem? se vc não vier, vc avisa";
    char saida[100];

    int t = substitui(msg, "vc", "você", saida, sizeof saida);
    printf("%s\n", saida);
    printf("%d trocas\n", t);
    return 0;
}
