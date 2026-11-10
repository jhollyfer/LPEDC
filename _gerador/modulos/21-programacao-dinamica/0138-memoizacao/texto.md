## 0138 · Memoização

Você vai subir 35 degraus a pé, de um em um ou de dois em dois. De quantos
jeitos dá para chegar ao topo? A pergunta esconde a ideia central deste
módulo.

Pense no **último passo**. Para chegar ao degrau `n`, você veio do `n - 1`
(passo simples) ou do `n - 2` (passo duplo):

`formas(n) = formas(n - 1) + formas(n - 2)`, com `formas(0) = formas(1) = 1`.

É o Fibonacci do assunto 0033: a recursão pura é **exponencial** e faz quase
30 milhões de chamadas para `formas(35)`, porque repete as mesmas contas.
Existem só 36 perguntas diferentes. A saída é **anotar cada resposta na
primeira vez e consultar nas próximas**, de duas formas:

- **memoização** (de *memo*, lembrete): a recursão consulta o vetor `memo[]`
  antes de calcular. Resolve de **cima para baixo**;
- **tabela**: sem recursão, enche um vetor do menor subproblema para o maior.
  Resolve de **baixo para cima**.

As duas são **programação dinâmica** (PD): combinar respostas de
**subproblemas que se repetem**, cada um calculado uma vez. "Programação"
aqui quer dizer planejamento numa tabela.

A PD exige duas condições: a resposta sai das respostas **ótimas** de
problemas menores do mesmo tipo (**subestrutura ótima**), e esses problemas
**se repetem** (**subproblemas sobrepostos**). Nas metades do merge sort, que
não se repetem, guardar não ajuda. O Cormen chama as versões de
*top-down with memoization* e *bottom-up method*.

Com 5 degraus, a recursão pura faria 15 chamadas. Com o memo, as verdes
calculam e anotam, as amarelas acham a resposta pronta e o cinza deixa de
existir:

{{ideia}}

O código mede as três versões para 35 degraus:

```c
#include <stdio.h>

#define MAX 50

long long chamadas = 0; // conta quantas vezes a função foi chamada

// recursão pura: formas de subir n degraus, de 1 em 1 ou de 2 em 2
long long formas_rec(int n) {
    chamadas++;
    if (n <= 1) {
        return 1;                       // 0 ou 1 degrau: um jeito só
    }
    return formas_rec(n - 1) + formas_rec(n - 2);
}

long long memo[MAX + 1];                // memo[n] == -1: ainda não sei

// de cima para baixo: a mesma recursão, consultando o memo antes
long long formas_memo(int n) {
    chamadas++;
    if (n <= 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];                 // já calculei: só consulta
    }
    memo[n] = formas_memo(n - 1) + formas_memo(n - 2);
    return memo[n];
}

// de baixo para cima: enche a tabela do menor para o maior
long long formas_tabela(int n) {
    long long t[MAX + 1];
    t[0] = 1;
    t[1] = 1;
    for (int i = 2; i <= n; i++) {
        t[i] = t[i - 1] + t[i - 2];     // os dois já estão prontos
    }
    return t[n];
}

int main(void) {
    int degraus = 35;

    chamadas = 0;
    long long r = formas_rec(degraus);
    printf("recursão pura: %lld formas, %lld chamadas\n", r, chamadas);

    for (int i = 0; i <= MAX; i++) {
        memo[i] = -1;
    }
    chamadas = 0;
    r = formas_memo(degraus);
    printf("memoização:    %lld formas, %lld chamadas\n", r, chamadas);

    r = formas_tabela(degraus);
    printf("tabela:        %lld formas, %d voltas no laço\n", r, degraus - 1);
    return 0;
}
// Saída:
// recursão pura: 14930352 formas, 29860703 chamadas
// memoização:    14930352 formas, 69 chamadas
// tabela:        14930352 formas, 34 voltas no laço
```

De 29.860.703 para 69 chamadas. O custo de toda PD é **número de
subproblemas × trabalho de cada um**: aqui, 35 somas, O(n), contra O(1,6ⁿ)
da recursão pura.

No fluxograma, a diferença é o losango do meio: quem já está no memo volta
sem chamar ninguém.

{{fluxograma}}

### Passo a passo

Versão de baixo para cima, para 5 degraus. Cada linha usa as duas anteriores:

| i | t[i - 2] | t[i - 1] | t[i] |
| --- | --- | --- | --- |
| 0 | | | 1 (base) |
| 1 | | | 1 (base) |
| 2 | 1 | 1 | 2 |
| 3 | 1 | 2 | 3 |
| 4 | 2 | 3 | 5 |
| 5 | 3 | 5 | 8 |

São 8 jeitos: 11111, 2111, 1211, 1121, 1112, 221, 212, 122.

> [!WARNING]
> O valor de "ainda não calculei" deve ser **impossível** como resposta (aqui,
> `-1`). Com `0` e 0 sendo resposta válida, a resposta sai certa, mas cada
> célula 0 é recalculada e o tempo volta a ser exponencial.

> [!TIP]
> **Por dentro do C:** a memoização empilha um frame por chamada
> (`formas_memo(100000)` estouraria a pilha). A tabela é um laço, sem
> chamadas.

> [!NOTE]
> **Pergunta para você:** a tabela guarda 36 valores, mas cada `t[i]` só
> olha os dois anteriores. Quanta memória a versão de baixo para cima
> precisa de verdade? Pense antes de abrir o A276.

{{pratique}}
