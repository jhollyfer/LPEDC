// Lista · Módulo 03 · Laços
// Exercício P0324 · ★★★ · Os primos até 10 000

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int LIMITE = 10000;
    int contagem = 1; // o 2
    int anterior = 2;
    int maior_buraco = 0, buraco_de = 0, buraco_ate = 0;

    for (int n = 3; n <= LIMITE; n += 2) {
        bool primo = true;
        for (int d = 3; d * d <= n; d += 2) {
            if (n % d == 0) {
                primo = false;
                break;
            }
        }
        if (!primo) {
            continue;
        }
        contagem++;
        if (n - anterior > maior_buraco) {
            maior_buraco = n - anterior;
            buraco_de = anterior;
            buraco_ate = n;
        }
        anterior = n;
    }

    printf("Primos até %d: %d\n", LIMITE, contagem);
    printf("Maior primo: %d\n", anterior);
    printf("Maior buraco: %d, entre %d e %d\n", maior_buraco, buraco_de, buraco_ate);
    return 0;
}
