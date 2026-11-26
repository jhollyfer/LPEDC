## 0138 · Memoização

Você vai subir 35 degraus a pé, de um em um ou de dois em dois. De quantos
jeitos diferentes dá para chegar ao topo? Contar na mão é impossível, e a
pergunta esconde a ideia que guia o módulo inteiro.

Pense no **último passo**. Para pisar no degrau `n`, você veio do degrau
`n - 1`, com um passo simples, ou do `n - 2`, com um passo duplo. Então o
número de jeitos de chegar a `n` é a soma dos jeitos de chegar a cada um
desses dois: `formas(n) = formas(n - 1) + formas(n - 2)`, com `formas(0) =
formas(1) = 1`. É a recorrência de Fibonacci, que você viu no assunto 0033.

Escrita como recursão pura, essa função é **exponencial**. `formas(35)` faz
quase 30 milhões de chamadas, porque `formas(33)` é calculada duas vezes,
`formas(32)` três, e assim por diante, numa avalanche de contas repetidas
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3). E só existem 36 perguntas
diferentes, de `formas(0)` a `formas(35)`. O desperdício é refazer conta
pronta. A saída é **anotar cada resposta na primeira vez e consultar nas
próximas**, como quem cola um lembrete na geladeira.

Essa é a **programação dinâmica** (PD): resolver um problema combinando as
respostas de **subproblemas que se repetem**, calculando cada um uma vez só
(CORMEN et al., 2024, cap. 14). O nome engana. "Programação" aqui não quer
dizer escrever código; quer dizer planejamento, preencher uma tabela, no
sentido antigo da palavra.

A PD exige duas condições do problema. A primeira é a **subestrutura
ótima**: a resposta do problema sai das respostas ótimas de problemas
menores do mesmo tipo (CORMEN et al., 2024, cap. 14). Nos degraus, a resposta
de `n` sai das de `n - 1` e `n - 2`. A segunda é ter **subproblemas
sobrepostos**: os problemas menores **se repetem** ao longo da recursão
(CORMEN et al., 2024, cap. 14). É ela que separa a PD da divisão e conquista
(0131). As metades do merge sort nunca se repetem, e guardar a resposta
delas não economizaria nada.

Há dois jeitos de anotar. Na **memoização** (de *memo*, lembrete), você
mantém a recursão como está e acrescenta um vetor `memo[]`. Antes de
calcular, a função consulta o vetor; se a resposta já está lá, devolve na
hora; se não, calcula, anota e devolve. Ela resolve de **cima para baixo**
(*top-down*): parte do problema grande e desce só até os subproblemas de
que precisa (LINTZMAYER; MOTA, 2023).

```c
long long formas_memo(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];          // já sei: devolve
    memo[n] = formas_memo(n - 1) + formas_memo(n - 2);
    return memo[n];
}
```

O outro jeito é a **tabela**. Você joga a recursão fora e enche um vetor
num laço, do menor subproblema para o maior: `t[0]`, `t[1]`, depois `t[2]`
a partir deles, e assim até `t[n]`. Ela resolve de **baixo para cima**
(*bottom-up*): quando chega a vez de `t[i]`, tudo de que ele depende já está
pronto (CORMEN et al., 2024, cap. 14). O Cormen chama as duas versões de
*top-down with memoization* e *bottom-up method*.

Com as anotações, `formas(35)` cai de 29 860 703 chamadas para 69 na
memoização e 34 voltas de laço na tabela. A conta de custo vale para toda
PD: **número de subproblemas × trabalho de cada um**. Aqui são 35
subproblemas com uma soma cada, O(n), contra o crescimento exponencial da
recursão pura (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).

As duas versões têm o mesmo custo de tempo, mas diferem na pilha. A
memoização ainda é recursiva e empilha um frame por chamada aberta, então
`formas_memo(100000)` estouraria a pilha. A tabela é um laço comum, sem
chamadas (FEOFILOFF, 2009). A memoização ganha quando só uma parte dos
subproblemas é necessária, porque ela calcula só essa parte.

> [!WARNING]
> O valor de "ainda não calculei" deve ser **impossível** como resposta (aqui,
> `-1`). Com `0` e 0 sendo resposta válida, cada célula 0 é recalculada e o
> tempo volta a ser exponencial, com a resposta certa.

{{exemplo}}

Subir 35 degraus de um em um ou de dois em dois: pelo último passo,
`formas(n) = formas(n - 1) + formas(n - 2)`, com `formas(0) = formas(1) = 1`.
Com 5 degraus e memo, as chamadas verdes calculam e anotam, as amarelas acham
a resposta pronta e o cinza deixa de existir:

{{ideia}}

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

De 29.860.703 para 69 chamadas: 35 somas, O(n), contra O(1,6ⁿ) da recursão
pura. No fluxograma, quem já está no memo volta sem chamar ninguém:

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
