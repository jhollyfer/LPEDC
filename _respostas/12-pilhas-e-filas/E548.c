// 0092 · Deque
// Exercício E548 · ★☆☆

#include <stdio.h>

int volta(int i, int passos, int cap) {
    // passos % cap fica entre 0 e cap - 1, então i - passos % cap > -cap,
    // e somar cap deixa tudo positivo antes do último %
    return (i - passos % cap + cap) % cap;
}

int main(void) {
    printf("-1 %% 8 = %d\n", -1 % 8);
    printf("-9 %% 8 = %d\n", -9 % 8);
    printf("volta(0, 1, 8) = %d\n", volta(0, 1, 8));
    printf("volta(3, 5, 8) = %d\n", volta(3, 5, 8));
    printf("volta(2, 18, 8) = %d\n", volta(2, 18, 8));
    return 0;
}
