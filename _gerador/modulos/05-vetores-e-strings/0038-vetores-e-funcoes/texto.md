## 0038 · Vetores e funções

A lanchonete da esquina vai reajustar o cardápio em 10%. A coxinha de R$ 12,50
passa a R$ 13,75, o suco de R$ 8,00 vai para R$ 8,80. Você escreve a função
`reajustar` e passa o vetor de preços. Ela mexe nos preços do `main` ou numa
cópia?

No assunto 0029, o C passa argumentos **por valor**: a função recebe uma cópia.
Com vetor é diferente: **a função mexe no vetor original**. O C nunca copia um
vetor inteiro para a função. Vai **o endereço onde o vetor começa**, e a função
escreve nas mesmas gavetas.

No parâmetro, os colchetes ficam vazios. Na chamada, vai só o nome:

```c
void reajustar(double precos[], int n, double percentual); // protótipo
reajustar(cardapio, 4, 10);                                // chamada
```

Por isso o `int n`: como só o endereço chega, **o tamanho não vai junto** e a
função não tem como descobri-lo. Vetor + tamanho é um par que aparece no curso
inteiro.

Um número dentro dos colchetes do parâmetro é ignorado: `double precos[4]`,
`double precos[100]` e `double precos[]` são iguais para o compilador. Prefira
os colchetes vazios.

Quando a função **não deve** mexer no vetor, marque o parâmetro com
**`const`**: `void mostrar(const double precos[], int n)`. Se alguém escrever
`precos[0] = 0;` dentro dela, o compilador dá erro.

O `main` guarda o vetor `cardapio`. A função recebe o endereço dele em
`precos`, e cada `precos[i]` é a mesma gaveta que `cardapio[i]`:

{{ideia}}

`reajustar` escreve (sem `const`) e `mostrar` só lê (com `const`):

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

No fluxograma, o `main` chama e a função percorre as 4 gavetas. Ela é `void`,
mas o `main` enxerga os preços novos, porque ela escreveu direto no vetor dele:

{{fluxograma}}

Um **elemento** passado sozinho vai por valor, como qualquer `double`:
`reajustar_um(double preco)` chamada com `cardapio[0]` recebe uma cópia do
12.50 e não muda nada. Só o vetor inteiro (o nome sem colchetes) vai pelo
endereço. O exemplo A076 mostra as duas coisas lado a lado.

> [!WARNING]
> **`sizeof` dentro da função não dá o tamanho do vetor.** No `main`,
> `sizeof(cardapio)` vale 32 (4 × 8 bytes). Dentro de `reajustar`,
> `sizeof(precos)` vale 8 num PC de 64 bits: é o tamanho de um **endereço**. O
> truque `sizeof(v) / sizeof(v[0])` só funciona onde o vetor foi declarado. O
> gcc avisa (`-Wsizeof-array-argument`); quem ignora ganha um laço que percorre
> 1 item em vez de 4.

> [!TIP]
> **Por dentro do C:** a chamada passa ao frame da função (assunto 0031) um
> endereço (8 bytes), um `int` e um `double`; os 32 bytes do vetor ficam no
> frame do `main`. Por isso passar um vetor custa 8 bytes, seja de 4 itens ou
> de um milhão, e por isso a função pode estragá-lo (o `const` protege). No
> módulo 06 esse endereço será um **ponteiro**, e `double precos[]` é só outro
> jeito de escrevê-lo.

> [!NOTE]
> **Pergunta para você:** e se você chamasse `reajustar(cardapio, ITENS, 10)`
> duas vezes seguidas? A coxinha ficaria com 20% de aumento (R$ 15,00) ou com
> mais? Calcule antes de rodar.

{{pratique}}
