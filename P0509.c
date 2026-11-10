// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0509 · ★☆☆ · Conserte o contador de letras
//
// A função conta abaixo deveria dizer quantas vezes uma letra aparece no nome
// do rio. Ela tem DOIS erros de propósito, e o gcc avisa dos dois: rode, leia
// os avisos (warning) e conserte. Depois de consertado, o programa mostra:
//
//   Saída esperada:
//   Letra o: 3
//   Letra a: 2
//   Letra z: 1
//
// Dicas:
// 1. Um vetor que chega como parâmetro vira só um endereço: sizeof s dá o
//    tamanho de um endereço (8), não o da string. Use o '\0' para parar.
// 2. Dentro do if, = é atribuição; para comparar, use ==.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int conta(char s[], char letra) {
    int total = 0;
    for (size_t i = 0; i < sizeof s; i++) {
        if (s[i] = letra) {
            total++;
        }
    }
    return total;
}

int main(void) {
    char rio[] = "Solimoes e Amazonas";

    printf("Letra o: %d\n", conta(rio, 'o'));
    printf("Letra a: %d\n", conta(rio, 'a'));
    printf("Letra z: %d\n", conta(rio, 'z'));
    return 0;
}
