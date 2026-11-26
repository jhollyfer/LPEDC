## 0038 · Vetores e funções

A lanchonete da esquina vai reajustar o cardápio em 10%. A coxinha de
R$ 12,50 passa a R$ 13,75 e o suco de R$ 8,00 vai para R$ 8,80. Você escreve
uma função `reajustar` e passa a ela o vetor de preços. A pergunta é: ela
mexe nos preços do `main` ou numa cópia deles?

No assunto 0029 você viu que o C passa argumentos **por valor**: a função
recebe uma cópia e o original fica intacto. Com vetor a regra é outra. O C
nunca copia um vetor inteiro para dentro da função; ele entrega **o endereço
em que o vetor começa** (DEITEL; DEITEL, 2011, cap. 6). Pense em emprestar a
chave do armário em vez de fazer um armário igual: quem recebe a chave abre
as mesmas gavetas. Por isso a função escreve no vetor original, e a coxinha
do `main` passa mesmo a custar R$ 13,75.

No parâmetro, o vetor aparece com colchetes vazios; na chamada, vai só o
nome, sem colchetes e sem índice:

```c
void reajustar(double precos[], int n, double percentual); // protótipo
reajustar(cardapio, 4, 10);                                // chamada
```

Um número dentro dos colchetes do parâmetro não muda nada: `double
precos[4]`, `double precos[100]` e `double precos[]` são a mesma coisa para o
compilador, que ignora o número (BACKES, 2013, cap. 9). Prefira os colchetes
vazios, que não prometem um tamanho que ninguém confere.

Repare no `int n` do protótipo. Como só o endereço chega à função, o tamanho
do vetor fica para trás, e a função não tem como descobri-lo sozinha. Então o
tamanho viaja num parâmetro à parte. Esse par, vetor mais tamanho, aparece no
curso inteiro, em toda função de busca e de ordenação (BACKES, 2013, cap. 9).

Às vezes a função só precisa ler o vetor, como uma que mostra o cardápio na
tela. Nesse caso, marque o parâmetro com **`const`**: `void mostrar(const
double precos[], int n)`. O `const` é uma promessa conferida pelo compilador.
Se alguém escrever `precos[0] = 0;` dentro de `mostrar`, a compilação falha,
e o erro aparece antes de estragar algum preço (DEITEL; DEITEL, 2011, cap. 6).

Um item sozinho do vetor segue a regra antiga. Em `aplicar(cardapio[0])`, a
função recebe uma cópia do `double` que está na gaveta 0, como receberia
qualquer outro número; mudar essa cópia não muda o cardápio (DEITEL; DEITEL,
2011, cap. 6).

Passar o endereço também tem a ver com custo. Na chamada, o frame da função
(assunto 0031) recebe um endereço de 8 bytes, um `int` e um `double`; os
bytes do vetor continuam no frame do `main`. Passar um vetor de 4 itens ou de
um milhão custa os mesmos 8 bytes. No módulo 06 esse endereço ganha nome,
**ponteiro**, e `double precos[]` vira só outro jeito de escrever um ponteiro
(KERNIGHAN; RITCHIE, 1989, cap. 5).

> [!WARNING]
> **`sizeof` dentro da função não dá o tamanho do vetor.** No `main`,
> `sizeof(cardapio)` vale 32 (4 × 8 bytes). Em `reajustar`, `sizeof(precos)`
> vale 8, o tamanho de um endereço, e o laço anda 1 item em vez de 4. O gcc
> avisa (`-Wsizeof-array-argument`); passe o tamanho como parâmetro.

{{exemplo}}

A lanchonete reajusta o cardápio em 10%. A função recebe o endereço de
`cardapio` em `precos`, e cada `precos[i]` é a mesma gaveta que `cardapio[i]`:

{{ideia}}

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

A função é `void`, mas o `main` enxerga os preços novos, porque ela escreveu
direto no vetor dele:

{{fluxograma}}
