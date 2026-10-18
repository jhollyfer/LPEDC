## 0106 · Encadeamento

No hortifrúti, o estoque fica em 5 prateleiras numeradas. A regra da casa diz
em qual prateleira vai cada fruta. Quando duas frutas caem na mesma
prateleira, ninguém joga uma fora: elas ficam **lado a lado**, em fila. Para
achar o kiwi, você vai direto à prateleira 1 e olha só o que está ali.

Essa é a primeira forma de tratar colisão: o **encadeamento** (ou
encadeamento separado). Cada balde da tabela deixa de guardar um item e passa a
guardar a **cabeça de uma lista encadeada**, a corrente com todos os itens
cujo hash caiu ali. A tabela vira um vetor de ponteiros: `No *baldes[m]`.

As três operações são as de lista que você já conhece (módulo 11), com um
passo a mais na frente: calcular o balde.

- **inserir**: calcula `i = hash(chave) % m`, procura a chave na lista de
  `baldes[i]`; se achar, troca o valor; se não, cria um nó e põe **no início**
  da lista, em O(1);
- **buscar**: calcula `i` e percorre só a lista de `baldes[i]`;
- **remover**: calcula `i` e faz a remoção de lista, guardando o anterior.

Quanto custa? Com uma função hash que espalha bem, cada lista tem, em média,
`α = n / m` nós (o fator de carga). Buscar custa O(1 + α): o cálculo do hash
mais uma lista curta. Se `m` cresce junto com `n`, α fica constante e a busca
fica O(1) na média. No pior caso, com um hash ruim que joga tudo num balde
só, a tabela vira uma lista única e a busca volta a ser O(n).

No encadeamento a tabela **nunca enche**: α pode passar de 1, as listas só
ficam mais compridas. Algumas implementações, quando uma corrente fica
comprida demais, até trocam a lista por uma árvore.

Vamos ver na prática. Seis frutas entram na ordem banana, uva, pera, kiwi,
manga e caju, com o hash polinomial do assunto anterior e `m = 5`. Os índices
saem 4, 2, 4, 1, 1 e 4. Como cada nova entra no início da corrente, o balde 4
termina com caju, pera, banana. Para buscar "kiwi", a busca vai ao balde 1,
compara com "manga" (não é), depois com "kiwi" (é): 2 comparações, sem olhar
nenhum outro balde:

{{ideia}}

A estrutura segue o padrão TAD: `tabela.h` com a interface e o tipo opaco,
`tabela.c` com o nó, os baldes e as operações. O coração da implementação:

```c
typedef struct No {
    char chave[TAM_CHAVE]; // cópia da chave (não um ponteiro emprestado)
    int valor;
    struct No *prox;
} No;

struct Tabela {
    int m;       // número de baldes
    int n;       // número de itens
    No **baldes; // vetor de m cabeças de lista
};

bool tabela_busca(const Tabela *t, const char *chave, int *valor, int *comparacoes) {
    int i = (int)(hash(chave) % (unsigned)t->m);
    int olhados = 0;
    for (No *p = t->baldes[i]; p != NULL; p = p->prox) {
        olhados++;
        if (strcmp(p->chave, chave) == 0) {
            *valor = p->valor;
            if (comparacoes != NULL) {
                *comparacoes = olhados;
            }
            return true;
        }
    }
    if (comparacoes != NULL) {
        *comparacoes = olhados;
    }
    return false;
}
```

E o cliente, que só conhece o `tabela.h` (exemplo A211):

```c
#include <stdio.h>
#include "tabela.h"

int main(void) {
    Tabela *estoque = tabela_cria(5);
    if (estoque == NULL) {
        return 1;
    }
    const char *frutas[] = {"banana", "uva", "pera", "kiwi", "manga", "caju"};
    int caixas[] = {12, 30, 8, 5, 20, 14};
    for (int i = 0; i < 6; i++) {
        tabela_insere(estoque, frutas[i], caixas[i]);
    }
    tabela_mostra(estoque);

    int qtd, olhados;
    if (tabela_busca(estoque, "kiwi", &qtd, &olhados)) {
        printf("kiwi: %d caixas (%d comparações)\n", qtd, olhados);
    }
    if (!tabela_busca(estoque, "limao", &qtd, &olhados)) {
        printf("limao: não tem (%d comparações)\n", olhados);
    }
    tabela_libera(estoque);
    return 0;
}
// Saída:
// [0]
// [1] -> manga:20 -> kiwi:5
// [2] -> uva:30
// [3]
// [4] -> caju:14 -> pera:8 -> banana:12
// kiwi: 5 caixas (2 comparações)
// limao: não tem (0 comparações)
```

Repara no fluxograma da busca: o hash leva direto ao balde, e daí em diante é
o laço de sempre de lista encadeada. O "kiwi" dá uma volta no laço (passa pela
manga) e para no Sim. O "limao" cai no balde 0, que está vazio, e sai pelo Não
logo na primeira pergunta:

{{fluxograma}}

> [!WARNING]
> Chave de texto se compara com `strcmp`, nunca com `==`. `p->chave == chave`
> compara **endereços**: diz se as duas strings moram no mesmo lugar da
> memória, não se têm as mesmas letras. O programa compila, às vezes até
> funciona (o compilador pode juntar literais iguais num endereço só) e quebra
> quando a chave vem do teclado ou de um arquivo. O mesmo vale ao guardar: o
> nó tem a sua **cópia** da chave, porque o buffer de quem chamou vai ser
> reaproveitado.

> [!TIP]
> **Por dentro do C:** com `m = 5`, os baldes são um bloco de 5 ponteiros (40
> bytes) contíguo no heap. Cada nó é um `malloc` separado: 32 bytes da chave,
> 4 do valor, 4 de preenchimento e 8 do `prox`, `sizeof(No)` = 48, espalhados
> em qualquer canto da memória. Por isso o `tabela_libera` precisa andar em
> **todas** as correntes dando `free` em cada nó, guardando o `prox` antes; um
> `free(t->baldes)` sozinho solta só os 40 bytes das cabeças e vaza o resto. E
> como os nós ficam longe uns dos outros, percorrer uma corrente comprida custa
> caro para a cache do processador.

> [!NOTE]
> **Pergunta para você:** o "limao" cai no balde 0. Se você inserir "limao"
> com 9 caixas e depois buscar "coco" (que também cai no balde 0), quantas
> comparações a busca faz? E se a inserção fosse no fim da corrente, mudaria
> alguma coisa? Teste no A211.

{{pratique}}
