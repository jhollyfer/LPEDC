## 0042 · Vetores

O relógio da academia contou seus passos durante a semana: 8200 no domingo,
10450 na segunda, e assim por diante. Para somar, achar a média e o recorde,
você criaria `passos_dom`, `passos_seg`, `passos_ter`... sete variáveis, sete
somas na mão. E se fosse o mês inteiro? Trinta variáveis. O ano? Não dá.

O **vetor** (ou *array*) resolve isso: **várias variáveis do mesmo tipo, com um
nome só**, lado a lado na memória. Cada uma é acessada por um número, o
**índice**, entre colchetes: `passos[0]`, `passos[1]`, ..., `passos[6]`.

```c
int passos[7];                 // 7 gavetas de int, com lixo dentro
int notas[4] = {7, 9, 6, 10};  // declara e inicializa
int zeros[100] = {0};          // a 1ª vira 0 e as outras também
int dias[] = {31, 28, 31};     // sem tamanho: o compilador conta (3)
```

Três regras que pegam quem vem do JS:

- **O índice começa em 0** e vai até `tamanho - 1`. Num vetor de 7, o último é
  `passos[6]`. O "sétimo elemento" é `passos[6]`; `passos[7]` não existe.
- **O tamanho é fixo.** No JS o array cresce com `push`. No C, o tamanho é
  decidido na declaração e nunca muda. Use um `#define` para ele: muda num
  lugar só e o laço acompanha.
- **Vetor não tem `.length`.** Quem sabe o tamanho é você. Dentro do bloco onde
  ele foi declarado, `sizeof(v) / sizeof(v[0])` dá a conta (bytes do vetor
  divididos pelos bytes de um item).

Cada posição é uma variável comum: entra em conta, em `if`, em `scanf("%d",
&notas[i])`. E o índice pode ser qualquer expressão inteira: `v[i + 1]`,
`v[n - 1]`, `v[i % 7]`. É isso que casa o vetor com o `for`: o contador do laço
vira o índice.

Duas coisas que **não** funcionam: atribuir um vetor inteiro (`copia = passos;`
nem compila) e inicializar com chaves depois da declaração (`passos = {1, 2};`
também não). Vetor se copia gaveta por gaveta, num laço.

Vamos ver na prática. São 7 gavetas, uma por dia. O laço passa por todas
somando e guardando a maior. O recorde está na gaveta 5, que é o **dia 6** para
quem lê o relatório:

{{ideia}}

O código percorre as gavetas com `i` de 0 a 6. Repare que o `maior` começa com
`passos[0]`, e não com 0:

```c
#include <stdio.h>

#define DIAS 7

int main(void) {
    // 7 gavetas de int, uma por dia; o índice vai de 0 a 6
    int passos[DIAS] = {8200, 10450, 6300, 12000, 9100, 15300, 7400};

    int total = 0;
    int maior = passos[0]; // começa pelo primeiro, não por 0
    int dia_maior = 0;

    for (int i = 0; i < DIAS; i++) { // i < DIAS: o último índice é 6
        total += passos[i];
        if (passos[i] > maior) {
            maior = passos[i];
            dia_maior = i;
        }
    }

    printf("Total: %d passos\n", total);
    printf("Média: %.1f por dia\n", (double) total / DIAS);
    printf("Recorde: %d passos no dia %d\n", maior, dia_maior + 1);
    return 0;
}
// Saída:
// Total: 68750 passos
// Média: 9821.4 por dia
// Recorde: 15300 passos no dia 6
```

Repara no fluxograma: é o padrão acumulador e o padrão maior/menor do assunto
0030, só que agora os valores vêm das gavetas do vetor, e não do teclado. A
pergunta `i < 7?` é o que impede o laço de passar da última gaveta:

{{fluxograma}}

> [!WARNING]
> **O C não confere o índice.** Com `int v[7]`, escrever `v[7] = 0` ou ler
> `v[-1]` compila sem erro e mexe na memória vizinha, que pode ser outra
> variável sua. É **comportamento indefinido**: às vezes nada acontece, às
> vezes outro valor muda "sozinho", às vezes o programa cai. O erro clássico é o
> `<=` no laço: `for (i = 0; i <= 7; i++)` passa uma vez a mais. No JS,
> `arr[99]` devolve `undefined`; no C, devolve o que estiver lá. O `rodar` usa
> o AddressSanitizer, que pega esse erro e mostra `stack-buffer-overflow`.

> [!TIP]
> **Por dentro do C:** as 7 gavetas são 28 bytes seguidos na memória (7 × 4
> bytes). O nome `passos` marca onde o vetor começa, e o índice diz **quantos
> itens pular**: `passos[5]` fica em início + 5 × 4 bytes. Por isso o primeiro
> é o 0 (pula zero itens) e por isso acessar qualquer posição custa o mesmo,
> seja a 0 ou a 999: é uma conta, não uma busca. E por isso o C não confere o
> limite: ele só faz a conta e vai até lá. Vetor local sem inicializar tem lixo,
> igual a qualquer variável local.

> [!NOTE]
> **Pergunta para você:** se o `maior` começasse com 0 e os valores fossem
> temperaturas de inverno em Urupema (`{-3, -5, -1, -4}`), qual seria o
> "maior" mostrado? Por que começar por `v[0]` resolve?

{{pratique}}
