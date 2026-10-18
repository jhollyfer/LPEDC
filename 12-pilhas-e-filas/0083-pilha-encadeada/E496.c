// 0083 · Pilha encadeada
// Exercício E496 · ★★☆
//
// Pilha de pratos do restaurante, cada prato com um número. Este programa
// compila (o gcc 13 até solta um aviso: leia com atenção) e, sem o
// sanitizer, às vezes mostra os números certos. Mesmo assim está errado.
// Rode com o rodar, ache no relatório do AddressSanitizer o nome do erro e
// a linha, conserte mudando a ordem de duas linhas e rode de novo: a saída
// tem que bater e o relatório tem que sumir.
//
//   Saída esperada depois do conserto:
//   Tirou o prato 30
//   Tirou o prato 20
//   Tirou o prato 10
//
// Dicas:
// 1. Procure "heap-use-after-free" e o número da linha no relatório.
// 2. Depois do free, o nó não é mais seu, mesmo que os bytes ainda estejam
//    lá: o free só marca a memória como livre, e é por sorte que sem o
//    sanitizer a leitura parece funcionar.
// 3. Resposta esperada: o erro é heap-use-after-free, na linha que faz
//    "*numero = velho->numero", depois do free(velho). Conserto: passe a
//    linha do *numero para antes do free. Saída: as três linhas acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct prato {
    int numero;
    struct prato *baixo;
} Prato;

bool poe_prato(Prato **topo, int numero) {
    Prato *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return false;
    }
    novo->numero = numero;
    novo->baixo = *topo;
    *topo = novo;
    return true;
}

bool tira_prato(Prato **topo, int *numero) {
    if (*topo == NULL) {
        return false;
    }
    Prato *velho = *topo;
    *topo = velho->baixo;
    free(velho);
    *numero = velho->numero;
    return true;
}

int main(void) {
    Prato *topo = NULL;
    for (int n = 10; n <= 30; n += 10) {
        poe_prato(&topo, n);
    }
    int numero;
    while (tira_prato(&topo, &numero)) {
        printf("Tirou o prato %d\n", numero);
    }
    return 0;
}
