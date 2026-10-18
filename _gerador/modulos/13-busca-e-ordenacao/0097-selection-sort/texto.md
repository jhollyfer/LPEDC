## 0097 · Selection sort

Final da bateria de kart com os amigos. Os tempos da melhor volta, em
segundos, foram 58, 31, 47, 19 e 26. Para montar o pódio, você faz o óbvio:
procura o **menor** tempo e chama o primeiro lugar. Depois procura o menor
entre os que **sobraram** e chama o segundo. E assim por diante.

Isso é o **selection sort** (ordenação por seleção). O vetor fica dividido em
duas partes: à esquerda, a parte **pronta** (os menores, já na ordem final);
à direita, o resto. Cada passada `i`:

1. procura o **índice** do menor elemento em `v[i..n-1]`;
2. troca esse menor com `v[i]`. Pronto: a gaveta `i` nunca mais muda.

Repare que a passada guarda o **índice** do menor, não o valor. É o índice
que permite fazer a troca no fim. É a mesma ideia do padrão "maior/menor" do
assunto 0030, rodando de novo a cada passada.

Custo: a passada 0 compara `n - 1` vezes, a 1 compara `n - 2` vezes... No
total, `n(n - 1)/2` comparações, **sempre**. Vetor bagunçado, ordenado ou ao
contrário, tanto faz: para saber qual é o menor, é preciso olhar todos os que
sobraram. Então é **O(n²)** em todos os casos.

A vantagem está nas **trocas**: no máximo **uma por passada**, ou seja, no
máximo `n - 1`. O bubble pode fazer `n(n - 1)/2`. Quando mover um elemento é
caro (structs grandes, um registro inteiro), isso pesa.

Vamos ver na prática. Em cada linha, a gaveta roxa é a posição `i` que vai
receber o menor, e a amarela é o menor que a passada achou. Depois da troca,
a gaveta vira verde e não sai mais do lugar:

{{ideia}}

O mesmo exemplo em C:

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

A passada `i = 0` por dentro. O `menor` começa apontando para a gaveta 0 e
vai sendo atualizado:

| j | v[j] | v[menor] antes | `v[j] < v[menor]`? | menor |
| --- | --- | --- | --- | --- |
| | | | | 0 (58) |
| 1 | 31 | 58 | sim | 1 (31) |
| 2 | 47 | 31 | não | 1 |
| 3 | 19 | 31 | sim | 3 (19) |
| 4 | 26 | 19 | não | 3 |

Fim da passada: troca `v[0]` (58) com `v[3]` (19). Quatro comparações, uma
troca. As passadas seguintes fazem 3, 2 e 1 comparações: 10 no total.

Repara no fluxograma: a caixa "acha o menor" esconde um laço inteiro (a
tabela acima). A troca acontece **fora** dele, uma vez por passada:

{{fluxograma}}

> [!WARNING]
> O erro mais comum é trocar **dentro** do laço que procura o menor: toda vez
> que acha alguém menor, já troca. O vetor até sai ordenado, mas você perdeu a
> única vantagem do algoritmo e passou a fazer trocas como o bubble. Outro
> clássico: esquecer de reiniciar `menor = i` a cada passada. Aí `menor`
> continua apontando para uma gaveta da parte pronta, e a troca bagunça o que
> já estava certo.

> [!TIP]
> **Por dentro do C:** a troca do selection é de **longa distância**: o 19
> salta da gaveta 3 para a 0 de uma vez, e o 58 vai para a 3 passando por cima
> do 31 e do 47. Esse salto é o que torna o selection **instável**: dois
> elementos iguais podem trocar de ordem entre si (o exemplo A194 mostra a
> Bia passando na frente da Ana). Já em custo de memória ele é ótimo: ordena
> no próprio vetor, com uma variável `aux` e dois índices. Isso se chama
> ordenar **in-place**, com **O(1)** de memória extra.

> [!NOTE]
> **Pergunta para você:** quantas comparações e quantas trocas o selection faz
> no vetor `19 26 31 47 58`, que já está ordenado? E o bubble com bandeira, do
> assunto anterior? Responda antes de rodar.

{{pratique}}
