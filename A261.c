// A261 · Potência rápida sem recursão: os bits do expoente

#include <stdio.h>

// base^exp % m sem recursão: lê o expoente bit a bit, do menos significativo
// para o mais significativo. A cada volta, "base" vira o quadrado dela
// (b, b^2, b^4, b^8...) e entra no resultado quando o bit vale 1.
long long potencia_mod(long long base, long long exp, long long m) {
    long long r = 1;
    base %= m;
    printf("bit  base  resultado\n");
    while (exp > 0) {
        int bit = exp & 1;
        if (bit) {
            r = r * base % m;  // este pedaço do expoente entra na conta
        }
        printf("%3d  %4lld  %9lld\n", bit, base, r);
        base = base * base % m; // próxima potência: o quadrado da atual
        exp >>= 1;              // anda um bit para a esquerda
    }
    return r;
}

int main(void) {
    const char *dias[] = {"domingo", "segunda", "terça", "quarta",
                          "quinta", "sexta", "sábado"};
    // hoje é domingo: que dia da semana será daqui a 2^100 dias?
    // 100 em binário é 1100100: 7 bits, 7 voltas
    long long resto = potencia_mod(2, 100, 7);
    printf("2^100 dias: %lld dia(s) além de semanas inteiras -> %s\n\n",
           resto, dias[resto]);

    // os 4 últimos dígitos de 2^64, que não cabe nem num unsigned long long
    // (o maior é 2^64 - 1); com % 10000, nenhuma conta passa de 10^8
    long long fim = potencia_mod(2, 64, 10000);
    printf("2^64 termina em %04lld\n", fim);
    return 0;
}
// Saída:
// bit  base  resultado
//   0     2          1
//   0     4          1
//   1     2          2
//   0     4          2
//   0     2          2
//   1     4          1
//   1     2          2
// 2^100 dias: 2 dia(s) além de semanas inteiras -> terça
//
// bit  base  resultado
//   0     2          1
//   0     4          1
//   0    16          1
//   0   256          1
//   0  5536          1
//   0  7296          1
//   1  1616       1616
// 2^64 termina em 1616
