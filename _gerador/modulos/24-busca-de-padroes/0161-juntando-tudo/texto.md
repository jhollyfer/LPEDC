## 0161 · Juntando tudo

O síndico digitou os avisos do condomínio num arquivo, uma linha por aviso, e
quer saber quais falam da garagem. No terminal, isso é `grep garagem
avisos.txt`: o programa lê o arquivo linha por linha e mostra as que têm o
padrão. Neste assunto você monta o seu **mini-grep** com os quatro algoritmos
do módulo e mede qual trabalha menos.

O primeiro passo é dar aos quatro a **mesma cara**. Eles ficam num TAD,
`padroes.h` e `padroes.c`, todos com a mesma assinatura:

```c
typedef int (*Busca)(const char *texto, int n, const char *padrao, int m,
                     int pos[], int max, long *comparacoes);

int pb_forca_bruta(...);   // os quatro com os mesmos parâmetros
int pb_kmp(...);
int pb_horspool(...);
int pb_rabin_karp(...);
```

Cada função devolve quantas ocorrências achou, guarda as posições das
primeiras `max` em `pos` (ou nada, se `pos` for `NULL`) e **soma** em
`*comparacoes` as comparações de letra que fez. Somar, e não zerar, deixa
acumular o custo de um arquivo inteiro, linha após linha.

Com a mesma assinatura, o algoritmo vira um **dado**. `Busca` é um tipo
ponteiro para função (assunto 0050), e um vetor de structs `{nome, busca}`
guarda os quatro. O grep chama `algs[a].busca(...)` sem saber qual está do outro
lado: trocar de algoritmo é trocar um índice, não reescrever o laço.

E qual escolher? Cada um vence numa situação:

| | preparo | memória extra | pior caso | caso comum | ponto forte |
| --- | --- | --- | --- | --- | --- |
| força bruta | nenhum | nenhuma | O(n·m) | perto de `n` | simples; ótima para padrão curto |
| KMP | tabela π, O(m) | `m` inteiros | O(n + m) | entre `n` e `2n` | garantia; lê o texto uma vez, sem voltar |
| Horspool | saltos, O(256 + m) | 256 inteiros | O(n·m) | perto de `n / m` | pula letras; melhora com padrão longo |
| Rabin-Karp | hash do padrão, O(m) | nenhuma | O(n·m) | O(n + m) | vários padrões de uma vez; texto como números |

Vamos ver na prática. São 8 avisos e o padrão é "garagem". O grep mostra as
linhas 3, 5 e 8 (a 3 tem duas ocorrências). Depois, as mesmas linhas passam pelos
quatro algoritmos: o resultado é igual, o trabalho não:

{{ideia}}

O programa, usando o TAD:

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

Repara no fluxograma: o grep é um laço sobre as linhas com uma chamada de
busca no meio. Toda a esperteza do módulo está escondida atrás dessa chamada:

{{fluxograma}}

Leia os números com cuidado. O KMP fez **mais** comparações que a força bruta:
em texto comum, a força bruta já falha na primeira letra, e o KMP só ganha
quando há muita repetição parcial (o pior caso da força bruta). O Horspool
pulou letras: com 7 letras no padrão, ele olhou menos de um quarto do que a
força bruta olhou. E o Rabin-Karp parece imbatível, mas o número dele só conta
as letras da conferência: as duas contas de hash em cada uma das 317 janelas
não entram. O exemplo A321 liga o **cronômetro** de verdade, com `clock()`,
em textos de 2 milhões de letras.

> [!WARNING]
> Comparação de letra é um bom modelo, mas não é o tempo. O Rabin-Karp troca
> comparações por multiplicações e restos, que custam mais caro; o Horspool lê
> a tabela de saltos a cada alinhamento. E os algoritmos trabalham com
> **bytes**, não com letras: em UTF-8, "Reunião" tem 8 bytes, as posições
> devolvidas são posições de byte, e "garagem" não acha "GARAGEM" (o E963 e o
> E951 mostram os cuidados). O `grep` de verdade ainda trata acentos,
> maiúsculas e expressões regulares; o seu trata padrões fixos.

> [!TIP]
> **Por dentro do C:** `clock()`, de `<time.h>`, devolve o tempo de processador
> gasto pelo programa, em "tiques"; dividindo a diferença por `CLOCKS_PER_SEC`,
> você tem segundos. Ele mede o seu programa, não o relógio da parede. Três
> cuidados: meça trechos grandes (abaixo de alguns milissegundos é ruído); o
> `rodar` compila com AddressSanitizer, que confere cada acesso à memória e
> deixa o programa umas duas vezes mais lento; e com `-O2` o `gcc` pode apagar uma busca cujo
> resultado ninguém usa. Por isso o A321 imprime o total achado junto com o
> tempo.

> [!NOTE]
> **Pergunta para você:** se o padrão fosse "a", com uma letra só, qual dos
> quatro faria menos comparações nos 8 avisos? E com "de"? Pense antes, depois
> troque o padrão no código e confira.

{{pratique}}
