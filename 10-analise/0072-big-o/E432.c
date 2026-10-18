// 0072 · Notação O: como o custo cresce
// Exercício E432 · ★★★
//
// Este programa conta as vogais de um texto de n letras. A função tamanho()
// faz o mesmo que o strlen (anda até o '\0') e conta cada letra visitada como
// um passo. Rode e veja os passos para n = 1000, 2000 e 4000:
//
//   n = 1000: 400 vogais, 1001000 passos
//   n = 2000: 800 vogais, 4002000 passos
//   n = 4000: 1600 vogais, 16004000 passos
//
// 1. Acrescente ao main a regra do dobro: a partir do segundo n, mostre na
// mesma linha a razão entre os passos deste n e os do anterior. Rode: a razão
// denuncia a classe do código.
// 2. Refatore conta_vogais para ficar O(n), sem mudar a função tamanho(), e
// rode de novo.
//
//   Saída esperada (depois do conserto):
//   n = 1000: 400 vogais, 1000 passos
//   n = 2000: 800 vogais, 2000 passos, razão 2.00
//   n = 4000: 1600 vogais, 4000 passos, razão 2.00
//
// Dicas:
// 1. Guarde os passos do n anterior numa variável e use (double) na divisão.
// 2. Antes do conserto a razão sai 4.00: O(n²). Quantas vezes a condição do
//    for é avaliada? E o que ela chama?
// 3. O texto não muda dentro do laço. Precisa medir o tamanho dele toda vez?
// 4. Resposta esperada: guarde o tamanho numa variável antes do laço
//    (int n = tamanho(texto);) e use i < n. Os passos caem para 1000, 2000 e
//    4000, e a razão vira 2.00: O(n).
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>

long passos = 0;

int tamanho(const char *s) {
    int t = 0;
    while (s[t] != '\0') {
        passos++;
        t++;
    }
    return t;
}

int conta_vogais(const char *texto) {
    int vogais = 0;
    for (int i = 0; i < tamanho(texto); i++) {
        char c = texto[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vogais++;
        }
    }
    return vogais;
}

int main(void) {
    static char texto[4001];
    int tamanhos[3] = {1000, 2000, 4000};

    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            texto[i] = "abcde"[i % 5]; // a, b, c, d, e, a, b, ...
        }
        texto[n] = '\0';
        passos = 0;
        int v = conta_vogais(texto);
        printf("n = %d: %d vogais, %ld passos\n", n, v, passos);
    }
    return 0;
}
