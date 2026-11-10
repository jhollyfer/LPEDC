## 0046 · Passagem por referência

No mercadinho, as etiquetas saíram trocadas: o arroz a R$ 8 e o feijão a
R$ 25. Você quer uma função `troca` que conserte isso. A versão óbvia não
funciona, por causa do jeito como o C chama funções.

No C, **todo argumento é passado por valor** (assunto 0029): a função recebe
uma **cópia**. `troca_copias(arroz, feijao)` cria `a` e `b`, com 8 e 25, troca
as cópias e termina; elas somem com o frame (assunto 0031). O `arroz` do
`main` nem fica sabendo.

A saída é entregar o **endereço** em vez do valor. A função recebe ponteiros,
`void troca(int *a, int *b)`, e quem chama passa os endereços:
`troca(&arroz, &feijao)`. O endereço também é copiado, mas a cópia aponta para
**a mesma gaveta**. Dentro da função, `*a` é o próprio `arroz` do `main`. É a
**passagem por referência** (no C, simulada com ponteiros).

Isso explica o `&` do `scanf`: `scanf("%d", &total)` precisa **escrever** na
variável, então pede o endereço. Sem o `&`, receberia uma cópia do lixo de
`total` e escreveria num endereço inventado. Já `scanf("%s", nome)` vai sem `&`
porque o nome de um vetor já é o endereço do primeiro elemento (assunto 0038;
o 0047 detalha).

O mesmo truque resolve outro limite: o `return` devolve **um** valor só. Para
entregar dois ou mais resultados, a função recebe ponteiros e escreve neles (o
A092 racha a conta e devolve o valor de cada um e a sobra).

A `troca` recebe os endereços `0x1000` e `0x1004`, guarda o 8 em `tmp` e mexe
direto nas gavetas do `main`:

{{ideia}}

As duas versões lado a lado; só a segunda conserta as etiquetas:

```c
#include <stdio.h>

// recebe CÓPIAS: troca as cópias e o main nem fica sabendo
void troca_copias(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// recebe ENDEREÇOS: troca o que está nas gavetas do main
void troca(int *a, int *b) {
    int tmp = *a; // guarda o valor da primeira gaveta
    *a = *b;      // primeira gaveta recebe o da segunda
    *b = tmp;     // segunda gaveta recebe o guardado
}

int main(void) {
    int arroz = 8, feijao = 25; // digitados trocados: o arroz é o mais caro

    troca_copias(arroz, feijao);
    printf("Depois de troca_copias: arroz %d, feijão %d\n", arroz, feijao);

    if (arroz < feijao) {         // o pacote de arroz deveria custar mais
        troca(&arroz, &feijao);   // passa os endereços, não os valores
    }
    printf("Depois de troca:        arroz %d, feijão %d\n", arroz, feijao);
    return 0;
}
// Saída:
// Depois de troca_copias: arroz 8, feijão 25
// Depois de troca:        arroz 25, feijão 8
```

### Passo a passo

Teste de mesa de `troca(&arroz, &feijao)`, com os endereços fictícios do
desenho:

| linha | `a` | `b` | `tmp` | `arroz` (0x1000) | `feijao` (0x1004) |
| --- | --- | --- | --- | --- | --- |
| entrada na função | 0x1000 | 0x1004 | ? | 8 | 25 |
| `tmp = *a` | 0x1000 | 0x1004 | 8 | 8 | 25 |
| `*a = *b` | 0x1000 | 0x1004 | 8 | **25** | 25 |
| `*b = tmp` | 0x1000 | 0x1004 | 8 | 25 | **8** |

`a` e `b` nunca mudam: muda o que está nas gavetas para onde apontam.

O `main` só chama a troca se os preços estão fora de ordem. A troca são três
passos, sempre com a variável auxiliar:

{{fluxograma}}

> [!WARNING]
> Dois erros clássicos. Esquecer o `&` na chamada: `troca(arroz, feijao)` manda
> o número 8 onde se espera um endereço; o compilador avisa (`makes pointer from
> integer without a cast`) e, se rodar, o programa escreve na "gaveta 8" e cai.
> Esquecer o `*` na função: `tmp = a; a = b;` troca os **ponteiros** locais, que
> são cópias, e nada muda lá fora. Quem mexe no dado do chamador é sempre `*a`.

> [!TIP]
> **Por dentro do C:** passar `&arroz` copia 8 bytes, seja qual for o tamanho do
> dado apontado; por isso, no módulo 08, struct grande vai por ponteiro. Quando
> a função só precisa **ler**, use `const int *p`: o compilador recusa `*p = ...`
> lá dentro.

> [!NOTE]
> **Pergunta para você:** o que acontece em `troca(&arroz, &arroz)`? Os dois
> ponteiros apontam para a mesma gaveta. O valor de `arroz` muda?

{{pratique}}
