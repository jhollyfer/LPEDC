// A075 · Um vetor entra, outro sai cheio

#include <stdio.h>

// lê as notas (const) e escreve o resultado em aprovado[], que é do main
void corrigir(const double notas[], int aprovado[], int n, double minima) {
    for (int i = 0; i < n; i++) {
        aprovado[i] = notas[i] >= minima; // 1 ou 0
    }
}

int contar(const int v[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += v[i];
    }
    return total;
}

int main(void) {
    // duas turmas de tamanhos diferentes: a função é a mesma
    double manha[5] = {7.5, 4.0, 6.0, 9.5, 5.9};
    double noite[3] = {8.0, 6.5, 3.0};
    int ok_manha[5]; // a função preenche: não precisa inicializar
    int ok_noite[3];

    corrigir(manha, ok_manha, 5, 6.0);
    corrigir(noite, ok_noite, 3, 6.0);

    printf("Manhã: %d de 5 aprovados\n", contar(ok_manha, 5));
    printf("Noite: %d de 3 aprovados\n", contar(ok_noite, 3));

    // a função só olha as n primeiras gavetas que você mandar
    printf("Só os 2 primeiros da manhã: %d\n", contar(ok_manha, 2));
    return 0;
}
// Saída:
// Manhã: 3 de 5 aprovados
// Noite: 2 de 3 aprovados
// Só os 2 primeiros da manhã: 1
