## 0037 · Vetores

- **Vetor** (*array*): várias variáveis do mesmo tipo com um nome só, lado a
  lado na memória. É um dado composto **homogêneo**; a struct (módulo 08) é o
  heterogêneo (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 1).
- **Índice**: a posição entre colchetes, de `0` a `tamanho - 1`. Num vetor de
  7, o último é `v[6]`. Pode ser qualquer expressão inteira (`v[i + 1]`)
  (DEITEL; DEITEL, 2011, cap. 6).
- **Por que começa em 0**: o nome marca o começo e o índice diz quantos itens
  pular. Acessar `v[0]` ou `v[999]` custa o mesmo (BACKES, 2013, cap. 6).
- **Tamanho fixo**: decidido na declaração; use um `#define`. O VLA do C99
  (`int v[n];`, assunto 0172) também não cresce (DEITEL; DEITEL, 2011, cap. 6).
- **Inicialização**: com chaves, só na declaração. Os itens que faltam viram 0;
  sem tamanho, o compilador conta (DEITEL; DEITEL, 2011, cap. 6).
- **Sem `.length`**: quem sabe o tamanho é você. Onde o vetor foi declarado,
  `sizeof(v) / sizeof(v[0])` dá a conta (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **Cópia**: `copia = passos;` não compila. Vetor se copia item por item, num
  laço (BACKES, 2013, cap. 6).

```c
int passos[7];                 // 7 gavetas de int, com lixo dentro
int notas[4] = {7, 9, 6, 10};  // declara e inicializa
int zeros[100] = {0};          // a 1ª vira 0 e as outras também
int dias[] = {31, 28, 31};     // sem tamanho: o compilador conta (3)
```

> [!WARNING]
> **O C não confere o índice.** `v[7] = 0` num `int v[7]` compila e mexe na
> memória vizinha: comportamento indefinido. O erro clássico é `i <= 7` no
> laço; o AddressSanitizer mostra `stack-buffer-overflow`.

{{exemplo}}

O relógio contou os passos da semana: 7 gavetas, uma por dia. O laço soma e
guarda a maior; o recorde está na gaveta 5, o dia 6 do relatório:

{{ideia}}

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

É o acumulador e o maior/menor do assunto 0025, com os valores vindos do vetor;
`i < 7?` impede o laço de passar da última gaveta:

{{fluxograma}}
