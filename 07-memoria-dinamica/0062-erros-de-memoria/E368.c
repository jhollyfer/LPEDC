// 0062 · Erros de memória
// Exercício E368 · ★☆☆
//
// Cada trecho abaixo é a primeira linha de um relatório do
// AddressSanitizer. Para cada um, diga qual erro aconteceu e dê um exemplo
// de código que causaria aquilo.
//
//   a) ERROR: AddressSanitizer: heap-buffer-overflow on address ...
//      WRITE of size 4 ... is located 0 bytes after 16-byte region
//   b) ERROR: AddressSanitizer: heap-use-after-free on address ...
//   c) ERROR: AddressSanitizer: attempting double-free on ...
//   d) ERROR: LeakSanitizer: detected memory leaks
//   e) ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000
//
// Em a), quantos ints tinha o bloco e qual índice foi usado?
//
// Dicas:
// 1. "0 bytes after" quer dizer "logo depois do último byte do bloco".
// 2. O endereço 0x0 é o NULL.
// 3. Resposta esperada: a) estouro: escreveu além do fim do bloco; 16
//    bytes são 4 ints e o índice usado foi 4 (ex.: for com i <= 4);
//    b) uso depois do free: free(p); printf("%d", p[0]);
//    c) free duplo: free(p); free(p); d) vazamento: malloc sem free;
//    e) acesso pelo ponteiro NULL: p = malloc(...) falhou e ninguém
//    conferiu, ou int *p = NULL; *p = 1;
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
