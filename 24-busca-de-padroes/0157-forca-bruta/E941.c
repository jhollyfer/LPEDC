// 0157 · Força bruta
// Exercício E941 · ★★★
//
// Ache o bug. Esta força bruta usa size_t, o tipo que o strlen devolve. Os
// dois primeiros testes dão certo, mas no terceiro o AddressSanitizer do
// rodar para o programa com "global-buffer-overflow" (é de propósito). Rode,
// leia o erro, conserte e rode de novo.
//
//   Saída esperada (depois de consertar):
//   2
//   2
//   0
//
// Dicas:
// 1. No terceiro teste, n = 3 e m = 9. Quanto vale n - m em size_t?
// 2. size_t não tem sinal: 3 - 9 dá a volta e vira um número enorme
//    (18446744073709551610 em 64 bits). O laço segue lendo além do '\0'.
// 3. Dois consertos possíveis: sair cedo com "if (m > n) return 0;" antes
//    do laço, ou escrever a condição como i + m <= n, que nunca dá a volta.
// 4. Resposta esperada: 2, 2 e 0, sem erro do sanitizer.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int conta(const char *texto, const char *padrao) {
    size_t n = strlen(texto);
    size_t m = strlen(padrao);
    int total = 0;
    for (size_t i = 0; i <= n - m; i++) {
        size_t j = 0;
        while (j < m && texto[i + j] == padrao[j]) {
            j++;
        }
        if (j == m) {
            total++;
        }
    }
    return total;
}

int main(void) {
    printf("%d\n", conta("pix pix", "pix"));
    printf("%d\n", conta("banana", "ana"));
    printf("%d\n", conta("pix", "pagamento"));
    return 0;
}
