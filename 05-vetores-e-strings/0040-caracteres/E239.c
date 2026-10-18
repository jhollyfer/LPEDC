// 0040 · Caracteres
// Exercício E239 · ★★★
//
// O programa abaixo deveria contar as letras de uma senha guardada num vetor
// de char. A senha tem 4 letras (a, B, z, Q), mas ele mostra outro número. O
// código compila sem aviso e roda sem erro do sanitizer: o erro é de lógica,
// de propósito.
//
//   1. Sem rodar: que número ele mostra?
//   2. Por quê? Quais caracteres foram contados como letra sem ser?
//   3. Conserte de dois jeitos: com isalpha e sem o ctype.h.
//
//   Saída esperada depois do conserto:
//   Letras na senha: 4
//
// Dicas:
// 1. Olhe a tabela ASCII entre o 'Z' (90) e o 'a' (97).
// 2. Quais caracteres da senha estão nesse buraco?
// 3. Resposta esperada: mostra 7. O teste c >= 'A' && c <= 'z' aceita '_'
//    (95), '[' (91) e '^' (94), que ficam entre 'Z' e 'a'. Conserto:
//    isalpha(senha[i]) ou (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z').
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char senha[] = {'a', 'B', '_', '9', 'z', '[', 'Q', '^'};
    int n = sizeof(senha);
    int letras = 0;

    for (int i = 0; i < n; i++) {
        char c = senha[i];
        if (c >= 'A' && c <= 'z') {
            letras++;
        }
    }
    printf("Letras na senha: %d\n", letras);
    return 0;
}
