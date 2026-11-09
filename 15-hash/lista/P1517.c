// Lista · Módulo 15 · Tabelas hash
// Exercício P1517 · ★★☆ · O primeiro crachá repetido na catraca
//
// A catraca da fábrica registrou os crachás na ordem em que passaram:
// 4821, 3307, 9954, 1220, 6638, 3307, 4821, 7012, 9954. A segurança quer o
// PRIMEIRO crachá que passou pela segunda vez (o que repetiu mais cedo).
// Use um conjunto hash: endereçamento aberto, m = 17, sondagem linear,
// VAZIO = -1, com a função bool ja_viu(int t[], int k), que devolve true se
// k já estava e, se não estava, guarda k. Pare na primeira repetição.
//
//   Saída esperada:
//   primeiro repetido: 3307, na passagem 6
//
// Dicas:
// 1. Uma passada só, em O(n) médio. A força bruta (comparar cada um com
//    todos os anteriores) seria O(n²).
// 2. O 4821 é o primeiro a APARECER entre os repetidos, mas o 3307 repete
//    ANTES: a pergunta é pela repetição, não pela primeira aparição.
// 3. Um conjunto é uma tabela hash só com chaves, sem valor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

#define M 17
#define VAZIO -1

int main(void) {
    int passagens[] = {4821, 3307, 9954, 1220, 6638, 3307, 4821, 7012, 9954};
    (void)passagens;

    return 0;
}
