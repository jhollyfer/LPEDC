// Lista · Módulo 12 · Pilhas e filas
// Exercício P1230 · ★★★ · O expediente da lotérica com arquivo de log

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int senha;
    char tipo; // 'A' aposta, 'B' boleto, 'S' saque
    int minutos;
} Atendimento;

typedef struct {
    Atendimento v[CAP];
    int inicio, n;
} Fila;

bool insere(Fila *f, Atendimento a) {
    if (f->n == CAP) {
        return false;
    }
    f->v[(f->inicio + f->n) % CAP] = a;
    f->n++;
    return true;
}

bool retira(Fila *f, Atendimento *a) {
    if (f->n == 0) {
        return false;
    }
    *a = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

int main(void) {
    const char *caminho = "/tmp/p1230_log.txt";
    Atendimento chegada[6] = {{1, 'B', 3}, {2, 'A', 1}, {3, 'B', 4}, {4, 'A', 2}, {5, 'S', 5}, {6, 'A', 1}};
    Fila fila = {.inicio = 0, .n = 0};
    for (int i = 0; i < 6; i++) {
        insere(&fila, chegada[i]);
    }

    FILE *log = fopen(caminho, "w");
    if (log == NULL) {
        perror(caminho);
        return 1;
    }
    int relogio = 0, linhas = 0;
    Atendimento a;
    while (retira(&fila, &a)) {
        fprintf(log, "%d %c %d %d\n", a.senha, a.tipo, relogio, relogio + a.minutos);
        relogio += a.minutos;
        linhas++;
    }
    fclose(log);
    printf("Log gravado: %d linhas\n", linhas);

    log = fopen(caminho, "r");
    if (log == NULL) {
        perror(caminho);
        return 1;
    }
    int qtd[3] = {0, 0, 0}, min[3] = {0, 0, 0}; // A, B, S
    int senha, ini, fim, n = 0, soma_espera = 0, ultimo_fim = 0;
    char tipo;
    while (fscanf(log, "%d %c %d %d", &senha, &tipo, &ini, &fim) == 4) {
        int k = tipo == 'A' ? 0 : tipo == 'B' ? 1 : 2;
        qtd[k]++;
        min[k] += fim - ini;
        soma_espera += ini;
        n++;
        if (fim > ultimo_fim) {
            ultimo_fim = fim;
        }
    }
    fclose(log);
    remove(caminho);

    printf("Apostas: %d (%d min)\n", qtd[0], min[0]);
    printf("Boletos: %d (%d min)\n", qtd[1], min[1]);
    printf("Saques: %d (%d min)\n", qtd[2], min[2]);
    if (n > 0) {
        printf("Espera média: %.2f min\n", (double) soma_espera / n);
    }
    printf("Fim do atendimento: minuto %d\n", ultimo_fim);
    return 0;
}
