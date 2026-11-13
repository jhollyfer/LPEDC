## 0071 · Eficiência: contar passos

- **Eficiência**: o tempo em segundos muda de máquina para máquina; o número de
  **passos** do algoritmo, não (FEOFILOFF, 2009).
- **Operação dominante**: a que domina o trabalho, contada em função de n.
  Numa busca, é a comparação `v[i] == alvo`; o `i++` e o `i < n` andam junto
  com ela (FEOFILOFF, 2009).
- **Melhor, pior e caso médio**: a entrada mais favorável (1 passo), a mais
  desfavorável (n passos) e a média de todas as posições ((n + 1) / 2 passos)
  (ZIVIANI, 2010, cap. 1).
- **Função de custo**: a contagem escrita como fórmula de n; o Ziviani diz
  **função de complexidade**. Aqui, f(n) = n no pior caso
  (ZIVIANI, 2010, cap. 1).
- **Temporal e espacial**: contar passos dá a complexidade temporal; contar
  memória extra, a espacial (assunto 0168) (ZIVIANI, 2010, cap. 1).
- **Por que o pior caso**: só ele permite prometer "nunca passa de n passos". O
  melhor caso é uma situação particular e não serve para análise
  (CELES; RANGEL, 2002).
- **Contador em vez de relógio**: `clock()` engana com entradas pequenas, e com
  `-O2` o `gcc` pode apagar um laço sem uso. O contador dá o mesmo número em
  qualquer máquina.

| comandas (n) | melhor caso | caso médio | pior caso |
| --- | --- | --- | --- |
| 8 | 1 | 4,5 | 8 |
| 800 | 1 | 400,5 | 800 |
| 80.000 | 1 | 40.000,5 | 80.000 |

> [!WARNING]
> Contar a coisa errada engana. Com o `passos++` **depois** do `if` que dá
> `return`, a comparação que acertou fica fora. Sem zerar o contador entre
> buscas, ele acumula. Confira à mão: achar na primeira posição custa 1.

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
