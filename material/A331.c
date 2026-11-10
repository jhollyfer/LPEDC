// A331 · Melhor, pior e médio na busca sequencial

#include <stdio.h>

int comparacoes = 0;

// procura a placa no pátio, da vaga 0 em diante
int busca(const int placas[], int n, int placa) {
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (placas[i] == placa) {
            return i;
        }
    }
    return -1;
}

// melhor, pior e média de comparações procurando cada placa que está no pátio
void tres_casos(const int placas[], int n) {
    int menor = n + 1, maior = 0;
    long soma = 0;
    for (int alvo = 0; alvo < n; alvo++) {
        comparacoes = 0;
        busca(placas, n, placas[alvo]);
        if (comparacoes < menor) menor = comparacoes;
        if (comparacoes > maior) maior = comparacoes;
        soma += comparacoes;
    }
    comparacoes = 0;
    busca(placas, n, -1);               // placa que não está no pátio
    printf("n = %4d | melhor %d | pior %4d | média %7.1f | ausente %4d\n",
           n, menor, maior, (double)soma / n, comparacoes);
}

int main(void) {
    static int patio[1000];
    for (int i = 0; i < 1000; i++) {
        patio[i] = 1000 + 7 * i;        // placas fictícias, todas diferentes
    }
    tres_casos(patio, 10);
    tres_casos(patio, 100);
    tres_casos(patio, 1000);
    return 0;
}
// Saída:
// n =   10 | melhor 1 | pior   10 | média     5.5 | ausente   10
// n =  100 | melhor 1 | pior  100 | média    50.5 | ausente  100
// n = 1000 | melhor 1 | pior 1000 | média   500.5 | ausente 1000
