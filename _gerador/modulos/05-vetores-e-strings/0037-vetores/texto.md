## 0037 · Vetores

O relógio da academia contou seus passos na semana: 8200 no domingo, 10450 na
segunda, e assim por diante. Para somar e achar a média e o recorde, você
criaria `passos_dom`, `passos_seg`... sete variáveis. No mês, trinta. No ano,
inviável.

O **vetor** (*array*) resolve: **várias variáveis do mesmo tipo, com um nome
só**, lado a lado na memória. Cada uma é acessada pelo **índice**, entre
colchetes: `passos[0]`, `passos[1]`, ..., `passos[6]`. É um dado composto
**homogêneo** (itens do mesmo tipo); a struct do módulo 08, o **registro**, é o
heterogêneo.

```c
int passos[7];                 // 7 gavetas de int, com lixo dentro
int notas[4] = {7, 9, 6, 10};  // declara e inicializa
int zeros[100] = {0};          // a 1ª vira 0 e as outras também
int dias[] = {31, 28, 31};     // sem tamanho: o compilador conta (3)
```

Três regras que pegam todo iniciante:

- **O índice começa em 0** e vai até `tamanho - 1`. Num vetor de 7, o último é
  `passos[6]`; `passos[7]` não existe.
- **O tamanho é fixo**, decidido na declaração. Use um `#define`: muda num
  lugar só e o laço acompanha. (Desde o C99 o tamanho pode vir de uma
  variável, `int v[n];`, o **VLA** do assunto 0172, mas também não cresce.)
- **Vetor não tem `.length`.** Quem sabe o tamanho é você. No bloco onde o vetor
  foi declarado, `sizeof(v) / sizeof(v[0])` dá a conta (bytes do vetor
  divididos pelos bytes de um item).

Cada posição é uma variável comum: entra em conta, em `if`, em
`scanf("%d", &notas[i])`. O índice pode ser qualquer expressão inteira
(`v[i + 1]`, `v[n - 1]`, `v[i % 7]`), e é isso que casa o vetor com o `for`.

Dois usos **não** funcionam: atribuir um vetor inteiro (`copia = passos;`) e
inicializar com chaves depois da declaração (`passos = {1, 2};`). Vetor se
copia gaveta por gaveta, num laço.

No exemplo, são 7 gavetas, uma por dia. O laço soma e guarda a maior. O
recorde está na gaveta 5, o dia 6 para quem lê o relatório:

{{ideia}}

O `i` vai de 0 a 6. O `maior` começa com `passos[0]`, e não com 0:

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

O caminho junta o acumulador e o maior/menor do assunto 0025, com os valores
vindos do vetor. A pergunta `i < 7?` impede o laço de passar da última gaveta:

{{fluxograma}}

> [!WARNING]
> **O C não confere o índice.** Com `int v[7]`, escrever `v[7] = 0` ou ler
> `v[-1]` compila e mexe na memória vizinha, talvez outra variável sua. É
> **comportamento indefinido**: nada acontece, ou outro valor muda "sozinho",
> ou o programa cai. O erro clássico é o `<=` no laço: `for (i = 0; i <= 7;
> i++)` passa uma vez a mais. O gcc com as flags de estudo usa o
> AddressSanitizer, que mostra `stack-buffer-overflow`.

> [!TIP]
> **Por dentro do C:** as 7 gavetas são 28 bytes seguidos (7 × 4). O nome marca
> o começo e o índice diz **quantos itens pular**: `passos[5]` fica em início +
> 5 × 4 bytes. Por isso o primeiro é o 0, e acessar a posição 0 ou a 999 custa
> o mesmo.

> [!NOTE]
> **Pergunta para você:** se o `maior` começasse com 0 e os valores fossem
> temperaturas de inverno em Urupema (`{-3, -5, -1, -4}`), qual seria o
> "maior" mostrado? Por que começar por `v[0]` resolve?

{{pratique}}
