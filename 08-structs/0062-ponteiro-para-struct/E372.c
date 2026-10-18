// 0062 · Ponteiro para struct
// Exercício E372 · ★★★
//
// Uma struct pode ter um ponteiro para outra struct do mesmo tipo (é a base
// das listas encadeadas do módulo 11). Para isso, ela precisa de nome:
// dentro dela, o apelido do typedef ainda não existe. Três amigos formam uma
// roda: Ana aponta para Caio, Caio para Bia e Bia para Ana.
//
// Complete o programa com três funções que andam SÓ pelas setas (p->amigo),
// sem usar o vetor g:
//
//   - void seguir(const Pessoa *p, int passos): mostra o nome de p e dos
//     próximos "passos" amigos;
//   - int tamanho_da_roda(const Pessoa *inicio): conta quantas pessoas há
//     até voltar para quem começou;
//   - const Pessoa *mais_velha(const Pessoa *inicio): devolve um ponteiro
//     para a pessoa de maior idade da roda.
//
// Chame seguir(&g[0], 4), tamanho_da_roda(&g[0]) e mais_velha(&g[1]) (a
// busca começa na Bia de propósito), e mostre também o sizeof(Pessoa).
//
//   Saída esperada (num PC de 64 bits):
//   Ana -> Caio -> Bia -> Ana -> Caio
//   Roda da Ana: 3 pessoas
//   Maior idade: Caio (41)
//   sizeof(Pessoa) = 24
//
// Dicas:
// 1. Para andar: p = p->amigo; repetido. A roda não tem fim: quem decide
//    quando parar é você.
// 2. Para contar, comece em inicio->amigo e pare quando p == inicio.
// 3. O tamanho: nome (10), 2 de sobra, idade (4), amigo (8, um ponteiro).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

typedef struct Pessoa {
    char nome[10];
    int idade;
    struct Pessoa *amigo;
} Pessoa;

// escreva seguir, tamanho_da_roda e mais_velha aqui

int main(void) {
    Pessoa g[3] = {{"Ana", 30, NULL}, {"Bia", 25, NULL}, {"Caio", 41, NULL}};
    g[0].amigo = &g[2];
    g[1].amigo = &g[0];
    g[2].amigo = &g[1];

    // chame as funções aqui

    return 0;
}
