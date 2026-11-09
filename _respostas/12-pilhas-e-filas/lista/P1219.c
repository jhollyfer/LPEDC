// Lista · Módulo 12 · Pilhas e filas
// Exercício P1219 · ★★☆ · O Ctrl+Z do bloco de notas

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo;      // 'D' digitou, 'A' apagou
    char texto[32];
} Operacao;

typedef struct {
    char texto[100];
    Operacao pilha[20];
    int n; // operações na pilha
} Editor;

static void empilha(Editor *e, char tipo, const char *s) {
    if (e->n == 20) {
        return; // histórico cheio: a operação não poderá ser desfeita
    }
    e->pilha[e->n].tipo = tipo;
    strcpy(e->pilha[e->n].texto, s);
    e->n++;
}

void digita(Editor *e, const char *s) {
    if (strlen(e->texto) + strlen(s) >= sizeof e->texto || strlen(s) >= 32) {
        return;
    }
    strcat(e->texto, s);
    empilha(e, 'D', s);
}

void apaga(Editor *e, int k) {
    int n = (int) strlen(e->texto);
    if (k > n) {
        k = n;
    }
    if (k >= 32) {
        return;
    }
    empilha(e, 'A', &e->texto[n - k]); // guarda o que vai sumir
    e->texto[n - k] = '\0';
}

bool desfaz(Editor *e) {
    if (e->n == 0) {
        return false;
    }
    Operacao op = e->pilha[--e->n];
    if (op.tipo == 'D') {
        e->texto[strlen(e->texto) - strlen(op.texto)] = '\0';
    } else {
        strcat(e->texto, op.texto);
    }
    return true;
}

void mostra(const char *rotulo, const Editor *e) {
    printf("%s [%s]\n", rotulo, e->texto);
}

int main(void) {
    Editor e = {.texto = "", .n = 0};
    digita(&e, "Bom");
    mostra("digita:", &e);
    digita(&e, " dia");
    mostra("digita:", &e);
    apaga(&e, 3);
    mostra("apaga: ", &e);
    digita(&e, "tarde");
    mostra("digita:", &e);
    for (int i = 0; i < 5; i++) {
        if (desfaz(&e)) {
            mostra("desfaz:", &e);
        } else {
            printf("desfaz: nada para desfazer\n");
        }
    }
    return 0;
}
