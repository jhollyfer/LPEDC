// 0158 · KMP
// Exercício E945 · ★★☆
//
// O log do servidor chega pelo teclado (ou por um cano), letra por letra, e
// pode ser enorme: não dá para guardar tudo num vetor. Escreva um programa
// que lê com getchar até o EOF e, usando KMP, mostra a linha e a coluna
// (contando de 1) de cada "erro". Ele não guarda o texto: só o k, a linha e a
// coluna. Teste assim:
//
//   printf 'ok\nerro 42\nok\nterror no erro\n' | ~/LPEDC/rodar E945.c
//
//   Saída esperada:
//   linha 2, coluna 1
//   linha 4, coluna 2
//   linha 4, coluna 11
//   3 ocorrências
//
// Dicas:
// 1. Guarde o getchar num int, não num char: o EOF não cabe num char.
// 2. Em cada '\n': linha++, coluna = 0 e k = 0 (a palavra não atravessa a
//    quebra). Nas outras letras: coluna++ e o passo do KMP.
// 3. Quando k == m, a palavra começou na coluna coluna - m + 1.
// 4. O "erro" dentro de "terror" conta. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAX 32

void calcula_pi(const char *p, int m, int pi[]) {
    int k = 0;
    pi[0] = 0;
    for (int j = 1; j < m; j++) {
        while (k > 0 && p[j] != p[k]) {
            k = pi[k - 1];
        }
        if (p[j] == p[k]) {
            k++;
        }
        pi[j] = k;
    }
}

int main(void) {

    return 0;
}
