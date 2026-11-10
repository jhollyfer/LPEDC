// A113 · Todo caminho de saída libera

#include <stdio.h>
#include <stdlib.h>

// Copia as notas de um aluno e calcula a média. Uma nota fora de 0 a 10
// cancela tudo, e a função sai mais cedo: esse return também precisa do free.
// Devolve -1 se a lista for inválida ou faltar memória.
double media_valida(const double *notas, int n) {
    double *copia = malloc(n * sizeof *copia);
    if (copia == NULL) {
        return -1; // nada foi alocado: nada a liberar
    }
    double soma = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] < 0 || notas[i] > 10) {
            printf("  nota %d inválida: %.1f\n", i + 1, notas[i]);
            free(copia); // a saída de erro é a que mais esquece
            return -1;
        }
        copia[i] = notas[i];
        soma += copia[i];
    }
    free(copia); // a saída normal
    return soma / n;
}

int main(void) {
    double ana[] = {7.5, 8.0, 9.0};
    double beto[] = {6.0, 11.0, 7.0}; // alguém digitou 11
    double caio[] = {5.0, 7.0, 6.0};

    const double *turma[] = {ana, beto, caio};
    const char *nomes[] = {"Ana", "Beto", "Caio"};
    for (int a = 0; a < 3; a++) {
        printf("%s:\n", nomes[a]);
        double m = media_valida(turma[a], 3);
        if (m < 0) {
            printf("  sem média\n");
        } else {
            printf("  média %.1f\n", m);
        }
    }
    return 0;
}
// Saída:
// Ana:
//   média 8.2
// Beto:
//   nota 2 inválida: 11.0
//   sem média
// Caio:
//   média 6.0
//
// Apague o free(copia) de dentro do if e rode de novo: Ana e Caio continuam
// certos, mas no fim o LeakSanitizer acusa 24 bytes em 1 bloco, o do Beto.
// Vazamento em caminho de erro é traiçoeiro: só aparece quando o erro
// acontece. Antes de cada return, pergunte: o que já foi alocado aqui?
