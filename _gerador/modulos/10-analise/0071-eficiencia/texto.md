## 0071 · Eficiência: contar passos

Até aqui a pergunta sobre um programa era "ele está **certo**?". A partir de
agora entra outra: "ele é **rápido** o bastante?". Dois programas certos
podem resolver o mesmo problema, um em um instante e o outro em horas. Para
escolher entre eles, você precisa de um jeito de medir o custo que não dependa
da sorte nem do computador.

Sexta à noite, padaria cheia. Você entrega a comanda 70 e a atendente procura
no bolo de comandas, uma por uma. Se a sua for a primeira, você sai na hora;
se for a última, espera o bolo inteiro. Com 8 comandas, tanto faz. Com 800,
faz diferença. O que pesa aqui é quantas comandas ela olha, e não a
velocidade das mãos dela.

Com programas é igual. Medir em segundos não funciona, porque o mesmo código
leva 2 ms num notebook, 9 ms num Raspberry Pi e 40 ms num computador ocupado
com outras tarefas. O que não muda de máquina é **quantos passos** o
algoritmo dá. A **eficiência** de um algoritmo se avalia por essa contagem de
passos, e não pelo relógio (FEOFILOFF, 2009).

Contar cada instrução seria trabalhoso e pouco útil. Em vez disso, escolha a
**operação dominante**, aquela que se repete mais e resume o trabalho, e conte
quantas vezes ela acontece em função de n, o tamanho da entrada. Numa busca
num vetor, a operação dominante é a comparação `v[i] == alvo`. O `i++` e o
`i < n` acontecem junto com ela, uma vez por volta, e contá-los mudaria o
total por um fator fixo, não a ideia de custo (FEOFILOFF, 2009).

A contagem depende de qual entrada chega, e não só do tamanho. No bolo de 8
comandas, procurar a que está em cima custa 1 comparação; procurar a de baixo,
ou uma que nem está lá, custa 8. Daí saem três casos (ZIVIANI, 2010, cap. 1).
O **melhor caso** é a entrada mais favorável, e custa 1 passo. O **pior
caso** é a mais desfavorável, e custa n passos. O **caso médio** é a média
sobre todas as posições possíveis: se a comanda está no bolo e qualquer
posição é igualmente provável, a busca faz em média (n + 1) / 2 comparações.

Escrita como fórmula de n, a contagem se chama **função de custo**; o
Ziviani usa o nome **função de complexidade**. Para a busca, f(n) = n no
pior caso (ZIVIANI, 2010, cap. 1). Contar passos dá a **complexidade
temporal**, que fala de tempo. Contar quanta memória extra o algoritmo usa dá
a **complexidade espacial**, assunto do 0168 (ZIVIANI, 2010, cap. 1).

Entre os três casos, a análise costuma olhar o pior. Só ele permite fazer uma
promessa: "esta busca nunca passa de n comparações, qualquer que seja a
entrada". O melhor caso é uma situação particular e não garante nada, como
dizer que uma avenida nunca tem trânsito porque às 4 da manhã ela estava
livre (CELES; RANGEL, 2002). A tabela mostra como os casos crescem com n:

| comandas (n) | melhor caso | caso médio | pior caso |
| --- | --- | --- | --- |
| 8 | 1 | 4,5 | 8 |
| 800 | 1 | 400,5 | 800 |
| 80.000 | 1 | 40.000,5 | 80.000 |

Multiplicou n por 100, o pior caso também multiplicou por 100. O assunto
0072 parte dessa observação.

Para estudar o custo na prática, use um **contador**: uma variável somada a
cada execução da operação dominante, e mostrada no fim. Medir com `clock()`
engana quando a entrada é pequena, porque o ruído do sistema passa do tempo
medido. E com a otimização `-O2`, o `gcc` pode apagar um laço cujo resultado
ninguém usa. O contador, impresso no `printf`, mantém o laço vivo e dá o
mesmo número em qualquer máquina.

> [!WARNING]
> Contar a coisa errada engana. Com o `passos++` **depois** do `if` que dá
> `return`, a comparação que acertou fica fora e achar na primeira posição
> aparece com 0 passos. Sem zerar o contador entre buscas, ele acumula.
> Confira o caso mais simples à mão: achar na primeira posição custa 1.

{{exemplo}}

Na padaria, a moça procura sua comanda no bolo, uma por uma. A comanda 70 está
na posição 6: a busca erra as 6 primeiras e acerta na 7ª comparação. A 41 sai
em 1 passo; a 99, que não está no bolo, custa as 8:

{{ideia}}

O contador é uma variável global somada a cada comparação, só para estudar o
custo.

```c
#include <stdio.h>

int passos = 0; // conta as comparações: a operação que domina o custo

// Devolve o índice de alvo em v[0..n-1], ou -1 se ele não estiver lá.
int busca(const int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        passos++; // vai comparar v[i] com o alvo
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int comandas[8] = {41, 17, 88, 23, 56, 9, 70, 35};
    int alvos[3] = {41, 70, 99};

    for (int k = 0; k < 3; k++) {
        passos = 0; // zera antes de cada busca
        int pos = busca(comandas, 8, alvos[k]);
        printf("comanda %d: posição %2d, passos: %d\n", alvos[k], pos, passos);
    }
    return 0;
}
// Saída:
// comanda 41: posição  0, passos: 1
// comanda 70: posição  6, passos: 7
// comanda 99: posição -1, passos: 8
```

O laço tem duas saídas: "achou?" responde Sim, ou as comandas acabam. Cada
volta pelo losango de baixo soma um passo:

{{fluxograma}}
