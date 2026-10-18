// A186 · Palíndromo com uma fila e uma pilha

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

// A fila devolve as letras na ordem em que entraram; a pilha, ao contrário.
// Se as duas sequências forem iguais, a frase é um palíndromo.
bool palindromo(const char *frase) {
    Fila *f = fila_cria();
    Pilha *p = pilha_cria();
    bool ok = f != NULL && p != NULL;
    for (int i = 0; ok && frase[i] != '\0'; i++) {
        unsigned char c = (unsigned char)frase[i];
        if (isalpha(c)) { // ignora espaços e pontuação
            int letra = toupper(c);
            fila_insere(f, letra);
            pilha_empilha(p, letra);
        }
    }
    int da_fila, da_pilha;
    while (ok && fila_retira(f, &da_fila) && pilha_desempilha(p, &da_pilha)) {
        if (da_fila != da_pilha) {
            ok = false;
        }
    }
    if (f != NULL) {
        fila_libera(f);
    }
    if (p != NULL) {
        pilha_libera(p);
    }
    return ok;
}

int main(void) {
    // sem acentos de propósito: em UTF-8, "ô" ocupa 2 bytes e isalpha não o
    // reconhece como letra
    const char *frases[] = {"Socorram-me, subi no onibus em Marrocos", "A base do teto desaba", "Pilha e fila"};
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", frases[i], palindromo(frases[i]) ? "sim" : "não");
    }
    return 0;
}
// Saída:
// Socorram-me, subi no onibus em Marrocos: sim
// A base do teto desaba: sim
// Pilha e fila: não
