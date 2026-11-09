// Lista · Módulo 14 · Árvores
// Exercício P1401 · ★☆☆ · O organograma, nível por nível
//
// O organograma de uma pequena empresa é uma árvore binária: a Diretora tem
// Vendas à esquerda e TI à direita; Vendas tem Loja e Online; Online tem só
// Site, à direita; TI tem só Suporte, à esquerda.
//
// Monte a árvore com uma função No *novo(nome, esq, dir) e escreva:
//
//   int altura(const No *r)          altura em ARESTAS (vazia = -1)
//   void mostra(const No *r, int prof)   pré-ordem com 2 espaços por nível
//
// mostra imprime cada nó com a profundidade (recebida no parâmetro) e a
// altura dele. No fim, mostre a altura da árvore e libere tudo.
//
//   Saída esperada:
//   Diretora (profundidade 0, altura 3)
//     Vendas (profundidade 1, altura 2)
//       Loja (profundidade 2, altura 0)
//       Online (profundidade 2, altura 1)
//         Site (profundidade 3, altura 0)
//     TI (profundidade 1, altura 1)
//       Suporte (profundidade 2, altura 0)
//   altura da árvore: 3
//
// Dicas:
// 1. Profundidade se calcula DESCENDO (o pai passa prof + 1 para os filhos);
//    altura se calcula SUBINDO (1 + a maior altura dos filhos).
// 2. printf("%*s", 2 * prof, "") imprime 2 * prof espaços.
// 3. A altura da árvore é a altura da raiz, que é a maior profundidade (o
//    Site, a 3 arestas da Diretora).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char nome[10];
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
