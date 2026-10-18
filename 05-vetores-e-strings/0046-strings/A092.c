// A092 · Percorrendo até o '\0'

#include <stdio.h>

// conta os caracteres sem strlen: anda até achar o '\0'
int tamanho(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// copia caractere por caractere e fecha com o '\0'
void copiar(char destino[], const char origem[]) {
    int i;
    for (i = 0; origem[i] != '\0'; i++) {
        destino[i] = origem[i];
    }
    destino[i] = '\0'; // sem esta linha, destino não termina
}

int main(void) {
    char cidade[] = "Belém";
    char copia[20];

    copiar(copia, cidade);
    copia[0] = 'X'; // a cópia é outro vetor

    printf("%s tem %d bytes antes do '\\0'\n", cidade, tamanho(cidade));
    printf("cópia alterada: %s\n", copia);

    cidade[3] = '\0'; // corta a string no meio
    printf("cortada: %s (%d)\n", cidade, tamanho(cidade));
    return 0;
}
// Saída:
// Belém tem 6 bytes antes do '\0'
// cópia alterada: Xelém
// cortada: Bel (3)
