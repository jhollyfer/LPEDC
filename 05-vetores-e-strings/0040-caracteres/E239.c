// 0040 · Caracteres
// Exercício E239 · ★★★
//
// O programa abaixo deveria contar as letras de uma senha guardada num vetor
// de char. A senha tem 4 letras (a, B, z, Q), mas ele mostra outro número. O
// código compila sem aviso e roda sem erro do sanitizer: o erro é de lógica,
// de propósito.
//
//   1. Dentro do if, acrescente um printf que mostre cada caractere contado e
//      o código dele ("contou: _ (95)"). Rode e veja quem entrou sem ser
//      letra.
//   2. Conserte o teste com isalpha e rode.
//   3. Troque por uma versão sem o ctype.h (só comparações com a tabela
//      ASCII), rode de novo e confira que dá o mesmo resultado.
//
//   Saída esperada depois do conserto (com o printf do passo 1):
//   contou: a (97)
//   contou: B (66)
//   contou: z (122)
//   contou: Q (81)
//   Letras na senha: 4
//
// Dicas:
// 1. Olhe a tabela ASCII entre o 'Z' (90) e o 'a' (97).
// 2. Quais caracteres da senha estão nesse buraco?
// 3. Resposta esperada: antes do conserto, mostra 7. O teste
//    c >= 'A' && c <= 'z' aceita '_' (95), '[' (91) e '^' (94), que ficam
//    entre 'Z' e 'a'. Conserto: isalpha(c) ou
//    (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'), e a saída acima.
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
