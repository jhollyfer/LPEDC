## 0177 · Rubro-negra clássica

A central de entregas do bairro registra cada pacote pelo número assim que
ele chega, e o entregador consulta a central a toda hora. Os números chegam
quase em ordem, o pior caso da BST. No 0145 você viu a rubro-negra
**esquerdista** (LLRB), uma versão enxuta. A prova do PPGI, os livros de
referência e as bibliotecas usam a versão **clássica** do Cormen:
a mesma ideia de cores, com outras regras de conserto e com ponteiro para o
pai.

Uma **árvore rubro-negra** é uma BST em que cada nó tem um bit a mais, a cor,
e que respeita as **cinco propriedades**:

1. todo nó é **vermelho** ou **preto**;
2. a **raiz** é preta;
3. toda **folha** (`T.nil`) é preta;
4. se um nó é vermelho, **os dois filhos são pretos** (nunca dois vermelhos
   seguidos);
5. para cada nó, todos os caminhos dele até as folhas abaixo passam pelo
   **mesmo número de nós pretos**.

As "folhas" do Cormen não guardam chave: são os lugares onde estaria um
`NULL`. Para não tratar `NULL` como caso especial, todas elas são **um nó
só**, a **sentinela `T.nil`**, preta, a mesma ideia da lista do 0174. O pai da
raiz também é `T.nil`.

O número de pretos de um nó `x` até uma folha, sem contar `x`, é a **altura
negra** `bh(x)`. Pela propriedade 5 ele não depende do caminho. Dela sai a
garantia: a subárvore de `x` tem pelo menos `2^bh(x) - 1` nós (por indução:
cada filho tem altura negra de pelo menos `bh(x) - 1`). Pela propriedade 4,
pelo menos metade dos nós de qualquer caminho da raiz até uma folha é preta,
então `bh(raiz) >= h/2`. Juntando, `n >= 2^(h/2) - 1`, e daí
**h ≤ 2 log₂(n + 1)**. Busca, mínimo, sucessor: tudo O(log n).

A **inserção** pendura o nó novo `z` como na BST e pinta de **vermelho** (assim
a propriedade 5 continua valendo). Só a 4 pode quebrar: se o pai de `z` for
vermelho. O conserto (`RB-INSERT-FIXUP`) olha o **tio** de `z`, o irmão do pai:

| Caso | Situação | O que fazer |
| --- | --- | --- |
| 1 | tio **vermelho** | pinta pai e tio de preto, o avô de vermelho, e **sobe**: `z` vira o avô |
| 2 | tio **preto**, `z` em **triângulo** (filho direito de um filho esquerdo, ou o espelho) | gira no pai e cai no caso 3 |
| 3 | tio **preto**, `z` em **linha** (filho esquerdo de um filho esquerdo, ou o espelho) | pinta o pai de preto e o avô de vermelho, gira no avô. Acabou |

O caso 1 só troca cores e pode subir até a raiz (O(log n) vezes). Os casos 2 e
3 fazem **no máximo duas rotações** e encerram. No fim, a raiz é pintada de
preto.

Chegam os pacotes 50, 30, 70, 20, 25, 40 e 45. O 20 tem
tio vermelho (caso 1). O 25 forma um triângulo com o 20 e o 30 (caso 2, depois
3). O 40 tem tio vermelho de novo, e o 45 fica em linha com o 40 e o 30 (caso
3, o espelho). No desenho, o antes e o depois de cada caso:

{{ideia}}

O TAD é o `vermelhopreto.h`. A sentinela fica dentro da struct da árvore,
como na lista do 0174, e o `T->casos` conta quantas vezes cada caso rodou. O
conserto, no `vermelhopreto.c` (o lado em que o pai é filho esquerdo; o outro
é o espelho):

```c
static void conserta(ArvVP *T, NoVP *z) {
    while (z->pai->cor == VERMELHO) {
        NoVP *avo = z->pai->pai;
        if (z->pai == avo->esq) {
            NoVP *tio = avo->dir;
            if (tio->cor == VERMELHO) { // caso 1: tio vermelho, recolore e sobe
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
                z = avo;
                T->casos[1]++;
            } else {
                if (z == z->pai->dir) { // caso 2: tio preto, z em "triângulo"
                    z = z->pai;
                    gira_esquerda(T, z);
                    T->casos[2]++;
                }
                z->pai->cor = PRETO; // caso 3: tio preto, z em "linha"
                z->pai->pai->cor = VERMELHO;
                gira_direita(T, z->pai->pai);
                T->casos[3]++;
            }
        } else {
            // o espelho: troque esq por dir e esquerda por direita
        }
    }
    T->raiz->cor = PRETO; // propriedade 2: a raiz é preta
}
```

O laço nunca testa `NULL`: o tio pode ser a sentinela, e ela é
preta, então cai nos casos 2 e 3 sem `if` a mais. E a raiz tem `T.nil` como
pai, preto: quando `z` chega à raiz, o `while` para sozinho. O cliente:

