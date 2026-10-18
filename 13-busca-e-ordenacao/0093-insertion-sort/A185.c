// A185 · A triagem que respeita a ordem de chegada

#include <stdio.h>

typedef struct {
    char nome[10];
    int chegada;      // ordem em que entrou no pronto-socorro
    int prioridade;   // 1 = urgente, 2 = pouco urgente, 3 = não urgente
} Paciente;

// insertion sort por prioridade: só empurra quem é ESTRITAMENTE maior
void ordena_triagem(Paciente v[], int n) {
    for (int j = 1; j < n; j++) {
        Paciente x = v[j];              // a struct inteira é copiada
        int i = j - 1;
        while (i >= 0 && v[i].prioridade > x.prioridade) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;                   // para atrás de quem tem a mesma prioridade
    }
}

int main(void) {
    Paciente fila[] = {
        {"Rita", 1, 3}, {"Paulo", 2, 2}, {"Joana", 3, 1},
        {"Caio", 4, 3}, {"Lia", 5, 1}, {"Beto", 6, 2},
    };
    int n = 6;

    ordena_triagem(fila, n);
    for (int k = 0; k < n; k++) {
        printf("prioridade %d: %-6s (chegou em %dº)\n",
               fila[k].prioridade, fila[k].nome, fila[k].chegada);
    }
    return 0;
}
// Saída (empatados na prioridade continuam na ordem de chegada: é estável):
// prioridade 1: Joana  (chegou em 3º)
// prioridade 1: Lia    (chegou em 5º)
// prioridade 2: Paulo  (chegou em 2º)
// prioridade 2: Beto   (chegou em 6º)
// prioridade 3: Rita   (chegou em 1º)
// prioridade 3: Caio   (chegou em 4º)
