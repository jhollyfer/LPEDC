// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1819 · ★★☆ · Qual base para o radix? Conte as operações
//
// O radix sort LSD de inteiros sem sinal de 32 bits pode olhar r bits por
// passada (base b = 2^r): são ⌈32 / r⌉ passadas de Θ(n + b) cada. Base
// pequena faz muitas passadas; base grande faz poucas, mas cada uma paga o
// vetor C de b posições.
//
// Escreva radix(v, n, r), que funciona para r = 1, 4, 8 e 16, e conte as
// operações: cada passada soma n (contagem) + b (somas acumuladas) + n
// (colocação) + n (cópia de volta). Ordene cópias dos mesmos 100000 códigos
// de produto (sorteados no esqueleto) com cada r, confira o resultado e
// mostre passadas, operações e operações por elemento. Depois, repita com só
// n = 1000 elementos.
//
//   Saída esperada:
//   n = 100000
//     r =  1: 32 passadas, 9600064 operações ( 96.0 por item), ordenado
//     r =  4:  8 passadas, 2400128 operações ( 24.0 por item), ordenado
//     r =  8:  4 passadas, 1201024 operações ( 12.0 por item), ordenado
//     r = 16:  2 passadas,  731072 operações (  7.3 por item), ordenado
//   n = 1000
//     r =  1: 32 passadas,   96064 operações ( 96.1 por item), ordenado
//     r =  4:  8 passadas,   24128 operações ( 24.1 por item), ordenado
//     r =  8:  4 passadas,   13024 operações ( 13.0 por item), ordenado
//     r = 16:  2 passadas,  137072 operações (137.1 por item), ordenado
//
// Dicas:
// 1. Dígito da passada p: (x >> (p · r)) & (b - 1). Use unsigned para que o
//    deslocamento não mexa no sinal.
// 2. O vetor C de r = 16 tem 65536 posições: deixe-o static, e zere só as b
//    posições usadas em cada passada.
// 3. Fórmula: ⌈32/r⌉ · (3n + b). Com n grande, r = 16 ganha (2 passadas);
//    com n pequeno, o b = 65536 pesa mais que o n, e r = 8 ganha.
// 4. Resposta esperada: com n = 100000, r = 16 ganha (731072 operações,
//    contra 1201024 de r = 8); com n = 1000, r = 8 ganha (13024, contra
//    137072 de r = 16).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAXN 100000

unsigned semente = 99;

unsigned sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    unsigned alto = semente >> 16;
    semente = semente * 1103515245u + 12345u;
    return (alto << 16) | (semente >> 16); // 32 bits
}

int main(void) {
    static unsigned original[MAXN];
    for (int i = 0; i < MAXN; i++) original[i] = sorteia();

    printf("%u %u\n", original[0], original[1]);
    return 0;
}
