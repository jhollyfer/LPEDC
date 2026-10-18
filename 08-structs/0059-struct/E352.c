// 0059 · Struct
// Exercício E352 · ★★☆
//
// Este programa NÃO compila, de propósito: ele tem três erros clássicos de
// struct. Rode, leia as mensagens do gcc e conserte um por um. O programa
// consertado guarda a artilheira em a, copia para b e confere se as duas
// fichas são iguais.
//
//   Saída esperada (depois de consertado):
//   Marta: 17 gols
//   a e b são iguais
//
// Dicas:
// 1. O primeiro erro está antes do main: a mensagem aponta para a linha do
//    main, mas o culpado é a linha de cima.
// 2. Campo vetor não recebe texto com =. Qual função de string.h copia?
// 3. Struct não se compara com ==: compare campo a campo (strcmp para o nome).
// 4. Resposta esperada: falta ; depois da } da struct; a.nome = "Marta" vira
//    strcpy(a.nome, "Marta"); a == b vira strcmp(a.nome, b.nome) == 0 &&
//    a.gols == b.gols.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

struct jogadora {
    char nome[20];
    int gols;
}

int main(void) {
    struct jogadora a, b;

    a.nome = "Marta";
    a.gols = 17;
    b = a;

    printf("%s: %d gols\n", b.nome, b.gols);
    if (a == b) {
        printf("a e b são iguais\n");
    }
    return 0;
}
