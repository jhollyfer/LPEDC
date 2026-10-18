// A086 · Um elemento vai por valor, o vetor vai pelo endereço

#include <stdio.h>

#define N 5

// devolve a posição do código no vetor, ou -1 se não achar
int buscar(const int codigos[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (codigos[i] == alvo) {
            return i;
        }
    }
    return -1;
}

// recebe UMA quantidade: é uma cópia, como qualquer int
void baixa_na_copia(int quantidade) {
    quantidade = quantidade - 1;
}

// recebe o vetor: mexe nas gavetas de quem chamou
void baixa_no_vetor(int estoque[], int pos) {
    estoque[pos] = estoque[pos] - 1;
}

int main(void) {
    int codigos[N] = {101, 205, 310, 422, 587};
    int estoque[N] = {8, 3, 12, 0, 5};

    int pos = buscar(codigos, N, 310);
    printf("Código 310 na posição %d, estoque %d\n", pos, estoque[pos]);

    baixa_na_copia(estoque[pos]); // vai o valor 12
    printf("Depois de baixa_na_copia: %d\n", estoque[pos]);

    baixa_no_vetor(estoque, pos); // vai o vetor
    printf("Depois de baixa_no_vetor: %d\n", estoque[pos]);

    printf("Código 999: posição %d\n", buscar(codigos, N, 999));
    return 0;
}
// Saída:
// Código 310 na posição 2, estoque 12
// Depois de baixa_na_copia: 12
// Depois de baixa_no_vetor: 11
// Código 999: posição -1
