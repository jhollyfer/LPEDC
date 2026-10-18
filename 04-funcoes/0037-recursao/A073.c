// A073 · De quantos jeitos 5 amigos sentam no cinema

#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) {
        return 1; // caso base: resolve direto, sem chamar ninguém
    }
    return n * fatorial(n - 1); // caso recursivo: um problema menor
}

int main(void) {
    printf("5 amigos: %d jeitos\n", fatorial(5));
    printf("12 amigos: %d jeitos\n", fatorial(12)); // o maior que cabe num int
    return 0;
}
// Saída:
// 5 amigos: 120 jeitos
// 12 amigos: 479001600 jeitos
