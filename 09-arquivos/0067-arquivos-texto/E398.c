// 0067 · Arquivos texto
// Exercício E398 · ★☆☆
//
// O programa abre o MESMO arquivo quatro vezes, alternando os modos "w" e
// "a", e grava um nome em cada vez. A função grava já está pronta. Escreva a
// função mostra, que abre o arquivo para leitura, lê linha por linha com
// fgets e imprime todos os nomes na mesma linha, separados por espaço.
// Depois chame mostra logo após cada grava no main, para enxergar o que cada
// modo fez com o arquivo:
//
//   Saída esperada:
//   w Ana  -> Ana
//   a Bia  -> Ana Bia
//   w Caio -> Caio
//   a Duda -> Caio Duda
//
// Dicas:
// 1. "w" cria o arquivo vazio, apagando o que já existia; "a" escreve depois
//    do último byte, sem apagar nada.
// 2. Para imprimir o nome sem o '\n' que o fgets traz, troque o '\n' por
//    '\0': linha[strcspn(linha, "\n")] = '\0'; (strcspn é de <string.h>).
// 3. Resposta esperada: as quatro linhas acima. Ana e Bia somem quando o
//    terceiro fopen abre com "w".
//
// Escreva sua resposta abaixo (complete onde está o TODO):

#include <stdio.h>
#include <string.h>

void grava(const char *caminho, const char *modo, const char *nome) {
    FILE *arq = fopen(caminho, modo);
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    fprintf(arq, "%s\n", nome);
    fclose(arq);
}

// TODO: escreva void mostra(const char *caminho)

int main(void) {
    const char *caminho = "/tmp/fila.txt";
    grava(caminho, "w", "Ana");
    printf("w Ana  ->");
    // TODO: mostra(caminho);
    printf("\n");
    grava(caminho, "a", "Bia");
    grava(caminho, "w", "Caio");
    grava(caminho, "a", "Duda");
    // TODO: o mesmo para Bia, Caio e Duda

    remove(caminho);
    return 0;
}
