// A123 · As comandas do bar

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mesa;
    double total;
    int itens;
} Comanda;

// cria um vetor de comandas no heap e devolve o endereço (NULL se falhar)
Comanda *abrir_comandas(int n) {
    Comanda *v = malloc(n * sizeof *v);
    if (v == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        v[i] = (Comanda){i + 1, 0.0, 0}; // mesas 1, 2, 3...
    }
    return v;
}

void lancar(Comanda *c, double preco) {
    c->total += preco;
    c->itens++;
}

// devolve um ponteiro para a comanda mais cara: sem copiar nenhuma
const Comanda *mais_cara(const Comanda *v, int n) {
    const Comanda *m = &v[0];
    for (int i = 1; i < n; i++) {
        if (v[i].total > m->total) {
            m = &v[i];
        }
    }
    return m;
}

int main(void) {
    int n = 3;
    Comanda *bar = abrir_comandas(n);
    if (bar == NULL) {
        return 1;
    }

    lancar(&bar[0], 12.00); // chope na mesa 1
    lancar(&bar[2], 35.90); // porção na mesa 3
    lancar(&bar[0], 12.00);
    lancar(bar + 1, 8.50);  // bar + 1 é o mesmo que &bar[1]

    // o ponteiro anda de comanda em comanda: p++ pula sizeof(Comanda) bytes
    for (Comanda *p = bar; p < bar + n; p++) {
        printf("Mesa %d: %d itens, R$ %.2f\n", p->mesa, p->itens, p->total);
    }

    const Comanda *top = mais_cara(bar, n);
    printf("Maior conta: mesa %d\n", top->mesa);

    free(bar); // depois disso, top também fica solto: não use mais
    return 0;
}
// Saída:
// Mesa 1: 2 itens, R$ 24.00
// Mesa 2: 1 itens, R$ 8.50
// Mesa 3: 1 itens, R$ 35.90
// Maior conta: mesa 3
