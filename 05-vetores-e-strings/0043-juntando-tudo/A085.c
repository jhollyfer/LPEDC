// A085 · Os logins da empresa nova

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define TAM_LOGIN 16
#define TAM_LINHA 60

// iniciais dos nomes do meio + o último nome, tudo em minúsculas:
// "Ana Paula Souza" vira "apsouza"
void gerar_login(const char nome[], char login[]) {
    int n = (int) strlen(nome);
    int ultimo = 0; // onde começa a última palavra
    for (int i = 0; i < n; i++) {
        if (nome[i] == ' ') {
            ultimo = i + 1;
        }
    }

    int j = 0;
    for (int i = 0; i < n && j < TAM_LOGIN - 2; i++) { // sobra lugar p/ dígito e '\0'
        int comeca_palavra = nome[i] != ' ' && (i == 0 || nome[i - 1] == ' ');
        if (i >= ultimo || comeca_palavra) {
            login[j] = (char) tolower((unsigned char) nome[i]);
            j++;
        }
    }
    login[j] = '\0';
}

int buscar(char logins[][TAM_LOGIN], int n, const char login[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(logins[i], login) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char logins[MAX][TAM_LOGIN];
    int total = 0;
    char linha[TAM_LINHA];

    while (total < MAX && fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strlen(linha) == 0) {
            continue; // linha em branco não vira login
        }

        char base[TAM_LOGIN];
        gerar_login(linha, base);
        strcpy(logins[total], base);

        // já existe? tenta base2, base3... até achar um livre
        for (int k = 2; buscar(logins, total, logins[total]) >= 0; k++) {
            strcpy(logins[total], base);
            size_t fim = strlen(logins[total]);
            logins[total][fim] = (char) ('0' + k);
            logins[total][fim + 1] = '\0';
        }

        printf("%-22s -> %s\n", linha, logins[total]);
        total++;
    }
    printf("%d logins criados\n", total);
    return 0;
}
// Entrada (um nome por linha, com uma linha em branco depois do 3º):
// Ana Paula Souza, Joao Lima, Antonio Pedro Souza, Bia Alves, Amanda P Souza
// Saída:
// Ana Paula Souza        -> apsouza
// Joao Lima              -> jlima
// Antonio Pedro Souza    -> apsouza2
// Bia Alves              -> balves
// Amanda P Souza         -> apsouza3
// 5 logins criados
