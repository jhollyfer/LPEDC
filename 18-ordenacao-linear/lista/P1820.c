// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1820 · ★★☆ · Counting sort custa n + k: quando o k atrapalha
//
// O counting sort é Θ(n + k): linear em n, mas paga o tamanho k do intervalo
// das chaves. Com k pequeno é imbatível; com k enorme, perde até para uma
// ordenação por comparação.
//
// Ordene n = 1000 valores sorteados com chaves em [0, k), para k = 10, 1000,
// 100000 e 1000000, com counting sort e com merge sort. Conte as operações
// do counting sort (n na contagem + k nas somas + n na colocação) e as
// comparações do merge sort. Mostre as contagens e quem ganhou, e confira que
// os dois resultados são iguais.
//
//   Saída esperada:
//         k  counting   merge  vencedor  iguais
//        10      2010    8507  counting  sim
//      1000      3000    8719  counting  sim
//    100000    102000    8706  merge     sim
//   1000000   1002000    8712  merge     sim
//
// Dicas:
// 1. O vetor C com 1 milhão de int ocupa 4 MB: deixe-o static.
// 2. O merge sort faz por volta de n lg n ≈ 10 mil comparações para n = 1000,
//    qualquer que seja k.
// 3. O ponto de virada fica onde 2n + k ≈ n lg n: com n = 1000, k na casa de
//    8 mil. Para chaves grandes (CPF, telefone), use radix sort, que quebra a
//    chave em dígitos pequenos.
// 4. Resposta esperada: counting ganha com k = 10 e k = 1000 (2010 e 3000
//    operações); merge ganha com k = 100000 e 1000000.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 1000

unsigned semente = 5;

int sorteia(int k) {
    semente = semente * 1103515245u + 12345u;
    unsigned x = (semente >> 16) << 15;
    semente = semente * 1103515245u + 12345u;
    return (int)((x | (semente >> 17)) % (unsigned)k);
}

int main(void) {
    int v[N];
    for (int i = 0; i < N; i++) v[i] = sorteia(1000);

    printf("%d %d\n", v[0], v[1]);
    return 0;
}
