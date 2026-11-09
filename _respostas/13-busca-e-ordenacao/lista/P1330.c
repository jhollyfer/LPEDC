// Lista · Módulo 13 · Busca e ordenação
// Exercício P1330 · ★★★ · A agenda do posto de saúde

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;   // aaaammdd
    int hora;   // hhmm
    char paciente[12];
} Consulta;

// chave composta: data, depois hora
int compara(const void *a, const void *b) {
    const Consulta *x = a, *y = b;
    if (x->data != y->data) {
        return (x->data > y->data) - (x->data < y->data);
    }
    return (x->hora > y->hora) - (x->hora < y->hora);
}

// primeira consulta com (data, hora) >= (data, 0); devolve de 0 a n
int primeira_do_dia(const Consulta v[], int n, int data) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio].data < data) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return ini;
}

void lista_dia(const Consulta v[], int n, int data) {
    int i = primeira_do_dia(v, n, data);
    printf("%02d/%02d:", data % 100, data / 100 % 100);
    if (i == n || v[i].data != data) {
        printf(" nenhuma consulta\n");
        return;
    }
    for (; i < n && v[i].data == data; i++) {
        printf(" %02d:%02d %s;", v[i].hora / 100, v[i].hora % 100, v[i].paciente);
    }
    printf("\n");
}

int main(void) {
    Consulta agenda[] = {
        {20261112, 1030, "Marta"}, {20261110, 900, "Joao"}, {20261112, 800, "Ivo"},
        {20261111, 1400, "Sara"}, {20261110, 1500, "Lia"}, {20261112, 1330, "Davi"},
        {20261110, 730, "Rosa"}, {20261114, 1000, "Tito"},
    };
    int n = 8;

    qsort(agenda, n, sizeof agenda[0], compara);
    lista_dia(agenda, n, 20261110);
    lista_dia(agenda, n, 20261112);
    lista_dia(agenda, n, 20261113);
    lista_dia(agenda, n, 20261114);
    return 0;
}
