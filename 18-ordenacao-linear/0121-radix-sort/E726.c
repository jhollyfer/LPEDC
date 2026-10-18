// 0121 · Radix sort
// Exercício E726 · ★★★
//
// O extrato da conta tem saques (negativos) e depósitos (positivos), em
// centavos. O radix sort em base 256 olha os bits, e no complemento de dois
// o -7 é FFFFFFF9: como número sem sinal, ele é enorme. Por isso um radix
// ingênuo põe todos os negativos DEPOIS dos positivos.
//
// a) Escreva radix(v, aux, n, com_chave), um radix sort em base 256 para
// int32_t. Com com_chave = false, use os bits do número direto:
// (uint32_t) x. Rode e veja o problema.
//
// b) Com com_chave = true, use a chave (uint32_t) x ^ 0x80000000u, que
// inverte só o bit de sinal. Rode de novo.
//
//   Saída esperada:
//   -7 como uint32_t: FFFFFFF9
//   sem a chave: 0 7 3200 98000 2147483647 -2147483648 -150000 -98000 -7
//   com a chave: -2147483648 -150000 -98000 -7 0 7 3200 98000 2147483647
//
// Dicas:
// 1. Uma função uint32_t bits(int32_t x, bool com_chave) devolve a chave
//    certa; o resto do radix é o do exemplo A242, com bits(v[i], com_chave)
//    no lugar de v[i].
// 2. Por que a chave funciona? INT_MIN (80000000) vira 00000000, -1
//    (FFFFFFFF) vira 7FFFFFFF, 0 vira 80000000 e INT_MAX vira FFFFFFFF: a
//    ordem dos int passa a ser a ordem dos uint32_t.
// 3. Só a chave muda: o vetor continua guardando os int32_t originais.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

void testa(const char *rotulo, bool com_chave) {
    // movimentações da conta, em centavos: saques negativos, depósitos positivos
    int32_t mov[] = {-150000, 3200, -7, 0, INT_MAX, INT_MIN, 98000, -98000, 7};
    int32_t aux[9];
    int n = 9;
    (void) aux;       // apague estas duas linhas
    (void) com_chave; // e chame radix(mov, aux, n, com_chave) aqui

    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", (int) mov[i]);
    }
    printf("\n");
}

int main(void) {
    printf("-7 como uint32_t: %08X\n", (unsigned) (uint32_t) -7);
    testa("sem a chave:", false);
    testa("com a chave:", true);
    return 0;
}
