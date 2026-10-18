// 0067 · Ponteiro para struct
// Exercício E400 · ★★☆
//
// Este programa compila com um AVISO e quebra quando roda. Leia o aviso do
// gcc, entenda o problema e conserte usando malloc. Atenção: depois do
// conserto, o AddressSanitizer ainda vai reclamar de outra coisa. Resolva
// também.
//
//   Saída esperada (depois de consertado):
//   Fone Bluetooth: R$ 149.90
//
// Dicas:
// 1. O aviso diz "function returns address of local variable". A variável p
//    mora no frame de criar_produto, que é desmontado no return.
// 2. Aloque o produto no heap: Produto *p = malloc(sizeof *p); e use p->.
// 3. Memória do heap não some sozinha: quem recebeu o ponteiro dá free.
// 4. Resposta esperada: criar_produto passa a alocar com malloc (conferindo
//    NULL) e o main faz free(fone) no fim; sem o free, o ASan acusa
//    "detected memory leaks".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    double preco;
} Produto;

Produto *criar_produto(const char *nome, double preco) {
    Produto p;
    strcpy(p.nome, nome);
    p.preco = preco;
    return &p;
}

int main(void) {
    Produto *fone = criar_produto("Fone Bluetooth", 149.90);
    printf("%s: R$ %.2f\n", fone->nome, fone->preco);
    return 0;
}
