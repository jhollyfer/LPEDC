// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2829 · ★★★ · O cache da biblioteca
//
// O sistema da biblioteca guarda as 3 páginas do catálogo mais recentes num
// cache. A ordem de uso fica numa lista dupla circular com sentinela (a mais
// recente logo depois da sentinela) e, para achar a página sem percorrer a
// lista, uma tabela de sondagem linear com m = 7 leva o número da página ao
// nó dela (com lápide na remoção). A cada acesso: se a página está no cache
// (acerto), o nó vai para a frente; senão (falta), se o cache está cheio,
// sai o último da lista (o menos recente), e a página nova entra na frente.
// Acessos: 7 0 1 2 0 3 0 4 2 3 0 3 2. Mostre, a cada acesso, A (acerto) ou F
// (falta) e o cache; no fim, o total de faltas.
//
//   Saída esperada:
//   7: F [ 7 ]
//   0: F [ 0 7 ]
//   1: F [ 1 0 7 ]
//   2: F [ 2 1 0 ]
//   0: A [ 0 2 1 ]
//   3: F [ 3 0 2 ]
//   0: A [ 0 3 2 ]
//   4: F [ 4 0 3 ]
//   2: F [ 2 4 0 ]
//   3: F [ 3 2 4 ]
//   0: F [ 0 3 2 ]
//   3: A [ 3 0 2 ]
//   2: A [ 2 3 0 ]
//   faltas: 9 de 13
//
// Dicas:
// 1. A tabela guarda pares (página, No *) com estado LIVRE, OCUPADA ou
//    LAPIDE; a busca passa reto pela lápide.
// 2. Mover para a frente: tira o nó (dois ponteiros) e insere depois da
//    sentinela (quatro), sem if.
// 3. O menos recente é nil.ant.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
