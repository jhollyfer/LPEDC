// 0042 · Lendo strings
// Exercício E248 · ★☆☆
//
// O programa abaixo faz três leituras seguidas. Rode-o digitando a linha
//
//   Maria Clara Souza
//
// mas ANTES preveja o que aparece entre cada par de colchetes.
//
// Dicas:
// 1. O %s para no primeiro espaço; %4s lê no máximo 4 caracteres.
// 2. O que o scanf não leu continua na entrada, esperando a próxima leitura.
// 3. O fgets pega o que sobrou da linha, do ponto exato em que o scanf
//    parou, e vai até o Enter.
// 4. Resposta esperada: [Maria] [Clar] [a Souza]. Cada %s pula os espaços
//    antes de ler; o fgets não pula nada.
//
// Escreva sua resposta abaixo (o código está pronto para conferir):

#include <stdio.h>
#include <string.h>

int main(void) {
    char a[20], b[20], resto[20];

    if (scanf("%19s", a) != 1 || scanf("%4s", b) != 1) {
        return 1;
    }
    if (fgets(resto, sizeof(resto), stdin) == NULL) {
        return 1;
    }
    resto[strcspn(resto, "\n")] = '\0';

    printf("[%s] [%s] [%s]\n", a, b, resto);
    return 0;
}
