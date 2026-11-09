// Lista · Módulo 14 · Árvores
// Exercício P1429 · ★★★ · O maior caminho da rede de sensores
//
// Os sensores de uma plantação formam uma árvore binária, com a central no
// sensor 1. Uma mensagem entre dois sensores percorre o caminho da árvore, e
// a engenharia quer o maior caminho possível entre DOIS sensores quaisquer
// (o DIÂMETRO da árvore), em arestas, e o sensor onde esse caminho faz a
// curva (o nó mais alto dele).
//
//   1 tem filhos 2 e 3
//   2 tem filhos 4 e 5;      3 tem só o filho direito 7
//   4 tem filhos 8 e 9;      5 tem só o filho direito 10
//   8 tem só o esquerdo 12;  10 tem só o direito 13;  13 tem só o esquerdo 14
//
// Escreva int altura_e_diametro(const No *r, int *diametro, int *curva), que
// devolve a altura de r (vazia = -1) e, de passagem, testa o maior caminho
// que faz a curva em r: (he + 1) + (hd + 1) arestas. Uma única pós-ordem
// resolve tudo em O(n).
//
//   Saída esperada:
//   altura: 5
//   maior caminho: 7 arestas, fazendo a curva no sensor 2
//
// Dicas:
// 1. O caminho mais longo NÃO precisa passar pela raiz: aqui ele vai do 12
//    ao 14 e faz a curva no 2.
// 2. Com altura de vazia = -1, um lado vazio soma (-1 + 1) = 0 arestas.
// 3. Chamar altura() dentro de uma função de diâmetro recursiva daria O(n²);
//    devolver a altura e atualizar o diâmetro na mesma volta dá O(n).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    struct No *esq, *dir;
} No;

int main(void) {

    return 0;
}
