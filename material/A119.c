// A119 · A frota de ônibus

#include <stdio.h>
#include <string.h>

typedef char Placa[8];      // apelido para um vetor: Placa é "char[8]"
typedef unsigned Minutos;   // apelido para um tipo simples

typedef struct onibus Onibus; // apelido antes da struct existir

struct onibus {             // a struct com nome: dá para usar os dois nomes
    Placa placa;
    int linha;
    Minutos atraso;
};

void mostrar(Onibus o) {
    printf("Linha %d (%s): %u min de atraso\n", o.linha, o.placa, o.atraso);
}

int main(void) {
    Onibus a = {"QWE1R23", 512, 0};
    struct onibus b = {"RTY4U56", 307, 15}; // o nome completo também vale
    Minutos tolerancia = 10;

    mostrar(a);
    mostrar(b);
    if (b.atraso > tolerancia) {
        printf("Linha %d passou da tolerância de %u min\n", b.linha, tolerancia);
    }

    Placa nova;              // é um vetor de 8 char, como qualquer outro
    strcpy(nova, "ZXC7V89"); // vetor: strcpy, não =
    printf("Placa nova: %s, %zu bytes\n", nova, sizeof nova);
    printf("Onibus ocupa %zu bytes, igual a struct onibus: %zu\n",
           sizeof(Onibus), sizeof(struct onibus));
    return 0;
}
// Saída:
// Linha 512 (QWE1R23): 0 min de atraso
// Linha 307 (RTY4U56): 15 min de atraso
// Linha 307 passou da tolerância de 10 min
// Placa nova: ZXC7V89, 8 bytes
// Onibus ocupa 16 bytes, igual a struct onibus: 16
