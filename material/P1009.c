// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1009 · ★☆☆ · O TAD da rifa da escola
//
// A rifa tem números de 0 a 63. A interface "conjunto.h" já está escrita, e
// o cliente também. Falta a implementação: escreva o "conjunto.c" com uma
// struct que guarda um vetor bool de 64 posições e um contador, de modo que
// pertence, insere e remove custem O(1) e tamanho também (sem contar o
// vetor a cada chamada). Número fora de 0..63 é recusado (insere devolve
// false). Inserir de novo um número que já está não muda nada.
//
//   Saída esperada:
//   Vendidos: 3
//   42 vendido? sim
//   13 vendido? não
//   64 aceito? não
//
// Dicas:
// 1. struct conjunto { bool tem[64]; int n; };
// 2. Em insere, só some 1 em n se o número ainda não estava. Em remove, só
//    subtraia se estava. Assim o invariante "n é o número de posições true"
//    vale depois de toda operação.
// 3. Resposta esperada: a saída acima (vendidos 7, 42 e 63; o 13 saiu).
//
// Escreva sua resposta abaixo (complete o conjunto.c):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ---- conjunto.h -----------------------------------------------------------
typedef struct conjunto Conjunto;

Conjunto *conj_cria(void);                   // NULL se faltar memória
bool conj_insere(Conjunto *c, int x);        // false se x fora de 0..63
void conj_remove(Conjunto *c, int x);
bool conj_pertence(const Conjunto *c, int x);
int conj_tamanho(const Conjunto *c);
void conj_libera(Conjunto *c);

// ---- conjunto.c -----------------------------------------------------------
// escreva aqui a struct conjunto e troque o corpo das seis funções
// (as linhas com (void) só existem para o esqueleto compilar sem aviso)

Conjunto *conj_cria(void) {
    return NULL;
}

bool conj_insere(Conjunto *c, int x) {
    (void) c;
    (void) x;
    return false;
}

void conj_remove(Conjunto *c, int x) {
    (void) c;
    (void) x;
}

bool conj_pertence(const Conjunto *c, int x) {
    (void) c;
    (void) x;
    return false;
}

int conj_tamanho(const Conjunto *c) {
    (void) c;
    return 0;
}

void conj_libera(Conjunto *c) {
    (void) c;
}

// ---- cliente --------------------------------------------------------------
int main(void) {
    Conjunto *rifa = conj_cria();
    if (rifa == NULL) {
        printf("Sem memória (ou conj_cria ainda não foi escrita)\n");
        return 1;
    }
    conj_insere(rifa, 7);
    conj_insere(rifa, 13);
    conj_insere(rifa, 42);
    conj_insere(rifa, 7); // repetido
    conj_insere(rifa, 63);
    bool aceito = conj_insere(rifa, 64);
    conj_remove(rifa, 13);

    printf("Vendidos: %d\n", conj_tamanho(rifa));
    printf("42 vendido? %s\n", conj_pertence(rifa, 42) ? "sim" : "não");
    printf("13 vendido? %s\n", conj_pertence(rifa, 13) ? "sim" : "não");
    printf("64 aceito? %s\n", aceito ? "sim" : "não");
    conj_libera(rifa);
    return 0;
}
