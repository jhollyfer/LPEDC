// 0134 · Seleção de intervalos
// Exercício E802 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *feira;
    int abre, fecha; // horário fechado [abre, fecha]
} Feira;

int por_fechamento(const void *a, const void *b) {
    const Feira *x = a, *y = b;
    return (x->fecha > y->fecha) - (x->fecha < y->fecha);
}

int main(void) {
    Feira f[] = {
        {"Pinheiros", 7, 12},  {"Lapa", 6, 9},      {"Tatuapé", 10, 14},
        {"Mooca", 8, 11},      {"Liberdade", 13, 18}, {"Butantã", 15, 17},
        {"Santana", 16, 20},
    };
    int n = 7;

    qsort(f, n, sizeof f[0], por_fechamento);
    int visitas = 0;
    int ultima = -1; // hora da última visita marcada
    for (int i = 0; i < n; i++) {
        if (f[i].abre > ultima) {          // esta feira ainda não foi vista
            ultima = f[i].fecha;           // visita o mais tarde possível
            visitas++;
            printf("Visita às %dh:", ultima);
            for (int j = i; j < n; j++) {  // quem está aberta nessa hora
                if (f[j].abre <= ultima && ultima <= f[j].fecha) {
                    printf(" %s", f[j].feira);
                }
            }
            printf("\n");
        }
    }
    printf("Total: %d visitas\n", visitas);
    return 0;
}
