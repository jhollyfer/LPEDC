// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0919 · ★★☆ · A votação em que o "sim" nunca vence
//
// O condomínio votou a troca do portão, e cada voto ficou numa linha do
// arquivo: sim, nao, sim, sim. O programa abaixo compila sem aviso, mas
// mostra "Votos sim: 2, não: 2, inválidos: 0", um empate que não houve.
// Há DOIS erros de propósito:
// um faz toda comparação falhar e outro faz a ÚLTIMA linha ser contada
// diferente das outras quando o arquivo não termina com '\n'. Conserte
// os dois (sem mudar o que é gravado no arquivo).
//
//   Saída esperada:
//   Votos sim: 3, não: 1, inválidos: 0
//
// Dicas:
// 1. O que o fgets guarda no vetor, além das letras? Acrescente um
//    printf("[%s]\n", linha) no laço e rode para ver.
// 2. Cortar o último caractere "na marra" (linha[strlen(linha) - 1] = '\0')
//    estraga a linha que não tem '\n': ela perde uma letra de verdade.
// 3. Resposta esperada: troque o corte na marra por
//    linha[strcspn(linha, "\n")] = '\0' e compare com strcmp(...) == 0 (o
//    código compara com != 0). A saída fica igual à de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *caminho = "/tmp/p0919_votos.txt";
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "sim\nnao\nsim\nsim"); // a última linha não tem '\n'
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[16];
    int sim = 0, nao = 0, invalidos = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        linha[strlen(linha) - 1] = '\0'; // tira o '\n'
        if (strcmp(linha, "sim") != 0) {
            sim++;
        } else if (strcmp(linha, "nao") != 0) {
            nao++;
        } else {
            invalidos++;
        }
    }
    fclose(arq);
    remove(caminho);

    printf("Votos sim: %d, não: %d, inválidos: %d\n", sim, nao, invalidos);
    return 0;
}
