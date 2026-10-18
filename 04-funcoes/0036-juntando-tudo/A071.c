// A071 · Rachando a conta da mesa sem perder centavo

#include <stdio.h>

#include "cardapio.h"

#define TAXA_SERVICO 10 // por cento

void mostrar_reais(int centavos) {
    printf("R$ %d.%02d", centavos / 100, centavos % 100);
}

// lança um item e devolve o preço (0 se o código não existe)
int pedir(int codigo) {
    int preco = preco_centavos(codigo);
    if (preco == 0) {
        printf("código %d não existe\n", codigo);
        return 0;
    }
    mostrar_item(codigo);
    printf(": ");
    mostrar_reais(preco);
    printf("\n");
    return preco;
}

// quanto a pessoa número "pessoa" (1, 2, ...) paga:
// a divisão inteira deixa uma sobra, e as primeiras pagam 1 centavo a mais
int parte(int conta, int pessoas, int pessoa) {
    int base = conta / pessoas;
    int sobra = conta % pessoas;
    if (pessoa <= sobra) {
        return base + 1;
    }
    return base;
}

// recursiva: soma as partes da pessoa "de" até a última, para conferir
int soma_partes(int conta, int pessoas, int de) {
    if (de > pessoas) {
        return 0; // caso base: não sobrou ninguém
    }
    return parte(conta, pessoas, de) + soma_partes(conta, pessoas, de + 1);
}

int main(void) {
    int total = 0;
    total += pedir(1); // uma linha por pedido: assim a ordem na tela é garantida
    total += pedir(1);
    total += pedir(2);
    total += pedir(7);
    total += pedir(4);
    int conta = total + total * TAXA_SERVICO / 100;

    printf("%d itens, com serviço: ", itens_vendidos());
    mostrar_reais(conta);
    printf("\n");

    int pessoas = 3;
    for (int p = 1; p <= pessoas; p++) {
        printf("Pessoa %d paga ", p);
        mostrar_reais(parte(conta, pessoas, p));
        printf("\n");
    }
    printf("Conferindo: ");
    mostrar_reais(soma_partes(conta, pessoas, 1));
    printf("\n");
    return 0;
}
// Saída:
// X-salada: R$ 18.50
// X-salada: R$ 18.50
// Batata: R$ 12.00
// código 7 não existe
// Açaí: R$ 15.00
// 4 itens, com serviço: R$ 70.40
// Pessoa 1 paga R$ 23.47
// Pessoa 2 paga R$ 23.47
// Pessoa 3 paga R$ 23.46
// Conferindo: R$ 70.40
