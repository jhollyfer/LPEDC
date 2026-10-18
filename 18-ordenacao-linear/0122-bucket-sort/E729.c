// 0122 · Bucket sort
// Exercício E729 · ★★☆
//
// A agenda do celular agrupa os contatos pela letra inicial. Faça um bucket
// sort de strings com 26 baldes, um por letra: o balde de um nome é
// nome[0] - 'A', e cada balde é uma lista encadeada que guarda os nomes já
// em ordem alfabética (compare com strcmp). Mostre cada balde que não está
// vazio, devolva os nomes ao vetor em ordem e libere todos os nós.
//
//   Saída esperada:
//   A: Alberto Amanda Ana
//   B: Beatriz Bruno
//   C: Caio Carla
//   M: Marcos Mariana Marta Mauro
//   agenda: Alberto Amanda Ana Beatriz Bruno Caio Carla Marcos Mariana Marta Mauro
//
// Dicas:
// 1. O nó guarda só o ponteiro: typedef struct No { const char *nome;
//    struct No *prox; } No; as letras continuam onde estão.
// 2. É o insere_ordenado do texto com "x < lista->valor" trocado por
//    strcmp(nome, lista->nome) < 0 (e o mesmo no laço).
// 3. Na hora de juntar, copie p->nome para o vetor e dê free(p) antes de
//    passar para o próximo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *contatos[] = {"Marcos", "Ana", "Bruno", "Mariana", "Carla", "Alberto",
                              "Beatriz", "Marta", "Caio", "Amanda", "Mauro"};
    (void) contatos; // apague esta linha

    return 0;
}
