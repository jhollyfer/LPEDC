// A101 · Os preços trocados

#include <stdio.h>

// recebe CÓPIAS: troca as cópias e o main nem fica sabendo
void troca_copias(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// recebe ENDEREÇOS: troca o que está nas gavetas do main
void troca(int *a, int *b) {
    int tmp = *a; // guarda o valor da primeira gaveta
    *a = *b;      // primeira gaveta recebe o da segunda
    *b = tmp;     // segunda gaveta recebe o guardado
}

int main(void) {
    int arroz = 8, feijao = 25; // digitados trocados: o arroz é o mais caro

    troca_copias(arroz, feijao);
    printf("Depois de troca_copias: arroz %d, feijão %d\n", arroz, feijao);

    if (arroz < feijao) {         // o pacote de arroz deveria custar mais
        troca(&arroz, &feijao);   // passa os endereços, não os valores
    }
    printf("Depois de troca:        arroz %d, feijão %d\n", arroz, feijao);
    return 0;
}
// Saída:
// Depois de troca_copias: arroz 8, feijão 25
// Depois de troca:        arroz 25, feijão 8
