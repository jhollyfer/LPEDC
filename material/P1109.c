// Lista · Módulo 11 · Listas
// Exercício P1109 · ★☆☆ · A chamada em ordem alfabética
//
// Os alunos vão chegando e entrando na lista de chamada, que precisa ficar
// sempre em ordem alfabética. Escreva
//
//   Aluno *insere_ordenado(Aluno *inicio, const char *nome)
//
// que cria o nó e o encaixa no lugar certo (comparando com strcmp),
// devolvendo o novo início. Insira Marcos, Ana, Teo, Bia e Lia, nesta ordem,
// mostrando a lista depois de cada inserção. Libere tudo no fim.
//
//   Saída esperada:
//   Marcos
//   Ana Marcos
//   Ana Marcos Teo
//   Ana Bia Marcos Teo
//   Ana Bia Lia Marcos Teo
//
// Dicas:
// 1. Caso especial: lista vazia, ou o novo vem antes do primeiro
//    (strcmp(nome, inicio->nome) < 0). Aí o novo vira o início.
// 2. Senão, ande com p enquanto p->prox != NULL e strcmp(p->prox->nome,
//    nome) < 0. O novo entra entre p e p->prox.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[20];
    struct aluno *prox;
} Aluno;

int main(void) {

    return 0;
}
