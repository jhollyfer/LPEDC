// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2217 · ★★☆ · O cardápio entre parênteses
//
// O cardápio do restaurante está numa árvore geral (filho-esquerdo/irmão-
// direito). Para mandar o cardápio por mensagem, o dono quer a árvore numa
// linha só, no formato raiz(filho1 filho2 ...), em que cada filho que tem
// filhos sai do mesmo jeito. Complete escreve(r).
//
//   Cardápio
//   ├── Entradas
//   │   ├── Caldo
//   │   └── Bolinho
//   ├── Pratos
//   │   ├── Peixe
//   │   │   ├── Tambaqui
//   │   │   └── Pirarucu
//   │   └── Frango
//   └── Bebidas
//
//   Saída esperada:
//   Cardápio(Entradas(Caldo Bolinho) Pratos(Peixe(Tambaqui Pirarucu) Frango) Bebidas)
//
// Dicas:
// 1. Mostre o nome; se r->filho != NULL, abra "(", escreva os filhos (o
//    primeiro, depois cada irmão, com um espaço entre eles) e feche ")".
// 2. Os irmãos são escritos por quem chamou (o laço do pai), não pela
//    própria recursão do filho: escreve(r) só cuida de r e da subárvore
//    dele.
// 3. Resposta esperada: a linha de cima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    const char *nome;
    struct No *filho, *irmao;
} No;

No *novo(const char *nome) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    n->nome = nome;
    n->filho = n->irmao = NULL;
    return n;
}

void filho(No *p, No *f) {
    No **x = &p->filho;
    while (*x != NULL) {
        x = &(*x)->irmao;
    }
    *x = f;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->filho);
        libera(r->irmao);
        free(r);
    }
}

void escreve(const No *r) {
    (void)r;
    // COMPLETE AQUI
}

int main(void) {
    No *card = novo("Cardápio"), *ent = novo("Entradas"), *pra = novo("Pratos"), *pei = novo("Peixe");
    filho(card, ent);
    filho(card, pra);
    filho(card, novo("Bebidas"));
    filho(ent, novo("Caldo"));
    filho(ent, novo("Bolinho"));
    filho(pra, pei);
    filho(pra, novo("Frango"));
    filho(pei, novo("Tambaqui"));
    filho(pei, novo("Pirarucu"));
    escreve(card);
    printf("\n");
    libera(card);
    return 0;
}
