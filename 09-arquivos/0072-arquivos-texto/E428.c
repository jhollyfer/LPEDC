// 0072 · Arquivos texto
// Exercício E428 · ★☆☆
//
// Preveja a saída antes de rodar. O programa abre o MESMO arquivo quatro
// vezes, alternando os modos "w" e "a", e grava um nome em cada vez. No fim,
// mostra o que sobrou no arquivo. Abra o E428.c para ler o código.
//
// Dicas:
// 1. "w" cria o arquivo vazio, apagando o que já existia.
// 2. "a" abre e escreve depois do último byte, sem apagar nada.
// 3. Resposta esperada: duas linhas, "Caio" e "Duda". Ana e Bia sumiram
//    quando o terceiro fopen abriu com "w".
//
// Escreva sua resposta abaixo (um comentário com a saída prevista) e depois
// rode para conferir:

#include <stdio.h>

void grava(const char *caminho, const char *modo, const char *nome) {
    FILE *arq = fopen(caminho, modo);
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    fprintf(arq, "%s\n", nome);
    fclose(arq);
}

int main(void) {
    const char *caminho = "/tmp/fila.txt";
    grava(caminho, "w", "Ana");
    grava(caminho, "a", "Bia");
    grava(caminho, "w", "Caio");
    grava(caminho, "a", "Duda");

    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[50];
    while (fgets(linha, sizeof linha, arq) != NULL) {
        printf("%s", linha);
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
