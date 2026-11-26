## 0087 · Deque

No app de música, a fila de reprodução tem as faixas 5, 8 e 3. Você toca em
"tocar em seguida" e a faixa 11 vai para a **frente**. Depois se arrepende e
tira a última faixa adicionada, pelo **fim**. A pilha só mexe numa ponta, a
fila insere numa e retira na outra, e nenhuma das duas faz isso. Falta uma
estrutura que aceite as duas operações nas duas pontas.

Essa estrutura é o **deque**, do inglês *double-ended queue* (pronuncia-se
"deck"), também chamado de **fila dupla**: uma sequência que deixa inserir e
retirar tanto pela frente quanto pelo fundo (CELES; RANGEL, 2002). Pense numa
fila de embarque com porta nas duas pontas: a pessoa com prioridade entra
pela frente, e quem desiste sai por trás.

As operações são quatro. `deque_insere_inicio` e `deque_retira_inicio` mexem
na frente; `deque_insere_fim` e `deque_retira_fim` mexem no fundo (CELES;
RANGEL, 2002). Com elas, o deque imita as estruturas anteriores. Se você só
insere e retira pelo fim, ele se comporta como **pilha**. Se insere pelo fim
e retira pelo início, ele se comporta como **fila** (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 4). Quando o item que sai é o de maior prioridade, e
não o de uma ponta, a estrutura passa a ser outra, a fila de prioridade, que
o assunto 0102 monta com heap.

A versão em vetor reaproveita a fila circular do 0085. A única novidade é que
o `inicio` agora anda também para **trás**. Para inserir na frente, ele recua
uma gaveta e o valor entra ali; se o início estava na gaveta 0, ele dá a
volta e vai para a última. Inserir no fim e retirar do início são iguais aos
da fila. Retirar do fim é o mais simples de todos: o último item fica em
`(inicio + n - 1) % CAPACIDADE`, e basta ler ali e diminuir `n` (CELES;
RANGEL, 2002). As quatro operações custam **O(1)**, enquanto num vetor comum
inserir no início obrigaria a empurrar tudo, O(n).

A conta de recuar uma gaveta fica numa função auxiliar marcada com `static`.
Numa função escrita fora de qualquer bloco, `static` não cria variável
estática: ele tira a função da **ligação externa**, e ela fica **privada** do
arquivo (KERNIGHAN; RITCHIE, 1988). O `deque.c` pode usá-la, mas nenhum outro
arquivo enxerga o nome, e o TAD continua expondo só o que está no `.h`.

Se você quiser o deque encadeado, a lista simples não basta. Retirar do fim
exige que o último nó conheça o penúltimo, para que o penúltimo passe a ser o
fim. Isso pede a lista **duplamente encadeada** do assunto 0079, em que cada
nó aponta para o próximo e para o anterior (CELES; RANGEL, 2002).

> [!WARNING]
> Em C, o resto de negativo é **negativo**: `-1 % 8` vale `-1`, não 7. Assim
> `(inicio - 1) % CAPACIDADE` com `inicio = 0` escreve em `itens[-1]`. Some a
> capacidade antes: `(inicio - 1 + CAPACIDADE) % CAPACIDADE`
> (CPPREFERENCE, s.d.).

{{exemplo}}

No app de música, as faixas 5, 8 e 3 entram pelo fim, nas gavetas 0, 1 e 2.
A 11 entra pela frente ("tocar em seguida"): o início recua da gaveta 0 e dá
a volta para a 7. A ordem fica 11, 5, 8, 3:

{{ideia}}

A conta do recuo fica numa função auxiliar `static`:

```c
#define CAPACIDADE 8

// gaveta anterior a i, dando a volta: anterior(0) = CAPACIDADE - 1
static int anterior(int i) {
    return (i - 1 + CAPACIDADE) % CAPACIDADE; // (i - 1) % CAPACIDADE daria -1 com i = 0
}

bool deque_insere_inicio(Deque *d, int valor) {
    if (d->n == CAPACIDADE) {
        return false;
    }
    d->inicio = anterior(d->inicio); // o início recua uma gaveta
    d->itens[d->inicio] = valor;
    d->n++;
    return true;
}

bool deque_retira_fim(Deque *d, int *valor) {
    if (d->n == 0) {
        return false;
    }
    *valor = d->itens[(d->inicio + d->n - 1) % CAPACIDADE]; // o último ocupado
    d->n--;
    return true;
}
```

Programa da fila de músicas:

```c
#include <stdio.h>
#include "deque.h"

int main(void) {
    Deque *fila = deque_cria(); // guarda o número da faixa do álbum
    if (fila == NULL) {
        return 1;
    }

    deque_insere_fim(fila, 5); // "adicionar à fila": vai para o fim
    deque_insere_fim(fila, 8);
    deque_insere_fim(fila, 3);
    deque_insere_inicio(fila, 11); // "tocar em seguida": fura a fila

    // ordem agora: 11 5 8 3
    int faixa;
    if (deque_retira_inicio(fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (deque_retira_fim(fila, &faixa)) { // desistiu da última que adicionou
        printf("Removida a faixa %d\n", faixa);
    }

    printf("Ainda na fila:");
    while (deque_retira_inicio(fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");

    deque_libera(fila);
    return 0;
}
// Saída:
// Tocando a faixa 11
// Removida a faixa 3
// Ainda na fila: 5 8
```

Na entrada da faixa 11, o caminho difere do da fila só no recuo do início com
`anterior`, que soma 8 antes do `%`:

{{fluxograma}}
