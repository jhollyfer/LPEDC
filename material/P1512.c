// Lista · Módulo 15 · Tabelas hash
// Exercício P1512 · ★★☆ · Contando as palavras do trava-língua
//
// Conte quantas vezes cada palavra aparece no trava-língua
//
//   o rato roeu a roupa do rei de roma e o rei riu do rato
//
// com uma tabela hash de 7 baldes, encadeamento (palavra nova entra no
// início da corrente) e o hash djb2 (h = 5381; h = h * 33 + c), balde =
// djb2 % 7. Cada nó guarda a palavra (char palavra[16]), o contador e o
// prox. Separe as palavras pelos espaços, andando na frase caractere por
// caractere. No fim, mostre cada balde com palavra=vezes, os totais, e
// libere a tabela.
//
//   Saída esperada:
//   0: e=1
//   1: riu=1 do=2
//   2: roma=1 rato=2
//   3: a=1 roeu=1 o=2
//   4: rei=2 roupa=1
//   5: de=1
//   6:
//   15 palavras, 11 distintas
//
// Dicas:
// 1. conta(t, p): procura p na corrente do balde; achou, soma 1; não achou,
//    cria o nó com vezes = 1 no início.
// 2. Para separar: junte os caracteres num buffer até achar ' ' ou '\0';
//    aí feche com '\0', conte e recomece. Trate o '\0' DENTRO do laço, para
//    a última palavra não ficar de fora.
// 3. A palavra "o" aparece depois de "roeu" no balde 3 porque já existia
//    quando a frase passou pelo segundo "o": só o contador muda.
// 4. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e o rei riu do rato";
    (void)frase;

    return 0;
}
