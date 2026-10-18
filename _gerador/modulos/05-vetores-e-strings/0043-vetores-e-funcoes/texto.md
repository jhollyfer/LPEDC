## 0043 · Vetores e funções

A lanchonete da esquina vai reajustar o cardápio em 10%. A coxinha de R$ 12,50
passa a R$ 13,75, o suco de R$ 8,00 vai para R$ 8,80. Você escreve uma função
`reajustar` e chama passando o vetor de preços. Pergunta: a função mexe nos
preços do `main` ou numa cópia?

No assunto 0034 você viu que o C passa argumentos **por valor**: a função
recebe uma cópia, e mexer na cópia não muda o original. Com vetor é diferente
na prática: **a função mexe no vetor original**. Isso acontece porque o C nunca
copia um vetor inteiro para uma função. O que vai é **o endereço onde o vetor
começa**, e a função escreve nas mesmas gavetas.

Na declaração, o parâmetro leva colchetes vazios. Na chamada, vai só o nome,
sem colchetes:

```c
void reajustar(double precos[], int n, double percentual); // protótipo
reajustar(cardapio, 4, 10);                                // chamada
```

Repare no `int n`. Como só o endereço do começo chega à função, **o tamanho
não vai junto**. A função não tem como descobrir quantos itens existem: você
passa o tamanho num parâmetro separado. É o par que você vai ver o curso
inteiro: vetor + tamanho. No TS seria `function reajustar(precos: number[])` e
`precos.length` resolveria; no C, não existe `.length`.

Um número dentro dos colchetes do parâmetro é ignorado: `double precos[4]`,
`double precos[100]` e `double precos[]` são a mesma coisa para o compilador.
Prefira os colchetes vazios, que não fingem uma informação que não existe.

E quando a função **não deve** mexer no vetor? Marque o parâmetro com
**`const`**: `void mostrar(const double precos[], int n)`. Se alguém escrever
`precos[0] = 0;` dentro dela, o compilador dá erro. É documentação que o
compilador confere.

Vamos ver na prática. O `main` tem o vetor `cardapio`. A função recebe o
endereço dele no parâmetro `precos`, e cada `precos[i]` é a mesma gaveta que
`cardapio[i]`:

{{ideia}}

O código separa as duas tarefas: `reajustar` escreve (sem `const`), `mostrar`
só lê (com `const`):

```c
#include <stdio.h>

#define ITENS 4

// const: esta função promete só ler o vetor
void mostrar(const double precos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("R$ %6.2f\n", precos[i]);
    }
}

// sem const: esta função escreve nas gavetas do vetor de quem chamou
void reajustar(double precos[], int n, double percentual) {
    for (int i = 0; i < n; i++) {
        precos[i] = precos[i] * (1 + percentual / 100);
    }
}

int main(void) {
    double cardapio[ITENS] = {12.50, 8.00, 22.90, 5.50};

    reajustar(cardapio, ITENS, 10); // vai o vetor (sem colchetes) e o tamanho

    printf("Depois do reajuste de 10%%:\n");
    mostrar(cardapio, ITENS);
    return 0;
}
// Saída:
// Depois do reajuste de 10%:
// R$  13.75
// R$   8.80
// R$  25.19
// R$   6.05
```

Repara no fluxograma: o `main` chama, a função percorre as 4 gavetas e volta.
Ela não devolve nada (`void`), e mesmo assim o `main` enxerga os preços novos,
porque ela escreveu direto no vetor dele:

{{fluxograma}}

Atenção para a diferença: **um elemento** passado sozinho vai por valor, como
qualquer `double`. Uma função `reajustar_um(double preco)` chamada com
`cardapio[0]` recebe uma cópia do 12.50 e não muda nada. É o vetor inteiro (o
nome sem colchetes) que vai pelo endereço. O exemplo A086 mostra as duas
coisas lado a lado.

> [!WARNING]
> **`sizeof` dentro da função não dá o tamanho do vetor.** No `main`,
> `sizeof(cardapio)` vale 32 (4 × 8 bytes). Dentro de `reajustar`,
> `sizeof(precos)` vale 8 num PC de 64 bits: é o tamanho de um **endereço**,
> não do vetor. O truque `sizeof(v) / sizeof(v[0])` só funciona onde o vetor
> foi declarado. O gcc até avisa (`-Wsizeof-array-argument`), mas quem ignora
> o aviso ganha um laço que percorre 1 item em vez de 4. Por isso o tamanho
> vai num parâmetro.

> [!TIP]
> **Por dentro do C:** quando o `main` chama `reajustar(cardapio, 4, 10)`, o
> frame da função na pilha (assunto 0036) recebe três coisas: um endereço (8
> bytes), um `int` e um `double`. Os 32 bytes do vetor ficam onde estão, no
> frame do `main`. Para um vetor de um milhão de itens, a chamada custa o
> mesmo: 8 bytes. É por isso que o C faz assim: copiar vetores inteiros a cada
> chamada seria caro demais. O preço é que qualquer função que recebe o vetor
> pode estragá-lo; o `const` é a sua defesa. No módulo 06 você vai ver que
> esse endereço é um **ponteiro**, e que `double precos[]` no parâmetro é só
> outro jeito de escrever isso.

> [!NOTE]
> **Pergunta para você:** e se você chamasse `reajustar(cardapio, ITENS, 10)`
> duas vezes seguidas? A coxinha ficaria com 20% de aumento (R$ 15,00) ou com
> mais? Calcule antes de rodar.

{{pratique}}
