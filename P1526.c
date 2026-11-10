// Lista · Módulo 15 · Tabelas hash
// Exercício P1526 · ★★★ · O cache das páginas mais recentes
//
// O navegador guarda as 3 páginas usadas mais recentemente (cache LRU).
// Quando o cache está cheio e chega uma página nova, sai a usada há mais
// tempo. As duas operações precisam ser O(1), e isso pede DUAS estruturas
// juntas:
//
// - uma lista DUPLA, da mais recente (frente) à mais antiga (fundo): mover
//   para a frente e tirar do fundo é O(1);
// - uma tabela hash com encadeamento (7 baldes, id % 7) que leva do id da
//   página direto ao nó da lista.
//
//   typedef struct Pagina {
//       int id;
//       struct Pagina *ant, *prox;   // lista dupla
//       struct Pagina *prox_balde;   // corrente do balde
//   } Pagina;
//
// Escreva int acessa(Cache *c, int id): se a página está no cache, é um
// acerto e ela vai para a frente; se não, é uma falta: se o cache está
// cheio, a do fundo sai (da lista E da tabela, com free) e a nova entra na
// frente. Acessos: 10 20 10 30 40 20 10 40 50 40.
//
//   Saída esperada:
//   página 10: falta, cache: 10
//   página 20: falta, cache: 20 10
//   página 10: acerto, cache: 10 20
//   página 30: falta, cache: 30 10 20
//   página 40: (sai 20) falta, cache: 40 30 10
//   página 20: (sai 10) falta, cache: 20 40 30
//   página 10: (sai 30) falta, cache: 10 20 40
//   página 40: acerto, cache: 40 10 20
//   página 50: (sai 20) falta, cache: 50 40 10
//   página 40: acerto, cache: 40 50 10
//   acertos: 3 de 10
//
// Dicas:
// 1. Escreva acha, tira_da_lista, poe_na_frente e tira_da_tabela (com
//    Pagina **pp, como na remoção do P1516).
// 2. O "(sai X)" é impresso dentro de acessa, antes do resultado.
// 3. No fim, libere percorrendo a lista: todo nó está nela.
// 4. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define M 7
#define CAPACIDADE 3

typedef struct Pagina {
    int id;
    struct Pagina *ant, *prox;
    struct Pagina *prox_balde;
} Pagina;

typedef struct {
    Pagina *baldes[M];
    Pagina *frente, *fundo;
    int n;
} Cache;

int main(void) {

    return 0;
}
