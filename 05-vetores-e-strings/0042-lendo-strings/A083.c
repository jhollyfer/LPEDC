// A083 · O recado que termina numa linha vazia

#include <stdio.h>
#include <string.h>

#define TAM 60

int main(void) {
    char linha[TAM];
    int linhas = 0;
    size_t letras = 0;

    printf("Digite o recado (linha vazia termina):\n");
    // para no fim da entrada (NULL) ou numa linha vazia, o que vier primeiro
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strlen(linha) == 0) { // só o Enter: depois de tirar o '\n', sobra ""
            break;
        }
        linhas++;
        letras += strlen(linha);
        printf("%d| %s\n", linhas, linha);
    }

    printf("%d linhas, %zu caracteres\n", linhas, letras);
    return 0;
}
// Digite o recado (linha vazia termina):
// Chego umas 19h
// 1| Chego umas 19h
// Deixa a chave com a vizinha
// 2| Deixa a chave com a vizinha
//
// 2 linhas, 41 caracteres
