// 0057 · Erros de memória
// Exercício E338 · ★☆☆
//
// a) heap-buffer-overflow: i <= 4 escrevia v[4], logo depois do bloco de
//    16 bytes (4 ints). Agora i < 4.
// b) heap-use-after-free: o printf lia *conta depois do free. Agora o free
//    vem depois.
// c) attempting double-free: o mesmo bloco era liberado duas vezes. Um
//    bloco, um free.
// d) LeakSanitizer: o bloco do cupom nunca era liberado. Agora tem free.
// e) SEGV em 0x0: escrevia pelo ponteiro NULL. Agora ele recebe um bloco,
//    o NULL é conferido e o bloco é liberado.

#include <stdio.h>
#include <stdlib.h>

void notas(void) {
    int *v = malloc(4 * sizeof *v);
    if (v == NULL) {
        return;
    }
    printf("a) Notas:");
    for (int i = 0; i < 4; i++) { // índices 0 a 3
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
    printf("b) Saldo: R$ %d\n", *conta); // usa antes...
    free(conta);                          // ...e libera depois
}

void senha(void) {
    int *s = malloc(sizeof *s);
    if (s == NULL) {
        return;
    }
    *s = 42;
    printf("c) Senha %d atendida\n", *s);
    free(s); // um free só
}

void cupom(void) {
    int *cupom = malloc(sizeof *cupom);
    if (cupom == NULL) {
        return;
    }
    *cupom = 15;
    printf("d) Cupom: %d%% de desconto\n", *cupom);
    free(cupom); // o que faltava
}

void vagas(void) {
    int *livres = malloc(sizeof *livres); // um bloco de verdade
    if (livres == NULL) {
        return;
    }
    *livres = 3;
    printf("e) Vagas livres: %d\n", *livres);
    free(livres);
}

int main(void) {
    notas();
    saldo();
    senha();
    cupom();
    vagas();
    return 0;
}
// Saída:
// a) Notas: 7 8 9 10
// b) Saldo: R$ 150
// c) Senha 42 atendida
// d) Cupom: 15% de desconto
// e) Vagas livres: 3
