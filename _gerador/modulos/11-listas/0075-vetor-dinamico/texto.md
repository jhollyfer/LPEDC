## 0075 · Vetor dinâmico

Você anota as despesas de uma viagem e não sabe quantas serão. Um
`int despesas[100]` desperdiça memória se forem 5 e estoura se forem 101. O
vetor de tamanho fixo obriga você a adivinhar o tamanho antes de começar: se
sobra espaço, ele fica parado; se falta, não há um jeito barato de crescer
(CELES; RANGEL, 2002). Este assunto abre o módulo de listas com a solução
mais simples.

Pense numa estante de livros. Enquanto há prateleira livre, o livro novo vai
no fim. Quando a estante enche, você compra uma com o dobro do tamanho, passa
os livros para ela na mesma ordem e se desfaz da velha. A **lista
sequencial**, também chamada **lista em vetor**, funciona assim: ela guarda
os itens lado a lado num vetor, na ordem da lista (ZIVIANI, 2010, cap. 3).
Quando o vetor mora no heap e cresce sob demanda, ele é um **vetor
dinâmico**.

Três campos controlam a lista (FEOFILOFF, 2009, cap. 3). `itens` é o
endereço do vetor no heap. `tam` diz quantos itens estão em uso, e `cap`
quantos cabem. A diferença `cap - tam` é a folga. Enquanto `tam < cap`,
inserir no fim é só escrever em `itens[tam]` e somar 1 a `tam`: os itens
ocupam as posições 0 a `tam - 1`, e a primeira vaga é exatamente `tam`.

Quando `tam == cap`, a estante encheu. A função `realloc`, vista no assunto
0055, pede um bloco maior, copia os itens para ele e libera o antigo. Se não
houver memória, ela devolve `NULL` e não mexe no bloco antigo, que continua
válido (CPPREFERENCE, s.d.). Por isso o resultado vai primeiro para uma
variável auxiliar, e só depois de conferido substitui `itens`.

Quanto crescer a cada vez? Crescer de um em um parece econômico, mas cada
item novo copia todos os anteriores: 1 + 2 + 3 + ... + n, cerca de n²/2
cópias para n itens. **Dobrar a capacidade** muda a conta. As cópias
acontecem só quando a lista chega a 1, 2, 4, 8... itens, e somam
1 + 2 + 4 + ... + n, menos de 2n. Dividido pelas n inserções, dá um custo
constante por inserção, O(1) em média. Esse custo médio sobre uma sequência
de operações se chama **custo amortizado**: uma inserção ou outra sai cara,
mas a soma toda fica barata (CORMEN et al., 2024).

Com a lista começando com espaço para 2, as duas primeiras despesas entram
direto. A terceira encontra a lista cheia, a capacidade dobra para 4 e ela
entra. A quinta dobra de novo, para 8, copia as quatro e deixa três vagas.

Ler a posição `i` continua O(1), como em qualquer vetor: `itens[i]` sai de
uma conta de endereço. Já inserir ou remover no **meio** tem um preço:
todos os itens seguintes precisam andar uma casa para abrir ou fechar o
espaço. No pior caso, mexer na posição 0, são n deslocamentos, O(n). A
tabela reúne os custos:

| Operação | Custo |
| --- | --- |
| ler a posição `i` | O(1) |
| inserir no fim | O(1) amortizado |
| inserir ou remover no meio | O(n): desloca os seguintes |

A lista é montada como um **TAD**, no molde do assunto 0074: `lista.h` diz
**o que** a lista faz (criar, inserir, pegar, liberar), e `lista.c` diz
**como**, com a `struct lista` escondida do cliente (CELES; CERQUEIRA;
RANGEL, 2016). O `lista_libera` faz dois `free`: primeiro o do vetor de
itens, depois o da struct, porque depois de liberar a struct não dá mais para
ler o campo `itens`.

> [!WARNING]
> Nunca escreva `l->itens = realloc(l->itens, ...)`: se vier `NULL`, o bloco
> antigo se perde. E um `int *p = &itens[0]` guardado antes de inserir pode
> apontar para o bloco que o `realloc` liberou. Guarde o índice.

{{exemplo}}

As despesas de uma viagem, numa lista que começa com espaço para 2. A 3ª
dobra para 4; a 5ª (R$ 27) dobra para 8, copia os quatro valores e deixa
três vagas:

{{ideia}}

A peça central do `lista.c` garante espaço antes de cada inserção:

```c
struct lista {
    int *itens; // vetor no heap
    int tam;    // quantos itens estão em uso
    int cap;    // quantos itens cabem no vetor
};

// garante espaço para mais um item: se encheu, dobra
static bool garante_espaco(Lista *l) {
    if (l->tam < l->cap) return true;
    int nova_cap = l->cap * 2;
    int *novo = realloc(l->itens, nova_cap * sizeof(int));
    if (novo == NULL) return false; // l->itens continua valendo
    l->itens = novo;
    l->cap = nova_cap;
    return true;
}

bool lista_insere_fim(Lista *l, int valor) {
    if (!garante_espaco(l)) return false;
    l->itens[l->tam] = valor;
    l->tam++;
    return true;
}
```

Quem usa a lista só enxerga a interface de `lista.h`:

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    int despesas[] = {12, 35, 8, 50, 27}; // em reais
    Lista *viagem = lista_cria(2);        // começa com espaço para 2
    if (viagem == NULL) return 1;

    for (int i = 0; i < 5; i++) {
        lista_insere_fim(viagem, despesas[i]);
        printf("inseriu %2d: tam %d, cap %d\n", despesas[i],
               lista_tamanho(viagem), lista_capacidade(viagem));
    }
    lista_imprime(viagem);

    int total = 0;
    for (int i = 0; i < lista_tamanho(viagem); i++) {
        int valor;
        lista_pega(viagem, i, &valor);
        total += valor;
    }
    printf("total: R$ %d\n", total);

    lista_libera(viagem);
    return 0;
}
// Saída:
// inseriu 12: tam 1, cap 2
// inseriu 35: tam 2, cap 2
// inseriu  8: tam 3, cap 4
// inseriu 50: tam 4, cap 4
// inseriu 27: tam 5, cap 8
// [12, 35, 8, 50, 27]
// total: R$ 132
```

"Está cheio?" vem antes de escrever. Para o 27 a resposta é Sim: o vetor
dobra e só então o valor entra em `itens[4]`:

{{fluxograma}}
