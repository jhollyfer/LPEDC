// 0057 · Erros de memória
// Exercício E338 · ★☆☆
//
// Cada função abaixo tem UM erro de memória, de propósito, e cada uma gera
// um relatório diferente do AddressSanitizer:
//
//   heap-buffer-overflow    heap-use-after-free    attempting double-free
//   SEGV on unknown address 0x000000000000    LeakSanitizer: memory leaks
//
// O gcc até avisa sobre dois deles. O ASan para no primeiro erro: rode, leia
// a primeira linha do relatório, ache a função culpada pela pilha de
// chamadas e conserte com a menor mudança possível. Rode de novo e repita
// até as cinco linhas saírem e o programa terminar sem relatório nenhum.
//
//   Saída esperada depois dos consertos:
//   a) Notas: 7 8 9 10
//   b) Saldo: R$ 150
//   c) Senha 42 atendida
//   d) Cupom: 15% de desconto
//   e) Vagas livres: 3
//
// Dicas:
// 1. "0 bytes after 16-byte region" quer dizer "logo depois do último byte
//    de um bloco de 16 bytes": 4 ints, índices 0 a 3.
// 2. O endereço 0x0 é o NULL. O vazamento só é acusado no fim, quando todo
//    o resto já está certo.
// 3. Resposta esperada: a saída acima. a) i <= 4 vira i < 4 (estouro);
//    b) o printf vem antes do free (uso depois do free); c) apague o
//    segundo free (free duplo); d) acrescente free(cupom) (vazamento);
//    e) o ponteiro NULL precisa de um bloco: malloc e conferir o NULL antes
//    de escrever (e free no fim).
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

void notas(void) {
    int *v = malloc(4 * sizeof *v);
    if (v == NULL) {
        return;
    }
    printf("a) Notas:");
    for (int i = 0; i <= 4; i++) {
        v[i] = 7 + i;
        printf(" %d", v[i]);
    }
    printf("\n");
    free(v);
}

void saldo(void) {
    int *conta = malloc(sizeof *conta);
    if (conta == NULL) {
        return;
    }
    *conta = 150;
    free(conta);
    printf("b) Saldo: R$ %d\n", *conta);
}

void senha(void) {
    int *s = malloc(sizeof *s);
    if (s == NULL) {
        return;
    }
    *s = 42;
    printf("c) Senha %d atendida\n", *s);
    free(s);
    free(s);
}

void cupom(void) {
    int *cupom = malloc(sizeof *cupom);
    if (cupom == NULL) {
        return;
    }
    *cupom = 15;
    printf("d) Cupom: %d%% de desconto\n", *cupom);
}

void vagas(void) {
    int *livres = NULL;
    *livres = 3;
    printf("e) Vagas livres: %d\n", *livres);
}

int main(void) {
    notas();
    saldo();
    senha();
    cupom();
    vagas();
    return 0;
}
