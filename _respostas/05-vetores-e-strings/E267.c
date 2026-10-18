// 0045 · Caracteres
// Exercício E267 · ★★☆

#include <stdio.h>
#include <ctype.h>

#define K 3

int main(void) {
    char msg[] = {'Z', 'E', 'B', 'R', 'A', ' ', 'A', 'Z', 'U', 'L'};
    int n = sizeof(msg);

    for (int i = 0; i < n; i++) {
        if (isupper(msg[i])) {
            msg[i] = (char) ('A' + (msg[i] - 'A' + K) % 26);
        }
    }
    printf("Cifrada: ");
    for (int i = 0; i < n; i++) {
        putchar(msg[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (isupper(msg[i])) {
            msg[i] = (char) ('A' + (msg[i] - 'A' + 26 - K) % 26);
        }
    }
    printf("Decifrada: ");
    for (int i = 0; i < n; i++) {
        putchar(msg[i]);
    }
    printf("\n");
    return 0;
}
