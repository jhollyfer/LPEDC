## 0106 · Encadeamento

O assunto 0105 terminou com uma certeza incômoda: duas chaves diferentes vão
cair no mesmo balde. Se cada balde guarda um item só, o segundo não tem onde
ficar. A primeira saída é deixar o balde guardar quantos itens precisar.

Pense no hortifrúti com o estoque em 5 prateleiras. Cada fruta tem a sua
prateleira, dada por uma regra. Quando duas frutas caem na mesma, ficam lado a
lado, e achar o kiwi é olhar só a prateleira dele, nunca o estoque inteiro.
Esse é o **encadeamento**, também chamado de encadeamento separado: cada balde
guarda a **cabeça de uma lista encadeada** com todos os itens cujo hash caiu
ali (CORMEN et al., 2024, cap. 11). A tabela vira um vetor de ponteiros,
`No *baldes[m]`, e um balde vazio é só um ponteiro `NULL`.

Toda operação começa igual: calcule o balde, `i = hash(chave) % m`. Daí em
diante, é lista encadeada do módulo 11. Para **inserir**, procure a chave na
lista de `baldes[i]`. Se ela já está lá, troque o valor; se não está, crie um
nó e ponha **no início** da lista, que custa O(1) porque não precisa andar até
o fim. Para **buscar**, percorra só essa lista. Para **remover**, faça a
remoção de lista que você já conhece, guardando o nó anterior para religar o
`prox` (CELES; RANGEL, 2002).

Quanto custa buscar? Depende do tamanho da lista do balde. Se a função espalha
bem, as `n` chaves se dividem por igual entre os `m` baldes, e cada lista tem
em média `α = n / m` nós, o fator de carga do 0105. A busca então gasta um
passo para calcular o balde e mais α para percorrer a lista: Θ(1 + α) na
média (CORMEN et al., 2024, cap. 11). Se você aumenta `m` sempre que `n`
cresce, α fica parado num valor constante, e a busca passa a custar O(1) na
média. Esse é o motivo de a tabela hash ser tão usada.

O pior caso é outra história. Uma função ruim, que joga todas as chaves no
mesmo balde, transforma a tabela numa lista única, e a busca volta a ser O(n)
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7). A estrutura é a mesma; quem
decide se ela é rápida é a função hash.

Uma propriedade boa do encadeamento: a tabela **nunca enche**. Cada balde
cresce o quanto precisar, então α pode passar de 1 sem problema. O exemplo
A211 guarda 8 itens em 2 baldes, com α = 4. Fica lento, mas funciona
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).

O preço está na memória. Cada nó é um `malloc` separado, e o sistema não
libera nada sozinho. A função `tabela_libera` percorre cada balde e dá `free`
em todos os nós, guardando o `prox` numa variável antes de liberar o nó atual,
porque depois do `free` ler `p->prox` é ler memória que não é mais sua. Dar
só `free(t->baldes)` libera o vetor de ponteiros e deixa as listas perdidas na
memória, sem ninguém apontando para elas (CELES; CERQUEIRA; RANGEL, 2016).

> [!WARNING]
> Compare chave de texto com `strcmp`, nunca com `==`: `p->chave == chave`
> compara **endereços**. Pode funcionar com literais e quebra com chave vinda
> do teclado. O nó guarda a sua **cópia** da chave, porque o buffer de quem
> chamou é reaproveitado.

{{exemplo}}

O hortifrúti guarda o estoque em 5 baldes, com o hash polinomial do 0105.
Banana, uva, pera, kiwi, manga e caju caem em 4, 2, 4, 1, 1 e 4; cada nova
entra no início. Buscar "kiwi" vai ao balde 1 e faz 2 comparações:

{{ideia}}

A estrutura segue o padrão TAD: `tabela.h` com a interface e o tipo opaco,
`tabela.c` com o nó, os baldes e as operações:

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

O cliente conhece só o `tabela.h`:

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

No fluxograma da busca, o hash leva ao balde e o resto é o laço de lista. O
"kiwi" dá uma volta (passa pela manga) e para no Sim; o "limao" cai no balde
0, vazio, e sai pelo Não:

{{fluxograma}}
