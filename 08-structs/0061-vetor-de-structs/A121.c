// A121 · O estoque da farmácia

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int estoque;
    int minimo; // abaixo disso, precisa repor
} Remedio;

// devolve o índice do remédio com esse nome, ou -1 se não achar
int buscar(const Remedio v[], int n, const char *nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void vender(Remedio v[], int n, const char *nome, int qtd) {
    int i = buscar(v, n, nome);
    if (i == -1) {
        printf("%s: não temos\n", nome);
    } else if (v[i].estoque < qtd) {
        printf("%s: só restam %d\n", nome, v[i].estoque);
    } else {
        v[i].estoque -= qtd; // mexe direto no elemento do vetor
        printf("%s: vendidas %d, restam %d\n", nome, qtd, v[i].estoque);
    }
}

int main(void) {
    Remedio farmacia[] = {
        {"Dipirona", 40, 10},
        {"Paracetamol", 12, 10},
        {"Ibuprofeno", 5, 8},
    };
    int n = sizeof farmacia / sizeof farmacia[0];

    vender(farmacia, n, "Paracetamol", 3);
    vender(farmacia, n, "Ibuprofeno", 6);
    vender(farmacia, n, "Amoxicilina", 1);
    vender(farmacia, n, "Dipirona", 30);

    printf("Repor:\n");
    for (int i = 0; i < n; i++) {
        if (farmacia[i].estoque < farmacia[i].minimo) { // 10 de 10 ainda não
            printf("  %s (%d de %d)\n", farmacia[i].nome, farmacia[i].estoque,
                   farmacia[i].minimo);
        }
    }
    return 0;
}
// Saída:
// Paracetamol: vendidas 3, restam 9
// Ibuprofeno: só restam 5
// Amoxicilina: não temos
// Dipirona: vendidas 30, restam 10
// Repor:
//   Paracetamol (9 de 10)
//   Ibuprofeno (5 de 8)
