// 0088 · Pilha encadeada
// Exercício E526 · ★★☆
//
// Pilha de pratos do restaurante, cada prato com um número. Este programa
// compila (o gcc 13 até solta um aviso: leia com atenção) e, sem o
// sanitizer, às vezes mostra os números certos. Mesmo assim está errado:
// rode com o rodar e leia o relatório do AddressSanitizer. Responda:
//
// a) Qual é o nome do erro no relatório e em que linha ele acontece?
// b) Por que o programa às vezes "funciona" sem o sanitizer?
// c) Como consertar mudando a ordem de duas linhas?
//
//   Saída esperada depois do conserto:
//   Tirou o prato 30
//   Tirou o prato 20
//   Tirou o prato 10
//
// Dicas:
// 1. Procure "heap-use-after-free" e o número da linha no relatório.
// 2. Depois do free, o nó não é mais seu, mesmo que os bytes ainda estejam
//    lá.
// 3. Resposta esperada: a) heap-use-after-free, na linha que faz
//    "*numero = velho->numero", depois do free(velho); b) o free só marca
//    a memória como livre: até alguém reaproveitá-la, os bytes antigos
//    continuam lá, então ler parece funcionar por sorte; c) ler o valor
//    antes do free (passe a linha do *numero para antes do free).
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
