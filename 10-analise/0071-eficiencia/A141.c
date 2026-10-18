// A141 · Contar tudo: a busca com sentinela

#include <stdio.h>

// Na catraca da academia, a busca compara duas coisas a cada volta: "acabou
// a lista?" (i < n) e "é esta matrícula?". Contando as DUAS, dá para ver o
// truque da sentinela: pôr a própria matrícula procurada no fim da lista
// garante que a busca sempre acha, e o teste i < n some do laço.

int comparacoes = 0; // conta toda comparação, de qualquer tipo

int busca_comum(const int v[], int n, int alvo) {
    int i = 0;
    while (1) {
        comparacoes++; // i < n
        if (!(i < n)) {
            return -1;
        }
        comparacoes++; // v[i] == alvo
        if (v[i] == alvo) {
            return i;
        }
        i++;
    }
}

// v precisa ter uma posição livre em v[n] para a sentinela.
int busca_sentinela(int v[], int n, int alvo) {
    v[n] = alvo; // a sentinela: a busca vai parar aqui, no pior caso
    int i = 0;
    while (1) {
        comparacoes++; // v[i] == alvo (o único teste do laço)
        if (v[i] == alvo) {
            break;
        }
        i++;
    }
    return i < n ? i : -1; // um teste só, fora do laço
}

int main(void) {
    int matriculas[9] = {3021, 1187, 4410, 2595, 3978, 1203, 4862, 2240}; // 8 + 1 livre
    int alvos[3] = {3021, 4862, 9999};

    printf("%8s %6s %7s %10s\n", "alvo", "pos", "comum", "sentinela");
    for (int k = 0; k < 3; k++) {
        comparacoes = 0;
        int pos = busca_comum(matriculas, 8, alvos[k]);
        int c1 = comparacoes;

        comparacoes = 0;
        busca_sentinela(matriculas, 8, alvos[k]);
        int c2 = comparacoes + 1; // + o teste i < n do return

        printf("%8d %6d %7d %10d\n", alvos[k], pos, c1, c2);
    }
    return 0;
}
// Saída:
//     alvo    pos   comum  sentinela
//     3021      0       2          2
//     4862      6      14          8
//     9999     -1      17         10
//
// Pior caso: 2n + 1 contra n + 2. As duas continuam crescendo junto com n,
// mas a sentinela corta quase metade das comparações.
