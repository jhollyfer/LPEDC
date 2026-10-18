## 0138 · Memoização

A escada rolante da estação quebrou e você vai subir os 35 degraus a pé. Dá
para subir de um em um ou pular de dois em dois. De quantos jeitos diferentes
dá para chegar lá em cima? A pergunta parece de almanaque, mas ela esconde a
ideia mais poderosa deste módulo.

Pense no **último passo**. Para chegar no degrau `n`, você veio do degrau
`n - 1` (passo simples) ou do `n - 2` (passo duplo). Então:

`formas(n) = formas(n - 1) + formas(n - 2)`, com `formas(0) = formas(1) = 1`.

É a recursão de Fibonacci do assunto 0033, e lá você viu o problema: a
recursão pura é **exponencial**. Para `formas(35)`, ela faz quase 30 milhões
de chamadas. Não porque o problema é difícil, mas porque ela calcula as
**mesmas** coisas de novo e de novo. `formas(33)` é calculado 2 vezes,
`formas(32)` 3 vezes, `formas(31)` 5 vezes...

Só existem 36 perguntas diferentes (`formas(0)` até `formas(35)`). A saída é
óbvia depois que alguém fala: **anote cada resposta na primeira vez e consulte
nas próximas**. Isso tem nome:

- **memoização** (de *memo*, lembrete): a recursão continua igual, mas antes
  de calcular ela olha num vetor `memo[]` se a resposta já está lá. Resolve de
  **cima para baixo**: começa pela pergunta grande e desce até as pequenas;
- **tabela** (de **baixo para cima**): esquece a recursão e enche um vetor do
  menor subproblema para o maior. Quando chega em `t[i]`, os valores de que
  ele depende já estão prontos.

As duas são **programação dinâmica** (PD): resolver um problema combinando
respostas de **subproblemas que se repetem**, cada um calculado uma vez só. O
nome é antigo e não tem nada a ver com memória dinâmica: "programação" aqui
quer dizer "planejamento numa tabela".

Para a PD funcionar, duas coisas precisam ser verdade. A resposta do problema
tem que sair das respostas de problemas menores do mesmo tipo (a recorrência).
E esses problemas menores têm que **se repetir**; se cada um aparece uma vez
só, como nas metades do merge sort, guardar não adianta nada.

Vamos ver na prática. Com 5 degraus, a recursão pura faria as 15 chamadas da
árvore. Com o memo, só as coloridas acontecem: as verdes calculam e anotam,
as amarelas encontram a resposta pronta e voltam na hora. Tudo que está cinza
deixa de existir:

{{ideia}}

O código mede as três versões para os 35 degraus da estação:

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

De 29.860.703 para 69 chamadas, com a mesma recursão e três linhas a mais. A
conta do custo de qualquer PD é sempre esta: **número de subproblemas ×
trabalho de cada um**. Aqui são uns 35 subproblemas, cada um com uma soma:
O(n), contra O(1,6ⁿ) da recursão pura.

Repara no fluxograma: a única diferença para a recursão pura é o losango do
meio. Ele corta a árvore: quem já está no memo volta sem chamar ninguém:

{{fluxograma}}

### Passo a passo

A versão de baixo para cima, para os 5 degraus do desenho. Cada linha usa as
duas anteriores:

| i | t[i - 2] | t[i - 1] | t[i] |
| --- | --- | --- | --- |
| 0 | | | 1 (base) |
| 1 | | | 1 (base) |
| 2 | 1 | 1 | 2 |
| 3 | 1 | 2 | 3 |
| 4 | 2 | 3 | 5 |
| 5 | 3 | 5 | 8 |

São 8 jeitos de subir 5 degraus. Confira à mão: 11111, 2111, 1211, 1121,
1112, 221, 212, 122.

> [!WARNING]
> O valor que marca "ainda não calculei" precisa ser **impossível** como
> resposta. Aqui, `-1` serve porque nenhuma contagem é negativa. O erro comum
> é inicializar o memo com `0` (o que um vetor global já tem de graça) num
> problema em que 0 é resposta válida, como "quantos caminhos chegam aqui"
> numa grade com obstáculos. O programa continua dando a resposta certa, mas
> toda célula que vale 0 é recalculada a cada visita, e o tempo volta a ser
> exponencial sem nenhum aviso.

> [!TIP]
> **Por dentro do C:** as duas versões de PD fazem as mesmas contas, mas
> custam diferente para a máquina. A memoização ainda empilha um frame por
> chamada: `formas_memo(35)` desce 35 níveis na pilha antes de anotar a
> primeira resposta, e `formas_memo(100000)` estouraria a pilha. A tabela é um
> laço sobre um vetor contíguo, sem chamada nenhuma, que o cache do processador
> adora. Em troca, a memoização só calcula os subproblemas que a pergunta
> realmente usa, o que vale ouro quando eles são poucos dentro de uma tabela
> enorme.

> [!NOTE]
> **Pergunta para você:** a tabela guarda 36 valores, mas cada `t[i]` só
> olha para os dois anteriores. Quanta memória a versão de baixo para cima
> precisa de verdade? Pense antes de abrir o A276.

{{pratique}}
