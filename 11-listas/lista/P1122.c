// Lista · Módulo 11 · Listas
// Exercício P1122 · ★★★ · O malloc de brinquedo (first-fit)
//
// Por baixo do malloc existe uma LISTA DE BLOCOS LIVRES. Simule uma memória
// de 100 posições (endereços 0 a 99) com uma lista encadeada de blocos
// livres {inicio, tamanho}, sempre em ordem de endereço. Escreva:
//
//   int aloca(Bloco **livres, int tam)
//     first-fit: usa o PRIMEIRO bloco livre com tamanho >= tam, tirando tam
//     posições do começo dele (se sobrar zero, o bloco sai da lista).
//     Devolve o endereço, ou -1 se nenhum bloco serve;
//   void desaloca(Bloco **livres, int ini, int tam)
//     devolve o pedaço à lista, no lugar certo pela ordem de endereço, e
//     FUNDE com o vizinho da esquerda e/ou da direita se encostarem.
//
// Faça, nesta ordem, mostrando a lista de livres depois de cada operação:
// aloca 30, aloca 20, aloca 25, desaloca o de 20, aloca 10, desaloca o de
// 30, desaloca o de 25, aloca 50, aloca 40. No fim, mostre o total livre e
// o maior bloco, e libere a lista.
//
//   Saída esperada:
//   aloca 30 -> 0 | livres: [30,100)
//   aloca 20 -> 30 | livres: [50,100)
//   aloca 25 -> 50 | livres: [75,100)
//   desaloca 30+20 | livres: [30,50) [75,100)
//   aloca 10 -> 30 | livres: [40,50) [75,100)
//   desaloca 0+30 | livres: [0,30) [40,50) [75,100)
//   desaloca 50+25 | livres: [0,30) [40,100)
//   aloca 50 -> 40 | livres: [0,30) [90,100)
//   aloca 40 -> falhou | livres: [0,30) [90,100)
//   Livre: 40 posições, maior bloco: 30
//
// Dicas:
// 1. [a,b) quer dizer "de a até b - 1": o bloco {inicio 30, tamanho 20}
//    aparece como [30,50).
// 2. Em desaloca, ache ant (o último bloco que começa antes de ini) e p (o
//    primeiro depois). Se ant termina em ini, cresça ant; se o pedaço
//    termina onde p começa, junte p também (e libere o nó de p).
// 3. O último "aloca 40" falha com 40 posições livres: é a FRAGMENTAÇÃO
//    externa. Os blocos livres existem, mas nenhum é grande o bastante.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct bloco {
    int inicio;
    int tamanho;
    struct bloco *prox;
} Bloco;

int main(void) {

    return 0;
}
