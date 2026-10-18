// A126 · Uma linha de qualquer tamanho

#include <stdio.h>
#include <stdlib.h>

// Lê uma linha inteira, de qualquer tamanho, num bloco que cresce.
// Devolve NULL no fim da entrada (ou se faltar memória). Quem chama libera.
char *ler_linha(void) {
    int cap = 4;
    int qtd = 0;
    char *linha = malloc(cap);
    if (linha == NULL) {
        return NULL;
    }
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (qtd + 1 == cap) { // + 1: sempre sobra lugar para o '\0'
            char *maior = realloc(linha, cap * 2);
            if (maior == NULL) {
                free(linha);
                return NULL;
            }
            linha = maior;
            cap *= 2;
        }
        linha[qtd++] = (char)c;
    }
    if (c == EOF && qtd == 0) { // acabou a entrada
        free(linha);
        return NULL;
    }
    linha[qtd] = '\0';
    return linha;
}

int main(void) {
    char *nome;
    int n = 0;
    while ((nome = ler_linha()) != NULL) {
        n++;
        int tamanho = 0;
        while (nome[tamanho] != '\0') {
            tamanho++;
        }
        printf("Nome %d (%d bytes): %s\n", n, tamanho, nome);
        free(nome); // cada linha é um bloco novo
    }
    return 0;
}
// Exemplo de uso (os nomes vêm do teclado; Ctrl+D encerra):
// Ana
// Nome 1 (3 bytes): Ana
// Maria Eduarda dos Santos
// Nome 2 (24 bytes): Maria Eduarda dos Santos
//
// Para testar: printf 'Ana\nMaria Eduarda dos Santos\n' | ~/LPEDC/rodar 07-memoria-dinamica/0063-juntando-tudo/A126.c
// Nenhum fgets com tamanho fixo: o bloco cresce 4 -> 8 -> 16 -> 32.
