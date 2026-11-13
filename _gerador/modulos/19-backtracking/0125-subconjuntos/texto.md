## 0125 · Subconjuntos

- **Subconjunto**: cada item entra ou não entra. Com `n` itens há **2ⁿ**
  subconjuntos, contando o vazio e o conjunto inteiro; a lista de todos é o
  **conjunto das partes** (FEOFILOFF, 2009).
- **Enumerar**: gerar todos os casos sem esquecer nem repetir nenhum
  (FEOFILOFF, 2009).
- **Árvore de decisões**: cada nível decide um item; um ramo deixa o item de
  fora e o outro o põe. As folhas são os subconjuntos (ZIVIANI, 2010, cap. 2).
- **Versão recursiva**: `gera(i, k)` abre dois caminhos para o item `i`, sem
  ele e com ele, e mostra a escolha quando `i` chega a `n`. Como `k` é
  **parâmetro**, a escolha se desfaz sozinha na volta (KERNIGHAN; RITCHIE, 1989).
- **Versão por bits**: conte `m` de 0 a 2ⁿ - 1 e leia o bit `i` de `m` como "o
  item `i` entra" (assunto 0065). O 5 é `101`: itens 0 e 2 (KNUTH, 2011).

```c
for (int m = 0; m < (1 << N); m++)      // 1 << 3 vale 8
    for (int i = 0; i < N; i++)
        if (m & (1 << i)) { /* o item i está no subconjunto m */ }
```

- **Custo**: 2ⁿ⁺¹ - 1 chamadas e 2ⁿ folhas; mostrar cada uma custa até `n`,
  logo **O(n · 2ⁿ)**. Só serve para `n` pequeno (FEOFILOFF, 2009).

> [!WARNING]
> `m & (1 << i)` não dá 1 com o bit ligado: dá o próprio `1 << i`. Com `== 1`,
> só o item 0 é reconhecido. Com `int`, `1 << i` vale até `i = 30`; acima,
> use `1ULL << i`.

{{exemplo}}

Na fila do açaí há três complementos: granola (R$ 2), banana (R$ 3) e paçoca
(R$ 4). São 8 copos possíveis, as 8 folhas da árvore, na ordem em que o
programa os mostra:

{{ideia}}

```c
#include <stdio.h>

#define N 3

const char *nomes[N] = {"granola", "banana", "paçoca"};
const int precos[N] = {2, 3, 4}; // reais

int cesta[N];       // índices dos itens escolhidos até agora
int chamadas = 0;

// decide o item i; os k primeiros lugares da cesta já estão ocupados
void gera(int i, int k) {
    chamadas++;
    if (i == N) {                       // decidiu todos: mostra a cesta
        int total = 0;
        printf("{");
        for (int j = 0; j < k; j++) {
            printf(j == 0 ? "%s" : ", %s", nomes[cesta[j]]);
            total += precos[cesta[j]];
        }
        printf("} R$ %d\n", total);
        return;
    }
    gera(i + 1, k);                     // caminho 1: sem o item i
    cesta[k] = i;                       // caminho 2: com o item i
    gera(i + 1, k + 1);
}

int main(void) {
    gera(0, 0);
    printf("%d chamadas\n", chamadas);
    return 0;
}
// Saída:
// {} R$ 0
// {paçoca} R$ 4
// {banana} R$ 3
// {banana, paçoca} R$ 7
// {granola} R$ 2
// {granola, paçoca} R$ 6
// {granola, banana} R$ 5
// {granola, banana, paçoca} R$ 9
// 15 chamadas
```

A árvore tem 1 + 2 + 4 + 8 = 15 nós, um por chamada, e a pilha nunca passa de
4 frames. O fluxograma não tem laço: quem repete é a recursão:

{{fluxograma}}
