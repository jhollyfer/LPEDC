## 0177 · Rubro-negra clássica

A central de entregas registra pacotes pelo número, e eles chegam quase em
ordem, o pior caso da BST. No 0145 você viu a rubro-negra **esquerdista**
(LLRB). A prova usa a versão **clássica** do Cormen: as mesmas cores, outras
regras de conserto e ponteiro para o pai.

Uma **árvore rubro-negra** é uma BST em que cada nó tem uma cor e valem as
**cinco propriedades**:

1. todo nó é **vermelho** ou **preto**;
2. a **raiz** é preta;
3. toda **folha** (`T.nil`) é preta;
4. se um nó é vermelho, **os dois filhos são pretos**;
5. para cada nó, todos os caminhos até as folhas abaixo passam pelo **mesmo
   número de nós pretos**.

As "folhas" do Cormen não guardam chave: são os lugares do `NULL`. Todas são
**um nó só**, a **sentinela `T.nil`**, preta, como na lista do 0174. O pai da
raiz também é `T.nil`.

O número de pretos de `x` até uma folha, sem contar `x`, é a **altura negra**
`bh(x)`, igual em todos os caminhos (propriedade 5). A subárvore de `x` tem
pelo menos `2^bh(x) - 1` nós e, pela propriedade 4, `bh(raiz) >= h/2`. Daí
**h ≤ 2 log₂(n + 1)**: busca, mínimo e sucessor custam O(log n).

A **inserção** pendura o nó novo `z` como na BST e o pinta de **vermelho**
(a propriedade 5 se mantém). Só a 4 pode quebrar, se o pai de `z` for
vermelho. O conserto (`RB-INSERT-FIXUP`) olha o **tio** de `z`:

| Caso | Situação | O que fazer |
| --- | --- | --- |
| 1 | tio **vermelho** | pinta pai e tio de preto, o avô de vermelho, e **sobe**: `z` vira o avô |
| 2 | tio **preto**, `z` em **triângulo** (filho direito de um filho esquerdo, ou o espelho) | gira no pai e cai no caso 3 |
| 3 | tio **preto**, `z` em **linha** (filho esquerdo de um filho esquerdo, ou o espelho) | pinta o pai de preto e o avô de vermelho, gira no avô. Acabou |

O caso 1 só troca cores e pode subir até a raiz. Os casos 2 e 3 fazem **no
máximo duas rotações** e encerram. No fim, a raiz vira preta.

Chegam os pacotes 50, 30, 70, 20, 25, 40 e 45. O 20 tem tio vermelho (caso 1).
O 25 forma um triângulo com o 20 e o 30 (casos 2 e 3). O 40 tem tio vermelho, e
o 45 fica em linha com o 40 e o 30 (caso 3, espelho). No desenho, o antes e o
depois de cada caso:

{{ideia}}

No `vermelhopreto.h`, a sentinela fica dentro da struct da árvore, e o
`T->casos` conta cada caso. O conserto, no `vermelhopreto.c` (pai filho
esquerdo; o outro lado é o espelho):

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

O laço nunca testa `NULL`: o tio pode ser a sentinela, preta, e cai nos casos
2 e 3. Se `z` chega à raiz, o pai é `T.nil`, preto, e o `while` para. O
cliente:

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

O fluxograma é o conserto do pacote 25: tio preto (a sentinela), `z` em
triângulo. Caso 2 e caso 3 na mesma volta, e o laço termina:

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

Duas rotações no 25, uma no 45, nenhuma no 20 e no 40. A altura negra só
cresce quando o caso 1 chega à raiz: a árvore cresce **por cima**.

A **remoção** do Cormen (quatro casos, olhando o **irmão** do nó com um "preto
a mais") fica fora daqui. Para a prova: custa O(log n) e faz no máximo **três
rotações**.

> [!WARNING]
> Erros comuns: esquecer de **subir** no caso 1 (`z = avo`) e trocar a ordem
> das cores e da rotação no caso 3. Pegadinha de prova: `bh(x)` **não conta o
> próprio x** e **conta a folha `T.nil`**. Na árvore do exemplo, `bh` da raiz
> é 2: o 25 e a nil, ou o 70 e a nil.

> [!TIP]
> O `NoVP` tem 32 bytes. Todo ponteiro "vazio" aponta para `&T->nil`, então o
> código lê `tio->cor` sem testar `NULL`.

> [!NOTE]
> **Pergunta para você:** na árvore final do exemplo, chega o pacote 47. Quem
> é o pai, quem é o tio e qual caso roda? E se depois chegar o 48? Desenhe e
> confira com o `vp_pre_ordem`.

{{pratique}}