```c
#include <stdio.h>
#include "vermelhopreto.h"

int main(void) {
    int pacotes[] = {50, 30, 70, 20, 25, 40, 45};
    ArvVP *T = vp_cria();
    if (T == NULL) {
        return 1;
    }
    for (int i = 0; i < 7; i++) {
        int c1 = T->casos[1], c2 = T->casos[2], c3 = T->casos[3];
        vp_insere(T, pacotes[i]);
        printf("Insere %d: pré", pacotes[i]);
        vp_pre_ordem(T);
        printf(" | casos 1/2/3: %d %d %d\n", T->casos[1] - c1, T->casos[2] - c2, T->casos[3] - c3);
    }
    printf("Altura %d, altura negra %d, propriedades: %s\n", vp_altura(T),
           vp_altura_negra(T), vp_confere(T) ? "ok" : "quebradas");
    vp_libera(T);
    return 0;
}
// Saída:
// Insere 50: pré 50 | casos 1/2/3: 0 0 0
// Insere 30: pré 50 30* | casos 1/2/3: 0 0 0
// Insere 70: pré 50 30* 70* | casos 1/2/3: 0 0 0
// Insere 20: pré 50 30 20* 70 | casos 1/2/3: 1 0 0
// Insere 25: pré 50 25 20* 30* 70 | casos 1/2/3: 0 1 1
// Insere 40: pré 50 25* 20 30 40* 70 | casos 1/2/3: 1 0 0
// Insere 45: pré 50 25* 20 40 30* 45* 70 | casos 1/2/3: 0 0 1
// Altura 3, altura negra 2, propriedades: ok
```

O fluxograma é o conserto do pacote 25. Pai vermelho, tio preto (a
sentinela), `z` em triângulo: caso 2 e, na mesma volta, caso 3. Depois disso o
pai de `z` é preto e o laço termina:

{{fluxograma}}

### Passo a passo

O conserto de três inserções. "Pai" e "avô" são os de `z` no início da linha:

| Inserção | z | Pai | Tio | Caso | O que acontece | Depois |
| --- | --- | --- | --- | --- | --- | --- |
| 20 | 20 | 30 vermelho | 70 vermelho | 1 | 30 e 70 pretos, 50 vermelho; `z = 50` | 50 é a raiz: o laço para e ela volta a preto |
| 25 | 25 | 20 vermelho | nil (preto) | 2 | triângulo: `z = 20`, gira à esquerda no 20 | o 25 fica entre o 30 e o 20 |
| 25 | 20 | 25 vermelho | nil (preto) | 3 | 25 preto, 30 vermelho, gira à direita no 30 | 25 com 20\* e 30\*; o pai de `z` é preto, fim |
| 40 | 40 | 30 vermelho | 20 vermelho | 1 | 30 e 20 pretos, 25 vermelho; `z = 25` | o pai do 25 é o 50, preto: fim |
| 45 | 45 | 40 vermelho | nil (preto) | 3 (espelho) | 40 preto, 30 vermelho, gira à esquerda no 30 | 40 com 30\* e 45\* |

Duas rotações no 25, uma no 45, nenhuma no 20 e no 40. A altura negra começa
em 1 e só cresce quando o caso 1 chega à raiz e ela volta a ser preta: a
árvore cresce **por cima**, como a árvore 2-3 por trás da LLRB.

E a **remoção**? O Cormen também a faz em O(log n), com um conserto de quatro
casos olhando o **irmão** do nó que ficou com um "preto a mais". É bem mais
longa que a inserção e não cabe aqui. Para a prova, basta saber que ela
existe, que custa O(log n) e que faz no máximo **três rotações**.

> [!WARNING]
> Os erros mais comuns no conserto: esquecer de **subir** no caso 1
> (`z = avo`), e o vermelho do avô fica colado num pai vermelho lá em cima (é
> o bug do E1061); e trocar a ordem das cores e da rotação no caso 3, que
> deixa o vermelho no lugar errado. Outra pegadinha de prova: "a altura negra
> conta a raiz?". No Cormen, `bh(x)` **não conta o próprio x** e **conta a
> folha `T.nil`**. Na árvore do exemplo, `bh` da raiz é 2: o 25 e a nil, ou o
> 70 e a nil.

> [!TIP]
> **Por dentro do C:** o `NoVP` tem 32 bytes: 4 da chave, 4 do `enum` da cor e
> três ponteiros de 8. A sentinela é **um nó só** dentro da `ArvVP`, e todo
> ponteiro "vazio" da árvore aponta para o endereço `&T->nil`: mil folhas,
> zero bytes a mais. Como a sentinela é um nó real, o código pode **ler**
> `tio->cor` sem testar `NULL`, e a rotação pode até **escrever** no
> `nil.pai` sem estragar nada (a remoção do Cormen usa isso). Compare com a
> LLRB do 0145: 24 bytes por nó e nenhum `pai`, mas o conserto é recursivo e
> faz mais rotações. A clássica faz no máximo 2 rotações por inserção (o
> A354 mede).

> [!NOTE]
> **Pergunta para você:** na árvore final do exemplo, chega o pacote 47. Quem
> é o pai, quem é o tio e qual caso roda? E se depois chegar o 48? Desenhe e
> confira com o `vp_pre_ordem`.

{{pratique}}
