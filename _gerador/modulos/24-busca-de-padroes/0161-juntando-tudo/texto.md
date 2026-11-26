## 0161 · Juntando tudo

O síndico quer ler só os avisos do condomínio que falam da garagem. No
terminal, `grep garagem avisos.txt` resolve: o **grep** é o programa que
mostra as linhas de um arquivo que contêm um padrão (KERNIGHAN; RITCHIE,
1989). Aqui você monta um mini-grep com os quatro algoritmos do módulo e
usa o próprio programa para medir qual deles trabalha menos. O seu grep
trata só **padrões fixos**, palavras exatas, sem os curingas do grep de
verdade.

Para trocar de algoritmo sem reescrever o programa, os quatro precisam
aceitar os mesmos parâmetros e devolver a mesma coisa. Eles ficam num TAD,
com a interface em `padroes.h` e a implementação em `padroes.c`, todos com a
mesma **assinatura**, a lista de tipos dos parâmetros e do retorno:

```c
typedef int (*Busca)(const char *texto, int n, const char *padrao, int m,
                     int pos[], int max, long *comparacoes);

int pb_forca_bruta(...);   // os quatro com os mesmos parâmetros
int pb_kmp(...);
int pb_horspool(...);
int pb_rabin_karp(...);
```

Cada função devolve quantas ocorrências achou. As posições das primeiras
`max` ocorrências vão no vetor `pos`; se `pos` for `NULL`, a função só
conta. O último parâmetro é um contador: a função **soma** em
`*comparacoes` as comparações de letra que fez, em vez de zerar. Assim, ao
chamar a busca linha a linha, o contador acumula o custo do arquivo inteiro.

O `typedef` da primeira linha cria o tipo `Busca`, um **ponteiro para
função** (assunto 0050): uma variável que guarda o endereço de uma função e
permite chamá-la depois (KERNIGHAN; RITCHIE, 1989). Qualquer um dos quatro
algoritmos cabe numa variável `Busca`, porque todos têm a assinatura certa.
Com um vetor de structs `{nome, busca}`, cada posição guarda o nome de um
algoritmo e o ponteiro para ele, e trocar de algoritmo vira trocar o índice:
`algs[a].busca(...)`.

Para comparar os quatro, o programa conta **comparações de letra**. Esse
número é um cronômetro que não depende da máquina: dá o mesmo resultado no
seu computador e no de qualquer outra pessoa. Só que ele não é tempo. O
Rabin-Karp troca comparações de letra por multiplicações e restos, que o
contador não vê, e o Horspool consulta a tabela de saltos a cada
alinhamento. Para medir tempo de verdade, use `clock()`, de `<time.h>`, que
devolve o tempo de processador em tiques: a diferença entre duas chamadas,
dividida por `CLOCKS_PER_SEC`, dá segundos. Meça trechos grandes, de
milhões de letras, porque uma busca curta termina antes de o relógio andar.
E cuidado com a otimização: com `-O2`, o `gcc` pode apagar uma busca cujo
resultado ninguém usa. Por isso o A321 imprime o total achado.

Nenhum dos quatro vence sempre, e a tabela resume quando cada um compensa.
O **preparo** é o que o algoritmo calcula antes de ler o texto; a **memória
extra** é o que ele guarda além do texto e do padrão:

| | preparo | memória extra | pior caso | caso comum | ponto forte |
| --- | --- | --- | --- | --- | --- |
| força bruta | nenhum | nenhuma | O(n·m) | perto de `n` | simples; ótima para padrão curto |
| KMP | tabela π, O(m) | `m` inteiros | O(n + m) | entre `n` e `2n` | garantia; lê o texto uma vez, sem voltar |
| Horspool | saltos, O(256 + m) | 256 inteiros | O(n·m) | perto de `n / m` | pula letras; melhora com padrão longo |
| Rabin-Karp | hash do padrão, O(m) | nenhuma | O(n·m) | O(n + m) | vários padrões de uma vez; texto como números |

Repare na coluna do caso comum. Num texto do dia a dia, a força bruta
falha logo na primeira letra de quase todo alinhamento, e o KMP, que paga o
preço de recuar, pode fazer até mais comparações que ela. O KMP só mostra a
vantagem quando o texto tem muita repetição parcial do padrão. O Horspool,
que pula letras, costuma ser o mais rápido em texto comum.

> [!WARNING]
> Os algoritmos trabalham com **bytes**, não com letras. Em UTF-8,
> "Reunião" tem 7 letras e 8 bytes, as posições que o grep mostra são de
> byte, e "garagem" não acha "GARAGEM", porque maiúscula e minúscula são
> bytes diferentes (E963 e E951).

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
