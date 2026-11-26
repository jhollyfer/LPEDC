## 0092 · Selection sort

Final da bateria de kart: os tempos da melhor volta, em segundos, foram 58, 31,
47, 19 e 26. Para montar o pódio, ninguém compara vizinhos como no bubble
sort do 0091. Você procura o **menor** tempo, que é o primeiro lugar. Depois
procura o menor entre os que **sobraram**, que é o segundo lugar, e segue até
acabarem os pilotos.

Esse é o **selection sort** (ordenação por seleção): escolher o menor, depois
o segundo menor, e assim por diante (FEOFILOFF, 2009). O vetor fica dividido
em duas partes. À esquerda está a parte **pronta**, com os menores já na
posição final. À direita está o resto, ainda fora de ordem. Cada passada
aumenta a parte pronta em uma gaveta.

A passada `i` faz duas coisas. Primeiro procura o **índice** do menor
elemento em `v[i..n-1]`, a parte que ainda não está pronta. Depois troca esse
menor com `v[i]`. A partir daí a gaveta `i` nunca mais muda, porque ela já
tem o valor que deve ter no fim (FEOFILOFF, 2009). Na primeira passada dos
tempos do kart, o menor é o 19, na gaveta 3, e ele troca de lugar com o 58 da
gaveta 0.

Repare que a busca guarda o **índice** do menor, e não o valor. É o padrão
"maior/menor" do assunto 0025 com um detalhe a mais: para trocar no fim da
passada, você precisa saber **onde** o menor está. Guardar só o valor 19
responderia qual é o menor, mas não diria qual gaveta trocar.

O custo em comparações não depende da entrada. Achar o menor exige olhar
todos os que sobraram, e nenhum atalho diz que o menor já foi visto. Assim, o
método faz `n(n - 1)/2` comparações em **todos** os casos, mesmo com o vetor
já em ordem: **O(n²)** (ZIVIANI, 2010, cap. 4). A vantagem está nas
**trocas**: no máximo uma por passada, `n - 1` no total, contra até
`n(n - 1)/2` do bubble sort. Isso pesa quando mover um elemento custa caro,
como num vetor de `struct` grandes.

Um método de ordenação é **estável** quando elementos com chaves iguais saem
na mesma ordem relativa em que entraram. Se dois pilotos fizeram 31 segundos e
a Ana aparecia antes do Bruno, um método estável mantém Ana antes de Bruno. O
selection sort é **instável**, porque a troca é de longa distância: o 19
salta da gaveta 3 para a 0 e manda o 58 para a gaveta 3, por cima de quem
estiver no meio. Um elemento igual a outro pode pular para trás dele nessa
viagem (FEOFILOFF, 2009).

O método também ordena **in-place**, isto é, dentro do próprio vetor, sem
precisar de um segundo vetor: além dele, só usa algumas variáveis, e a memória
extra é **O(1)** (FEOFILOFF, 2009).

> [!WARNING]
> Trocar **dentro** do laço que procura o menor ordena, mas perde a vantagem
> das poucas trocas. Esquecer de reiniciar `menor = i` a cada passada faz
> `menor` apontar para a parte pronta.

{{exemplo}}

Os tempos da melhor volta numa bateria de kart, em segundos: 58, 31, 47, 19 e
26. Cada linha é uma passada: a gaveta roxa é a posição `i`, a amarela é o
menor achado; depois da troca, a gaveta vira verde e fica:

{{ideia}}

Em C:

```c
#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");
}

void selection_sort(int v[], int n) {
    int comparacoes = 0, trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;                    // índice do menor de v[i..n-1]
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {                 // uma troca só por passada
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            trocas++;
        }
        printf("i = %d:  ", i);
        mostra(v, n);
    }
    printf("%d comparações, %d trocas\n", comparacoes, trocas);
}

int main(void) {
    int tempos[] = {58, 31, 47, 19, 26}; // segundos por volta
    int n = 5;

    printf("início: ");
    mostra(tempos, n);
    selection_sort(tempos, n);
    return 0;
}
// Saída:
// início:  58 31 47 19 26
// i = 0:   19 31 47 58 26
// i = 1:   19 26 47 58 31
// i = 2:   19 26 31 58 47
// i = 3:   19 26 31 47 58
// 10 comparações, 4 trocas
```

### Passo a passo

A passada `i = 0`. O `menor` começa na gaveta 0:

| j | v[j] | v[menor] antes | `v[j] < v[menor]`? | menor |
| --- | --- | --- | --- | --- |
| | | | | 0 (58) |
| 1 | 31 | 58 | sim | 1 (31) |
| 2 | 47 | 31 | não | 1 |
| 3 | 19 | 31 | sim | 3 (19) |
| 4 | 26 | 19 | não | 3 |

Fim da passada: troca `v[0]` (58) com `v[3]` (19). As passadas seguintes
fazem 3, 2 e 1 comparações: 10 no total.

A caixa "acha o menor" esconde um laço inteiro (a tabela); a troca fica
**fora** dele:

{{fluxograma}}
