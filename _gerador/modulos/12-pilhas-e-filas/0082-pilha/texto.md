## 0082 · Pilha

Você monta um pedido no app de delivery: pizza, refrigerante, pudim. Toca em
"desfazer" e sai o pudim, o último que entrou. Toca de novo e sai o
refrigerante. O app nunca desfaz a pizza antes do pudim, porque ele só mexe
no item mais recente. Para guardar dados com essa regra, você precisa de uma
estrutura que lembre a ordem de chegada e só entregue o último.

A imagem é uma pilha de pratos na pia. Você põe um prato em cima dos outros e,
para lavar, tira o de cima; o prato do fundo só aparece quando todos os de
cima saíram. Essa estrutura é a **pilha** (*stack*): uma sequência que só
deixa mexer numa ponta, o **topo**, e por isso o último a entrar é o primeiro
a sair. A sigla é **LIFO**, do inglês *last in, first out* (FEOFILOFF, 2009).
A pilha de chamadas do assunto 0031 segue a mesma regra: a função chamada por
último é a primeira a terminar.

Quatro operações dão conta de tudo. **Empilhar** (*push*) põe um item no
topo. **Desempilhar** (*pop*) tira o item do topo e devolve o valor dele.
**Olhar o topo** (*peek*) lê o topo sem tirar nada. E a pergunta **está
vazia?** diz se ainda resta algum item. No Cormen elas se chamam PUSH, POP e
STACK-EMPTY (CORMEN et al., 2024, cap. 10). Repare que não existe operação
para ler o terceiro item de baixo para cima: se a pilha deixasse, deixaria de
ser pilha.

O C não traz pilha pronta. Você monta uma como **TAD**, o tipo abstrato de
dados do assunto 0074: o `pilha.h` diz **o que** a pilha faz e o `pilha.c`
decide **como** faz. Quem usa só inclui o `.h` e nunca enxerga os campos. Como
a função de desempilhar precisa devolver duas informações (o valor e se deu
certo), o valor sai por um ponteiro e o retorno `bool` avisa o sucesso
(CELES; RANGEL, 2002):

```c
typedef struct pilha Pilha; // tipo opaco: os campos ficam no pilha.c

Pilha *pilha_cria(void);                     // pilha vazia (NULL se faltar memória)
void pilha_libera(Pilha *p);                 // devolve toda a memória da pilha
bool pilha_vazia(const Pilha *p);            // true se não tem nada
int pilha_tamanho(const Pilha *p);           // quantos itens tem
bool pilha_empilha(Pilha *p, int valor);     // push: false se não coube
bool pilha_desempilha(Pilha *p, int *valor); // pop: false se estava vazia
bool pilha_topo(const Pilha *p, int *valor); // peek: olha o topo sem tirar
```

Duas coisas podem dar errado. Tirar de uma pilha vazia é **underflow**
(estouro para baixo): não há item para devolver. Empilhar numa pilha cheia é
**overflow** (estouro para cima), e ele só acontece porque esta versão guarda
os itens num vetor de tamanho fixo (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 2). As duas funções testam o caso antes de agir e devolvem `false`, em
vez de ler ou escrever fora do vetor.

Por dentro, a pilha em vetor usa um contador `n`, que guarda quantos itens
existem. O fundo fica em `itens[0]`, o topo em `itens[n - 1]`, e `n` aponta a
próxima vaga livre (FEOFILOFF, 2009). Com pizza, refrigerante e pudim
empilhados, `n` vale 3 e o pudim está em `itens[2]`. Empilhar escreve em
`itens[n]` e soma 1 em `n`; desempilhar subtrai 1 de `n` e lê `itens[n]`. O
Cormen conta posições a partir de 1, então nele a pilha vazia tem `S.top`
igual a 0 (CORMEN et al., 2024, cap. 10).

Desempilhar não apaga nada. O pudim continua escrito em `itens[2]`; ele só
saiu da pilha porque `n` voltou a 2, e o próximo `push` escreve por cima.
Por isso as duas operações custam **O(1)**: cada uma faz um teste, uma
atribuição e uma conta, não importa quantos itens a pilha tenha (CELES;
RANGEL, 2002).

> [!WARNING]
> Ler `itens[n]` antes de diminuir `n` pega a gaveta **vazia** acima do topo.
> Aqui `n` é a próxima vaga: empilha em `itens[n]` e depois `n++`; desempilha
> com `n--` e depois lê. Muito livro usa `topo = -1`: não misture convenções.

{{exemplo}}

No app de delivery, os preços entram em centavos (2590, 800 e 1200) nas
gavetas 0, 1 e 2, com `n` igual a 3. O "desfazer" tira o 1200, o último:

{{ideia}}

Trecho do `pilha.c`:

```c
struct pilha {
    int itens[CAPACIDADE]; // CAPACIDADE = 100
    int n;                 // quantos itens estão na pilha
};

bool pilha_empilha(Pilha *p, int valor) {
    if (p->n == CAPACIDADE) {
        return false; // cheia: estouro (overflow)
    }
    p->itens[p->n] = valor;
    p->n++;
    return true;
}

bool pilha_desempilha(Pilha *p, int *valor) {
    if (p->n == 0) {
        return false; // vazia: nada para tirar (underflow)
    }
    p->n--;
    *valor = p->itens[p->n]; // o valor continua no vetor, mas saiu da pilha
    return true;
}
```

O programa só usa as funções do `pilha.h`:

```c
#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }

    // preços em centavos: inteiro não tem erro de arredondamento
    pilha_empilha(pedido, 2590); // pizza: R$ 25,90
    pilha_empilha(pedido, 800);  // refrigerante: R$ 8,00
    pilha_empilha(pedido, 1200); // pudim: R$ 12,00

    int preco;
    if (pilha_desempilha(pedido, &preco)) { // "desfazer": sai o último que entrou
        printf("Desfeito: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    if (pilha_topo(pedido, &preco)) { // só olha, não tira
        printf("Agora no topo: R$ %d,%02d\n", preco / 100, preco % 100);
    }
    printf("Itens no pedido: %d\n", pilha_tamanho(pedido));

    pilha_libera(pedido);
    return 0;
}
// Saída:
// Desfeito: R$ 12,00
// Agora no topo: R$ 8,00
// Itens no pedido: 2
```

O desfazer testa se a pilha está vazia antes de diminuir `n`:

{{fluxograma}}
