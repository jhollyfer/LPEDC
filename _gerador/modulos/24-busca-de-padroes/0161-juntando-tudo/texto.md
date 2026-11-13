## 0161 · Juntando tudo

- **Grep**: mostra as linhas de um arquivo que têm um padrão fixo
  (KERNIGHAN; RITCHIE, 1989).
- **Mesma assinatura**: os quatro algoritmos do módulo ficam num TAD
  (`padroes.h`, `padroes.c`), devolvem quantas ocorrências acharam, guardam as
  primeiras `max` posições em `pos` (ou nada, se `NULL`) e **somam** em
  `*comparacoes` as comparações de letra.
- **Ponteiro para função** (assunto 0050): `Busca` aponta para qualquer um dos
  quatro, e um vetor de structs `{nome, busca}` troca de algoritmo pelo índice
  (KERNIGHAN; RITCHIE, 1989).
- **Comparação de letra** é um cronômetro que não depende da máquina, mas não é
  tempo: o Rabin-Karp troca comparações por contas de hash.
- **`clock()`** (`<time.h>`): tempo de processador em tiques; divida a diferença
  por `CLOCKS_PER_SEC`. Com `-O2`, o `gcc` pode apagar uma busca cujo resultado
  ninguém usa, e por isso o A321 imprime o total.

```c
typedef int (*Busca)(const char *texto, int n, const char *padrao, int m,
                     int pos[], int max, long *comparacoes);

int pb_forca_bruta(...);   // os quatro com os mesmos parâmetros
int pb_kmp(...);
int pb_horspool(...);
int pb_rabin_karp(...);
```

| | preparo | memória extra | pior caso | caso comum | ponto forte |
| --- | --- | --- | --- | --- | --- |
| força bruta | nenhum | nenhuma | O(n·m) | perto de `n` | simples; ótima para padrão curto |
| KMP | tabela π, O(m) | `m` inteiros | O(n + m) | entre `n` e `2n` | garantia; lê o texto uma vez, sem voltar |
| Horspool | saltos, O(256 + m) | 256 inteiros | O(n·m) | perto de `n / m` | pula letras; melhora com padrão longo |
| Rabin-Karp | hash do padrão, O(m) | nenhuma | O(n·m) | O(n + m) | vários padrões de uma vez; texto como números |

> [!WARNING]
> Os algoritmos trabalham com **bytes**: em UTF-8, "Reunião" tem 8 bytes, as
> posições são de byte, e "garagem" não acha "GARAGEM" (E963 e E951). O seu grep
> trata só padrões fixos.

{{exemplo}}

O síndico quer os avisos do condomínio que falam da garagem. São 8 avisos e o
grep mostra as linhas 3, 5 e 8 (a 3 tem duas ocorrências). Os quatro algoritmos
dão o mesmo resultado, com trabalho diferente:

{{ideia}}

O programa:

```c
#include <stdio.h>
#include <string.h>
#include "padroes.h"

typedef struct {
    const char *nome;
    Busca busca;          // ponteiro para a função (assunto 0050)
} Algoritmo;

int main(void) {
    const char *avisos[] = {
        "Aviso: a piscina fecha na segunda para limpeza",
        "Reunião de condomínio sexta às 19h no salão",
        "A garagem do bloco B será pintada; tire o carro da garagem até quinta",
        "Achados e perdidos: uma chave de carro na portaria",
        "Proibido lavar carro na garagem",
        "Mudanças só de segunda a sábado, das 8h às 18h",
        "Festa junina no salão: traga um prato",
        "Interfone da garagem com defeito",
    };
    int linhas = sizeof avisos / sizeof avisos[0];
    Algoritmo algs[] = {
        {"força bruta", pb_forca_bruta},
        {"KMP", pb_kmp},
        {"Horspool", pb_horspool},
        {"Rabin-Karp", pb_rabin_karp},
    };
    const char *padrao = "garagem";
    int m = (int) strlen(padrao);

    // 1. o grep: as linhas que têm o padrão (aqui, pelo KMP)
    printf("grep \"%s\":\n", padrao);
    for (int l = 0; l < linhas; l++) {
        long comp = 0;
        int k = pb_kmp(avisos[l], (int) strlen(avisos[l]), padrao, m, NULL, 0, &comp);
        if (k > 0) {
            printf("%d: %s\n", l + 1, avisos[l]);
        }
    }

    // 2. o cronômetro que não depende da máquina: comparações de letra
    printf("\nas mesmas 8 linhas com cada algoritmo:\n");
    for (int a = 0; a < 4; a++) {
        long comp = 0;
        int total = 0;
        for (int l = 0; l < linhas; l++) {
            total += algs[a].busca(avisos[l], (int) strlen(avisos[l]), padrao, m,
                                   NULL, 0, &comp);
        }
        printf("  %d ocorrências, %3ld comparações: %s\n", total, comp, algs[a].nome);
    }
    return 0;
}
// Saída:
// grep "garagem":
// 3: A garagem do bloco B será pintada; tire o carro da garagem até quinta
// 5: Proibido lavar carro na garagem
// 8: Interfone da garagem com defeito
//
// as mesmas 8 linhas com cada algoritmo:
//   4 ocorrências, 348 comparações: força bruta
//   4 ocorrências, 368 comparações: KMP
//   4 ocorrências,  83 comparações: Horspool
//   4 ocorrências,  28 comparações: Rabin-Karp
```

O grep é um laço sobre as linhas com uma chamada de busca no meio:

{{fluxograma}}

O KMP fez **mais** comparações que a força bruta: em texto comum ela falha na
primeira letra. O número do Rabin-Karp só conta a conferência; as contas de hash
das 317 janelas não entram.
