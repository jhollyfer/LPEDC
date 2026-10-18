// 0042 · Lendo strings
// Exercício E248 · ★☆☆
//
// O programa abaixo faz três leituras seguidas da mesma linha: dois scanf e um
// fgets. Troque o printf final por um printf depois de CADA leitura, que
// mostre o que ela pegou entre colchetes e o strlen. No fgets, mostre o
// strlen antes e depois de tirar o '\n'. Rode digitando a linha
//
//   Maria Clara Souza
//
//   Saída esperada (depois da linha digitada):
//   1ª leitura: [Maria] (5)
//   2ª leitura: [Clar] (4)
//   fgets: 8 com o '\n', limpo: [a Souza] (7)
//
// Para testar sem digitar: printf 'Maria Clara Souza\n' | ~/LPEDC/rodar
// seguido do caminho deste arquivo.
//
// Dicas:
// 1. O %s para no primeiro espaço; %4s lê no máximo 4 caracteres.
// 2. O que o scanf não leu continua na entrada, esperando a próxima leitura.
//    Cada %s pula os espaços antes de ler; o fgets não pula nada.
// 3. O fgets pega o resto da linha do ponto exato em que o scanf parou, com
//    o '\n' no fim. Guarde o strlen num size_t antes do strcspn.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o programa):

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
