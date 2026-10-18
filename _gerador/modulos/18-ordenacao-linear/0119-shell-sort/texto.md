## 0119 · Shell sort

O motorista da van de entregas recebe 10 pacotes jogados no banco de trás, com
os números de rota 62, 17, 85, 40, 9, 73, 28, 51, 94 e 33. Ele quer os
pacotes em ordem de rota. Se fizer como no insertion sort, pegando um por vez
e escorregando para a esquerda casa a casa, o pacote 9, que está na quinta
posição, vai precisar de quatro empurrões para chegar na frente.

Esse é o ponto fraco do **insertion sort** (assunto 0093): cada movimento
anda **uma casa só**. Um elemento que está longe do lugar certo paga uma
comparação e um deslocamento por casa que atravessa. Num vetor invertido, a
conta vira n²/2.

Em 1959, Donald Shell teve uma ideia simples: antes de andar de uma em uma
casa, ande de **h em h**. O **shell sort** faz o insertion sort várias vezes,
com saltos `h` cada vez menores:

1. com um salto grande, os elementos dão pulos longos e chegam **perto** do
   lugar certo;
2. com saltos menores, o vetor fica cada vez mais arrumado;
3. a última rodada é sempre com `h = 1`: o insertion sort comum, só que sobre
   um vetor **quase ordenado**, que é exatamente o caso em que ele é rápido.

Depois da rodada com salto `h`, o vetor está **h-ordenado**: se você pegar
um elemento a cada `h` casas, a partir de qualquer posição, essa fileira está
em ordem. Com `h = 4`, as posições 0, 4, 8 formam uma fileira; 1, 5, 9
formam outra; 2, 6 e 3, 7 formam mais duas. São quatro insertion sorts
pequenos, entrelaçados no mesmo vetor.

Quais saltos usar? A sequência mais conhecida é a de **Knuth**: `h = 3h + 1`,
ou seja, 1, 4, 13, 40, 121, 364... Você começa com o maior salto abaixo de
`n / 3` e vai dividindo por 3. Com `n = 10`, os saltos são só 4 e 1.

Vamos ver na prática. Na primeira linha, cada cor é uma fileira de salto 4.
Cada fileira se ordena sozinha: o 9 troca com o 62, o 33 com o 73 e o 28 com
o 85. Três movimentos e o vetor já está quase pronto:

{{ideia}}

O mesmo exemplo em C. O laço de dentro é o insertion sort do assunto 0093
com o `1` trocado por `h`:

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
}

// insertion sort com saltos: os saltos seguem a sequência de Knuth
void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;                  // 1, 4, 13, 40, 121...
    }
    for (; h >= 1; h /= 3) {            // ..., 121, 40, 13, 4, 1
        int movimentos = 0;
        // insertion sort entre elementos que estão a h casas de distância
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];        // empurra h casas para a direita
                j -= h;
                movimentos++;
            }
            v[j] = x;
        }
        printf("h = %d:", h);
        mostra(v, n);
        printf("  (%d movimentos)\n", movimentos);
    }
}

int main(void) {
    int rotas[] = {62, 17, 85, 40, 9, 73, 28, 51, 94, 33};
    int n = 10;

    printf("início:");
    mostra(rotas, n);
    printf("\n");
    shell_sort(rotas, n);
    return 0;
}
// Saída:
// início: 62 17 85 40 9 73 28 51 94 33
// h = 4: 9 17 28 40 62 33 85 51 94 73  (3 movimentos)
// h = 1: 9 17 28 33 40 51 62 73 85 94  (6 movimentos)
```

São 9 movimentos no total. O insertion sort comum, no mesmo vetor, faz 21:
o 9, sozinho, gastaria 4. No shell sort ele deu **um** pulo de 4 casas.

Repare que `h /= 3` desfaz a conta `3 * h + 1`: na divisão inteira, 13 / 3 é
4 e 4 / 3 é 1. O laço de fora para quando `h` vira 0. Repara no fluxograma:
primeiro o programa sobe até o maior salto, depois desce rodada por rodada,
e a última rodada é sempre a do `h = 1`:

{{fluxograma}}

### Passo a passo

A rodada com `h = 4`. O `i` anda de 4 até 9, e cada `v[i]` só se compara com
quem está 4, 8, ... casas para trás:

| i | x | compara com | ação | vetor depois |
| --- | --- | --- | --- | --- |
| 4 | 9 | v[0] = 62 | 62 pula para v[4]; 9 vai para v[0] | 9 17 85 40 62 73 28 51 94 33 |
| 5 | 73 | v[1] = 17 | nada | 9 17 85 40 62 73 28 51 94 33 |
| 6 | 28 | v[2] = 85 | 85 pula para v[6]; 28 vai para v[2] | 9 17 28 40 62 73 85 51 94 33 |
| 7 | 51 | v[3] = 40 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 8 | 94 | v[4] = 62 | nada | 9 17 28 40 62 73 85 51 94 33 |
| 9 | 33 | v[5] = 73, depois v[1] = 17 | 73 pula para v[9]; 33 vai para v[5] | 9 17 28 40 62 33 85 51 94 73 |

> [!WARNING]
> A última rodada **tem** que ser com `h = 1`. As rodadas com salto grande só
> garantem que cada fileira está em ordem, não o vetor todo: depois do
> `h = 4`, o 62 ainda está antes do 33. Se você inventar sua própria
> sequência (5, 3, 2, por exemplo) e esquecer do 1, o programa termina sem
> erro nenhum e com o vetor fora de ordem. Outro tropeço: escrever a
> condição como `j > 0` (a do insertion sort comum). Com salto `h`, o certo é
> `j >= h`, senão `v[j - h]` lê antes do começo do vetor.

> [!TIP]
> **Por dentro do C:** o shell sort não usa memória extra nenhuma: só `h`,
> `i`, `j` e `x`, umas poucas variáveis na pilha, qualquer que seja o tamanho
> do vetor. É por isso que ele aparece em sistemas embarcados e no código de
> bibliotecas pequenas (a uClibc, por exemplo, implementa o `qsort` com shell
> sort). O custo depende dos saltos, e ninguém sabe a fórmula exata para a
> maioria das sequências: com a de Knuth, o pior caso é O(n^1,5), e na
> prática fica perto de n^1,25. Já os saltos `n/2, n/4, ..., 1` (os de Shell)
> têm pior caso O(n²): como todos são pares menos o último, posições pares e
> ímpares só se comparam na rodada final.

> [!NOTE]
> **Pergunta para você:** o shell sort é estável? Pense em `5 3a 3b 1` (dois
> 3 iguais, o `a` antes do `b`) com saltos 2 e 1. Faça as duas rodadas no
> papel e veja em que ordem os dois 3 terminam.

{{pratique}}
