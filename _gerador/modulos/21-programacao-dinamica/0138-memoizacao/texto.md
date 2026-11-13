## 0138 · Memoização

- **Programação dinâmica** (PD): combina respostas de **subproblemas que se
  repetem**, calculando cada um uma vez só. "Programação" quer dizer
  planejamento numa tabela (CORMEN et al., 2024, cap. 14).
- **Subestrutura ótima**: a resposta sai das respostas ótimas de problemas
  menores do mesmo tipo (CORMEN et al., 2024, cap. 14).
- **Subproblemas sobrepostos**: os problemas menores **se repetem**. Nas
  metades do merge sort, que não se repetem, guardar não ajuda
  (CORMEN et al., 2024, cap. 14).
- **Memoização** (de *memo*, lembrete): a recursão consulta um vetor `memo[]`
  antes de calcular. Resolve de **cima para baixo** (*top-down*)
  (LINTZMAYER; MOTA, 2023).
- **Tabela**: sem recursão, enche um vetor do menor subproblema para o maior.
  Resolve de **baixo para cima** (*bottom-up*) (CORMEN et al., 2024, cap. 14).
- **Custo de uma PD**: número de subproblemas × trabalho de cada um. O
  Fibonacci recursivo puro é exponencial; com tabela, O(n)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).
- **Pilha**: a memoização empilha um frame por chamada; a tabela é só um laço
  (FEOFILOFF, 2009).

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
