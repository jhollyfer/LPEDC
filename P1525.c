// Lista · Módulo 15 · Tabelas hash
// Exercício P1525 · ★★★ · Quem joga futebol e vôlei
//
// A escolinha tem duas listas de inscritos (com um nome repetido por
// engano):
//
//   futebol: Lia Rui Davi Bia Caio Rui Nina
//   vôlei:   Bia Theo Lia Gil Nina Ana
//
// Monte um CONJUNTO hash de nomes para cada esporte (encadeamento, 7 baldes,
// djb2 % 7, sem repetidos) com bool contem(t, nome) e adiciona(t, nome).
// Mostre, na ordem das listas e sem repetir ninguém: quem está nos dois,
// quem está só no futebol, quem está só no vôlei, e o total de pessoas
// diferentes (o tamanho da união). Libere os conjuntos no fim.
//
//   Saída esperada:
//   os dois: Lia Bia Nina
//   só futebol: Rui Davi Caio
//   só vôlei: Theo Gil Ana
//   nos dois: 3, total de pessoas: 9
//
// Dicas:
// 1. Para não listar o Rui duas vezes, use um terceiro conjunto "já
//    mostrados".
// 2. União = (pessoas do futebol) + (só vôlei). Conte o futebol percorrendo
//    o conjunto, que já não tem repetidos.
// 3. Cada consulta é O(1) em média: o total é O(n + m), contra O(n · m)
//    comparando todo mundo com todo mundo.
// 4. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 7

typedef struct No {
    char nome[12];
    struct No *prox;
} No;

int main(void) {
    const char *futebol[] = {"Lia", "Rui", "Davi", "Bia", "Caio", "Rui", "Nina"};
    const char *volei[] = {"Bia", "Theo", "Lia", "Gil", "Nina", "Ana"};
    (void)futebol;
    (void)volei;

    return 0;
}
