// 0159 · Horspool
// Exercício E952 · ★★☆
//
// O Horspool também tem pior caso. O programa abaixo conta as comparações da
// força bruta num texto de trinta 'a'. Estenda: escreva
// long horspool(const char *t, const char *p, int *alinhamentos), que conta
// as comparações de letra e os alinhamentos, e mostre tudo no main:
//
//   Saída esperada:
//   baaa: força bruta  27, Horspool 108 (27 alinhamentos)
//   aaab: força bruta 108, Horspool  27 (27 alinhamentos)
//   abbb: força bruta  54, Horspool   9 (9 alinhamentos)
//
// Dicas:
// 1. Conte uma comparação a cada t[i + j] comparado com p[j], inclusive a que
//    falha.
// 2. Em "baaa", o Horspool compara da direita: casa três 'a' e só falha no
//    'b'. E como a letra sob a última casa é 'a', que aparece no fim do
//    padrão, o salto é 1. É o pior caso dele: m comparações e salto 1.
// 3. Em "abbb", o 'a' do texto só aparece no começo do padrão: salto 3.
// 4. Resposta esperada: a saída acima. Cada algoritmo tem o seu pior caso.
//
// Escreva sua resposta abaixo (acrescente a horspool e mude o main):

#include <stdio.h>
#include <string.h>

#define ALFABETO 256

long forca_bruta(const char *t, const char *p) {
    int n = (int) strlen(t);
    int m = (int) strlen(p);
    long comp = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comp++;
            if (t[i + j] != p[j]) {
                break;
            }
            j++;
        }
    }
    return comp;
}

int main(void) {
    char texto[31];
    for (int i = 0; i < 30; i++) {
        texto[i] = 'a';              // trinta 'a'
    }
    texto[30] = '\0';
    const char *padroes[] = {"baaa", "aaab", "abbb"};

    for (int k = 0; k < 3; k++) {
        printf("%s: força bruta %3ld\n", padroes[k], forca_bruta(texto, padroes[k]));
    }
    return 0;
}
