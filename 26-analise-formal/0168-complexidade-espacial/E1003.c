// 0168 · Complexidade espacial
// Exercício E1003 · ★☆☆
//
// A função potencia abaixo faz uma multiplicação por chamada. Meça quanto
// ela empilha: acrescente dois contadores globais, prof (frames vivos
// agora) e prof_max (o maior valor que prof já teve), e mostre a
// profundidade máxima para 3^10, 3^20 e 3^30:
//
//   Saída esperada:
//   3^10 = 59049, profundidade 11
//   3^20 = 3486784401, profundidade 21
//   3^30 = 205891132094649, profundidade 31
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

// base elevada a e, uma multiplicação por chamada
long potencia(long base, int e) {
    if (e == 0) {
        return 1;
    }
    return base * potencia(base, e - 1);
}

int main(void) {
    printf("3^10 = %ld\n", potencia(3, 10));
    return 0;
}
