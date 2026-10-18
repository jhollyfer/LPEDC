// 0058 · Pilha e heap
// Exercício E348 · ★★★
//
// Este programa compila com um AVISO (warning) de propósito e mostra lixo ou
// quebra. Rode, leia o aviso e responda: qual é o problema? Depois conserte
// sem usar static nem malloc: quem chama empresta o vetor.
//
//   Saída esperada depois do conserto:
//   Senha: A042
//   Senha: A107
//
// Dicas:
// 1. Procure "returns address of local variable" no aviso.
// 2. O vetor senha mora no frame de montar_senha. Para onde vai esse frame
//    depois do return?
// 3. Resposta esperada: a função devolve o endereço de um vetor local, que
//    morre no return (o gcc até troca o endereço por NULL). Conserto:
//    void montar_senha(int numero, char senha[]) e, em main,
//    char senha[8]; montar_senha(42, senha);
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

char *montar_senha(int numero) {
    char senha[8];
    senha[0] = 'A';
    senha[1] = (char)('0' + numero / 100);
    senha[2] = (char)('0' + numero / 10 % 10);
    senha[3] = (char)('0' + numero % 10);
    senha[4] = '\0';
    return senha;
}

int main(void) {
    printf("Senha: %s\n", montar_senha(42));
    printf("Senha: %s\n", montar_senha(107));
    return 0;
}
