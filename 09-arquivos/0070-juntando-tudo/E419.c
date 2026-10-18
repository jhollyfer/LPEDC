// 0070 · Juntando tudo
// Exercício E419 · ★★★
//
// Um diário de linha de comando: "anota <texto>" acrescenta uma linha em
// /tmp/diario.txt e mostra todas as anotações até agora. O esperado é:
//
//   $ rodar E419.c anota "comprar pão"
//   1 anotações:
//   comprar pão
//   $ rodar E419.c anota "pagar a luz"
//   2 anotações:
//   comprar pão
//   pagar a luz
//
// Mas o programa mostra "0 anotações:" toda vez, e depois de rodar as duas
// vezes o arquivo só tem "pagar a luz" (confira com cat /tmp/diario.txt).
// E "rodar E419.c anota", sem o texto, tem comportamento indefinido. Ache os
// TRÊS erros, conserte e rode as duas execuções de novo.
//
// Dicas:
// 1. Qual modo de abertura apaga o que já existia?
// 2. O fprintf grava direto no disco? Quando o buffer é descarregado? O
//    arquivo é aberto para leitura enquanto o de escrita ainda está aberto.
// 3. Conte os argumentos de "anota <texto>": quanto vale argc?
// 4. Resposta esperada: (1) "w" apaga o diário a cada execução; o certo é
//    "a". (2) Falta fclose(arq) antes de abrir para leitura: o texto ainda
//    está no buffer, então a leitura acha o arquivo vazio. (3) A conferência
//    deve ser argc != 3; com argc < 2, argv[2] pode ser NULL. Consertado, a
//    saída fica igual à do enunciado (apague /tmp/diario.txt antes de testar).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *caminho = "/tmp/diario.txt";
    if (argc < 2 || strcmp(argv[1], "anota") != 0) {
        fprintf(stderr, "Uso: %s anota <texto>\n", argv[0]);
        return 1;
    }

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "%s\n", argv[2]);

    FILE *leitura = fopen(caminho, "r");
    if (leitura == NULL) {
        perror(caminho);
        return 1;
    }
    char linhas[50][100];
    int n = 0;
    while (n < 50 && fgets(linhas[n], sizeof linhas[n], leitura) != NULL) {
        n++;
    }
    fclose(leitura);

    printf("%d anotações:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s", linhas[i]);
    }
    return 0;
}
