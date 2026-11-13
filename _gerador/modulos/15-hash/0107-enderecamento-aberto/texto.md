## 0107 · Endereçamento aberto

- **Endereçamento aberto**: sem lista. Os itens ficam **dentro do vetor**, e
  quem colide tenta outras posições numa sequência fixa. Cada tentativa é uma
  **sondagem** (CORMEN et al., 2024, cap. 11).
- **Sondagem linear**: começa em `chave % m` e anda uma casa por vez, dando a
  volta no fim: `i = (i + 1) % m`. No Cormen, `h(k, i) = (h'(k) + i) mod m`
  (CORMEN et al., 2024, cap. 11).
- **Outros passos**: a **quadrática**, `(h'(k) + c₁i + c₂i²) mod m`, e a
  **dispersão dupla**, `(h₁(k) + i · h₂(k)) mod m` (assunto 0179)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Operações**: inserir sonda até uma posição livre. Buscar sonda até achar
  a chave ou uma posição **livre**, onde ela teria parado (ZIVIANI, 2010,
  cap. 5).
- **Lápide**: remover marca a posição como **removida** (*tombstone*, o
  `DELETED` do Cormen). A busca passa reto e a inserção pode reaproveitá-la
  (CORMEN et al., 2024, cap. 11).
- **A tabela enche**: α nunca passa de 1. As ocupadas formam blocos que
  atraem mais chaves, o **agrupamento primário**. Com α = 0,5, uma busca sem
  sucesso olha 2,5 posições; com 0,9, cerca de 50 (KNUTH, 1998, seção 6.4).
- **Reconstruir**: passando de 70% a 75% de ocupação, crie uma tabela maior e
  reinsira tudo (exemplo A213). Num bloco só, sem `malloc` por item, a cache
  ajuda (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).

> [!WARNING]
> Remover **não** é marcar a posição como livre. Se a vaga 5 (do 301) volta a
> `LIVRE`, a busca pelo 1104 começa na 4, vê a 5 livre e diz "não está",
> embora ele esteja na 6. Use a lápide (exemplo A214).

{{exemplo}}

O estacionamento do condomínio tem 11 vagas, e a vaga é o apartamento com
resto por 11. O 301 dá 4, ocupada, e para na 5; o 1104 tenta 4, 5 e para na
6. Buscar o 1104 custa 3 sondagens:

{{ideia}}

O TAD é `aberta.h` (interface) e `aberta.c` (vetor de vagas, cada uma com
**estado** `LIVRE`, `OCUPADA` ou `REMOVIDA`). A busca é este laço:

```c
// anda a partir de chave % m até achar a chave ou uma posição LIVRE;
// passa reto pelas REMOVIDAS. Devolve a posição da chave ou -1.
static int procura(const Aberta *t, int chave, int *sondagens) {
    int i = chave % t->m;
    int olhadas = 0;
    for (int passo = 0; passo < t->m; passo++) {
        olhadas++;
        if (t->v[i].estado == LIVRE) {
            break; // a corrente de tentativas acaba aqui
        }
        if (t->v[i].estado == OCUPADA && t->v[i].chave == chave) {
            if (sondagens != NULL) {
                *sondagens = olhadas;
            }
            return i;
        }
        i = (i + 1) % t->m; // a próxima, dando a volta no fim
    }
    if (sondagens != NULL) {
        *sondagens = olhadas;
    }
    return -1;
}
```

O programa do condomínio:

```c
#include <stdio.h>
#include "aberta.h"

int main(void) {
    Aberta *vagas = aberta_cria(11);
    if (vagas == NULL) {
        return 1;
    }
    int aptos[] = {101, 202, 301, 1104, 504};
    int horas[] = {7, 8, 8, 9, 10};
    for (int i = 0; i < 5; i++) {
        int s;
        int vaga = aberta_insere(vagas, aptos[i], horas[i], &s);
        printf("apto %4d: hash %d -> vaga %d, sondagens: %d\n", aptos[i], aptos[i] % 11, vaga, s);
    }
    aberta_mostra(vagas);

    int hora, s;
    if (aberta_busca(vagas, 1104, &hora, &s)) {
        printf("1104 entrou às %dh, sondagens: %d\n", hora, s);
    }
    if (!aberta_busca(vagas, 303, &hora, &s)) {
        printf("303 não está, sondagens: %d\n", s);
    }
    aberta_libera(vagas);
    return 0;
}
// Saída:
// apto  101: hash 2 -> vaga 2, sondagens: 1
// apto  202: hash 4 -> vaga 4, sondagens: 1
// apto  301: hash 4 -> vaga 5, sondagens: 2
// apto 1104: hash 4 -> vaga 6, sondagens: 3
// apto  504: hash 9 -> vaga 9, sondagens: 1
// [ 0] -
// [ 1] -
// [ 2] 101
// [ 3] -
// [ 4] 202
// [ 5] 301
// [ 6] 1104
// [ 7] -
// [ 8] -
// [ 9] 504
// [10] -
// 1104 entrou às 9h, sondagens: 3
// 303 não está, sondagens: 2
```

No fluxograma, "está livre?" encerra sem sucesso e "é o carro?" encerra com
sucesso; senão, anda uma vaga. O 1104 é achado na 6; o 303 para na 7, livre:

{{fluxograma}}
