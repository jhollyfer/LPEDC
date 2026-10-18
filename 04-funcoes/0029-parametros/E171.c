// 0029 · Parâmetros e passagem por valor
// Exercício E171 · ★★☆
//
// O programa abaixo deveria mostrar as duas notas em ordem crescente, mas
// mostra "Em ordem: 9 e 6": a troca dentro de ordenar não chega ao main.
// Conserte e rode até aparecer "Em ordem: 6 e 9". Você ainda não pode usar
// ponteiros: troque "ordenar" por duas funções que devolvem valor, "menor" e
// "maior", e use as duas no printf.
//
// Dicas:
// 1. Uma função em C devolve um valor só, pelo return. A troca dentro de
//    ordenar acontece nas cópias.
// 2. printf("Em ordem: %d e %d\n", menor(a, b), maior(a, b));
// 3. Resposta esperada: "Em ordem: 6 e 9". A troca de verdade, com a função
//    mexendo nas variáveis do main, precisa de ponteiros (assunto 0046).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

void ordenar(int a, int b) {
    if (a > b) {
        int aux = a;
        a = b;
        b = aux;
    }
}

int main(void) {
    int a = 9;
    int b = 6;

    ordenar(a, b);
    printf("Em ordem: %d e %d\n", a, b);
    return 0;
}
