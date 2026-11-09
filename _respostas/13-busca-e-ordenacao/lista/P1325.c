// Lista · Módulo 13 · Busca e ordenação
// Exercício P1325 · ★★★ · Duas passadas estáveis, uma chave composta

#include <stdio.h>
#include <string.h>

typedef struct {
    char bairro[12];
    int hora;
    int pedido;
} Entrega;

// insertion sort por hora (estável)
void por_hora(Entrega v[], int n) {
    for (int j = 1; j < n; j++) {
        Entrega x = v[j];
        int i = j - 1;
        while (i >= 0 && v[i].hora > x.hora) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}

// insertion sort por bairro (estável)
void por_bairro(Entrega v[], int n) {
    for (int j = 1; j < n; j++) {
        Entrega x = v[j];
        int i = j - 1;
        while (i >= 0 && strcmp(v[i].bairro, x.bairro) > 0) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}

void mostra(const char *titulo, const Entrega v[], int n) {
    printf("%s\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("  %-8s %02d:00 pedido %d\n", v[i].bairro, v[i].hora, v[i].pedido);
    }
}

int main(void) {
    Entrega lista[] = {
        {"Centro", 15, 101}, {"Aleixo", 11, 102}, {"Centro", 9, 103}, {"Flores", 14, 104},
        {"Aleixo", 8, 105}, {"Centro", 12, 106}, {"Flores", 10, 107},
    };
    int n = 7;
    Entrega a[7], b[7];
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = lista[i];
    }

    por_hora(a, n);   // primeiro a chave secundária
    por_bairro(a, n); // depois a principal, com algoritmo estável
    mostra("hora, depois bairro (certo):", a, n);

    por_bairro(b, n);
    por_hora(b, n);
    mostra("bairro, depois hora (errado):", b, n);
    return 0;
}
