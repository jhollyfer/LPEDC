## 0177 · Rubro-negra clássica

Uma BST que recebe chaves quase em ordem vira uma corrente: cada nó novo vai
para a direita do anterior, a altura chega a n e a busca volta a custar O(n).
No 0145 você viu uma saída para isso, a rubro-negra **esquerdista** (LLRB). A
prova cobra a versão **clássica**, a do Cormen: as mesmas duas cores, outras
regras de conserto e um ponteiro para o pai em cada nó.

A ideia de pintar os nós de duas cores para manter uma árvore balanceada é
de Guibas e Sedgewick, e a LLRB é uma variante dela (GUIBAS; SEDGEWICK,
1978). A cor não guarda dado nenhum. Ela serve de etiqueta para impor regras
que impedem um caminho de ficar muito mais comprido que outro.

Uma **árvore rubro-negra** é uma BST em que cada nó tem uma cor, vermelho ou
preto, e valem cinco propriedades (CORMEN et al., 2024, cap. 13):

1. todo nó é vermelho ou preto;
2. a raiz é preta;
3. toda folha (`T.nil`) é preta;
4. se um nó é vermelho, os dois filhos dele são pretos;
5. para cada nó, todos os caminhos dele até as folhas abaixo passam pelo
   mesmo número de nós pretos.

A propriedade 3 fala de "folhas" num sentido próprio. As folhas do Cormen não
guardam chave: elas ocupam os lugares onde a BST comum teria `NULL`. E não são
várias: todas são **um nó só**, a sentinela `T.nil`, preta, como a da lista
do 0174. O pai da raiz também é `T.nil` (CORMEN et al., 2024, cap. 13). A
vantagem é a mesma da lista: o código lê a cor de qualquer vizinho sem
testar `NULL` antes, porque o vizinho "vazio" é um nó de verdade.

As propriedades 4 e 5 são as que seguram a altura. A **altura negra**
`bh(x)` é o número de nós pretos no caminho de `x` até uma folha, sem contar
o próprio `x` e contando a folha `T.nil`. Pela propriedade 5, esse número é o
mesmo em qualquer caminho, então `bh(x)` está bem definido. Pela propriedade
4, não existem dois vermelhos seguidos, então pelo menos metade dos nós de
qualquer caminho da raiz até uma folha é preta: `bh(raiz) >= h/2`. Juntando
isso com o fato de que a subárvore de `x` tem pelo menos `2^bh(x) - 1` nós,
sai **h ≤ 2 log₂(n + 1)**. Busca, mínimo e sucessor custam O(log n) (CORMEN
et al., 2024, cap. 13).

A **inserção** começa como a da BST: desce até um lugar vazio e pendura o nó
novo `z` ali. Depois pinta `z` de **vermelho**. A escolha tem motivo: um nó
vermelho não muda a contagem de pretos de caminho nenhum, então a propriedade
5 continua valendo. A única que pode quebrar é a 4, quando o pai de `z` também
é vermelho. O conserto (`RB-INSERT-FIXUP`) olha o **tio** de `z`, o irmão do
pai dele (CORMEN et al., 2024, cap. 13).

Se o tio é vermelho (caso 1), não há rotação. Pai e tio viram pretos, o avô
vira vermelho, e a contagem de pretos fica igual em todos os caminhos. Só que
o avô agora é vermelho e pode ter pai vermelho, então o problema **sobe**: `z`
passa a ser o avô e o laço continua.

Se o tio é preto, o conserto usa rotação, e o formato importa. No caso 2, `z`
forma um **triângulo** com o pai e o avô: é filho direito de um filho
esquerdo, ou o espelho. Uma rotação no pai endireita o triângulo e cai no
caso 3. No caso 3, `z` forma uma **linha**: filho esquerdo de um filho
esquerdo, ou o espelho. Pinte o pai de preto, o avô de vermelho, gire no avô,
e o conserto acaba. A tabela resume os três:

| Caso | Situação | O que fazer |
| --- | --- | --- |
| 1 | tio **vermelho** | pinta pai e tio de preto, o avô de vermelho, e **sobe**: `z` vira o avô |
| 2 | tio **preto**, `z` em **triângulo** (filho direito de um filho esquerdo, ou o espelho) | gira no pai e cai no caso 3 |
| 3 | tio **preto**, `z` em **linha** (filho esquerdo de um filho esquerdo, ou o espelho) | pinta o pai de preto e o avô de vermelho, gira no avô. Acabou |

O caso 1 só troca cores e pode subir até a raiz. Os casos 2 e 3 fazem no
máximo duas rotações e encerram. No fim, a raiz é pintada de preto, para
garantir a propriedade 2.

A **remoção** é mais longa: são quatro casos, e o conserto olha o **irmão**
do nó que ficou com um preto a menos no caminho. Para a prova, guarde o custo:
O(log n), com no máximo **três rotações** (SZWARCFITER; MARKENZON, 2010).

> [!WARNING]
> Erros comuns: esquecer de **subir** no caso 1 (`z = avo`) e trocar a ordem
> de cores e rotação no caso 3. Na prova, `bh(x)` **não conta o próprio x** e
> **conta a folha `T.nil`**.

{{exemplo}}

Uma central de entregas recebe os pacotes 50, 30, 70, 20, 25, 40 e 45, quase
em ordem. O 20 tem tio vermelho (caso 1); o 25 forma triângulo (casos 2 e 3);
o 45 fica em linha (caso 3, espelho). O antes e o depois de cada caso:

{{ideia}}

O conserto no `vermelhopreto.c` (pai filho esquerdo; o outro lado é o
espelho). O `T->casos` conta cada caso:

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
2 e 3. O cliente:

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
