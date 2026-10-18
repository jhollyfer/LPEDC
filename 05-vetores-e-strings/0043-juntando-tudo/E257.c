// 0043 · Juntando tudo
// Exercício E257 · ★★★
//
// O programa abaixo deveria mostrar o nome de trás para frente. Ele tem DOIS
// erros de propósito. Rode com o rodar: o sanitizer acusa um. Conserte esse,
// rode de novo e veja o outro: o programa passa a mostrar uma linha vazia.
//
//   Saída esperada depois do conserto:
//   aluaP anA
//
// Dicas:
// 1. "Ana Paula" tem quantos caracteres? E quantos bytes precisa para ser
//    guardado como string?
// 2. Quando i vale 0, qual caractere vai para invertido[0]? Lembre o que
//    mora em nome[strlen(nome)].
// 3. Uma string que começa com '\0' é vazia, não importa o resto.
// 4. Resposta esperada: invertido[9] não tem lugar para os 9 caracteres e o
//    '\0' (use invertido[10] ou maior); e o laço copia nome[n] (o '\0') para
//    invertido[0]. Conserto: for (i = 0; i < n; i++) invertido[i] =
//    nome[n - 1 - i]; e depois invertido[n] = '\0'.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[] = "Ana Paula";
    char invertido[9];
    int n = (int) strlen(nome);

    for (int i = 0; i <= n; i++) {
        invertido[i] = nome[n - i];
    }
    printf("%s\n", invertido);
    return 0;
}
