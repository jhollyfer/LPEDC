// 0053 · Ponteiros e strings
// Exercício E317 · ★★★

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindromo(const char *s) {
    size_t n = strlen(s);
    if (n == 0) {
        return true;
    }
    const char *ini = s;
    const char *fim = s + n - 1;
    while (ini < fim) {
        if (*ini == ' ') {
            ini++;
            continue;
        }
        if (*fim == ' ') {
            fim--;
            continue;
        }
        if (*ini != *fim) {
            return false;
        }
        ini++;
        fim--;
    }
    return true;
}

int main(void) {
    const char *frases[3] = {"arara", "socorram me subi no onibus em marrocos", "pix caiu"};

    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", frases[i], palindromo(frases[i]) ? "sim" : "não");
    }
    return 0;
}
