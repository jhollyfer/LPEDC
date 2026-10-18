// A184 · Palíndromo com deque: compara as duas pontas

#include <stdbool.h>
#include <stdio.h>
#include "deque.h"

bool palindromo(const char *palavra) {
    Deque *d = deque_cria();
    if (d == NULL) {
        return false;
    }
    for (int i = 0; palavra[i] != '\0'; i++) {
        deque_insere_fim(d, palavra[i]); // até 8 letras: a capacidade do deque.c
    }
    bool ok = true;
    // tira uma letra de cada ponta enquanto sobrarem pelo menos duas
    while (deque_tamanho(d) > 1 && ok) {
        int frente, tras;
        deque_retira_inicio(d, &frente);
        deque_retira_fim(d, &tras);
        if (frente != tras) {
            ok = false;
        }
    }
    deque_libera(d);
    return ok;
}

int main(void) {
    const char *palavras[] = {"RADAR", "REVIVER", "PRATO", "OSSO"};
    for (int i = 0; i < 4; i++) {
        printf("%-8s %s\n", palavras[i], palindromo(palavras[i]) ? "é palíndromo" : "não é");
    }
    return 0;
}
// Saída:
// RADAR    é palíndromo
// REVIVER  é palíndromo
// PRATO    não é
// OSSO     é palíndromo
