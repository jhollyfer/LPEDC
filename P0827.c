// Lista · Módulo 08 · Tipos compostos
// Exercício P0827 · ★★★ · O crivo de primos em bits
//
// O crivo de Eratóstenes marca os números compostos até N. Com um bool por
// número, N = 1000 gasta 1001 bytes; com um BIT por número, gasta 126. Crie
//
//   typedef struct { int n; unsigned char bits[126]; } Crivo;
//
// em que o bit k ligado quer dizer "k é composto". Escreva void
// montar(Crivo *c, int n), bool eh_primo(const Crivo *c, int k) e use-as
// para mostrar quantos primos há até 1000, os primos entre 900 e 1000, o
// maior intervalo entre dois primos seguidos até 1000 e a memória usada:
//
//   Saída esperada:
//   Primos até 1000: 168
//   Entre 900 e 1000: 907 911 919 929 937 941 947 953 967 971 977 983 991 997
//   Maior intervalo: 20 (de 887 a 907)
//   Memória: 126 bytes de bits (com bool seriam 1001)
//
// Dicas:
// 1. Ligue os bits de 0 e 1 (não são primos). Para cada i com i * i <= n
//    que ainda é primo, marque i * i, i * i + i, i * i + 2i, ... como
//    compostos.
// 2. Ligar o bit k: c->bits[k / 8] |= 1u << (k % 8). Testar: (c->bits[k /
//    8] >> (k % 8)) & 1.
// 3. Para o maior intervalo, guarde o primo anterior enquanto anda de 2 a
//    1000.
// 4. Resposta esperada: a saída acima (168 primos).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int n;
    unsigned char bits[126];
} Crivo;

int main(void) {

    return 0;
}
