// A276 · Duas variáveis bastam (até o long long acabar)

#include <limits.h>
#include <stdio.h>

// formas de subir n degraus de 1 ou 2 em 2, de baixo para cima, guardando só
// os dois últimos valores: O(1) de memória em vez de um vetor de n posições
int main(void) {
    long long dois_atras = 1;   // formas(0)
    long long um_atras = 1;     // formas(1)
    int n = 1;

    while (1) {
        // a próxima soma cabe no long long? confere ANTES de somar
        if (um_atras > LLONG_MAX - dois_atras) {
            break;
        }
        long long atual = um_atras + dois_atras;
        dois_atras = um_atras;      // a janela anda um degrau:
        um_atras = atual;           // o velho "um atrás" vira "dois atrás"
        n++;
        if (n == 10 || n == 50 || n == 90) {
            printf("formas(%d) = %lld\n", n, um_atras);
        }
    }
    printf("o último que cabe: formas(%d) = %lld\n", n, um_atras);
    printf("formas(%d) passaria de LLONG_MAX = %lld\n", n + 1, LLONG_MAX);
    return 0;
}
// Saída:
// formas(10) = 89
// formas(50) = 20365011074
// formas(90) = 4660046610375530309
// o último que cabe: formas(91) = 7540113804746346429
// formas(92) passaria de LLONG_MAX = 9223372036854775807
