// 0043 · Juntando tudo
// Exercício E257 · ★★★
//
// Resposta: invertido[9] não tem lugar para os 9 caracteres e o '\0' (o laço
// escrevia em invertido[9], fora do vetor); e o laço copiava nome[n], que é o
// '\0', para invertido[0], deixando a string vazia. Conserto abaixo.

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[] = "Ana Paula";
    char invertido[10];
    int n = (int) strlen(nome);

    for (int i = 0; i < n; i++) {
        invertido[i] = nome[n - 1 - i];
    }
    invertido[n] = '\0';
    printf("%s\n", invertido);
    return 0;
}
