// 0187 · Reduções
// Exercício E1119 · ★★☆
//
// O shopping vai abrir um corredor temático e quer o MAIOR grupo de lojas
// sem concorrência entre si (um conjunto independente). Resolva por
// redução a clique: escreva int maior_clique(int g[V][V]), que testa as
// máscaras de bits de 1 a 2^V - 1 e devolve a da maior clique (no empate,
// a primeira máscara), monte o complemento de concorre em g2, chame
// maior_clique e mostre as lojas escolhidas e quantas são.
//
// Lojas: Açaí, Bazar, Café, Doces, Ervas, Farmácia, Gelato (0 a 6).
// Concorrem: Açaí-Café, Açaí-Doces, Açaí-Gelato, Bazar-Ervas, Café-Gelato,
// Doces-Gelato, Ervas-Farmácia, Farmácia-Gelato.
//
//   Saída esperada:
//   Lojas no corredor: Bazar Café Doces Farmácia (4)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 7

const char *lojas[V] = {"Açaí", "Bazar", "Café", "Doces", "Ervas", "Farmácia", "Gelato"};
int concorre[V][V]; // 1 = as duas vendem algo em comum
int g2[V][V];

int main(void) {

    return 0;
}
