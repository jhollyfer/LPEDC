## 0108 · Juntando tudo: o contador de palavras

A padaria quer saber do que os clientes mais falam nos comentários do app.
O programa lê o texto, conta cada palavra e mostra o ranking. A chave da
tabela é a palavra e o valor é a contagem: cada palavra vira uma busca e um
`+1`. Ele junta:

- **strings e `ctype.h`**: quebrar o texto em palavras e passar para
  minúsculas, para "Pão" e "pão" contarem juntas;
- **tabela com encadeamento** (assunto 0106), como o TAD `palavras.h`:
  `contador_soma` soma 1 à palavra do balde ou cria o nó com a palavra
  **copiada**;
- **vetor + `qsort`** (assuntos 0050 e 0096): a tabela não tem ordem, então as
  contagens vão para um vetor, ordenado por vezes e, no empate, por ordem
  alfabética.

Com `N` palavras e `d` diferentes, a busca sequencial custa O(N · d); a
tabela custa O(N) em média, mais O(d log d) do `qsort`.

O exemplo tem 31 palavras, 17 diferentes, em 17 baldes (carga 1). O "pão" cai
no balde 2 e chega a 6; o "café", no 3, chega a 3; "estava" e "queijo" dividem
o balde 4. A tabela vai para o vetor, o `qsort` ordena e o ranking sai:

{{ideia}}

O `main` conhece só as funções do TAD `palavras.h`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palavras.h"

// letra = letra ASCII ou qualquer byte de um caractere UTF-8 (>= 128)
int eh_letra(char c) {
    unsigned char u = (unsigned char)c;
    return isalpha(u) || u >= 128;
}

// copia a próxima palavra de *p para buf, em minúsculas, e avança *p.
// devolve 0 quando o texto acaba
int proxima_palavra(const char **p, char *buf, size_t tam) {
    while (**p != '\0' && !eh_letra(**p)) {
        (*p)++; // pula espaço, pontuação, número
    }
    if (**p == '\0') {
        return 0;
    }
    size_t n = 0;
    while (eh_letra(**p)) {
        if (n < tam - 1) {
            buf[n++] = (char)tolower((unsigned char)**p);
        }
        (*p)++;
    }
    buf[n] = '\0';
    return 1;
}

// mais vezes primeiro; no empate, ordem alfabética
int compara(const void *a, const void *b) {
    const Contagem *x = a;
    const Contagem *y = b;
    if (x->vezes != y->vezes) {
        return y->vezes - x->vezes;
    }
    return strcmp(x->palavra, y->palavra);
}

int main(void) {
    const char *texto =
        "O pão de queijo estava quente e o café estava frio. "
        "Pão bom, café ruim: o pão de queijo salva a padaria. "
        "O café da tarde? Pão, pão e mais pão!";

    Contador *c = contador_cria(17);
    if (c == NULL) {
        return 1;
    }
    char palavra[TAM_PALAVRA];
    const char *p = texto;
    while (proxima_palavra(&p, palavra, sizeof palavra)) {
        contador_soma(c, palavra);
    }

    int n = contador_distintas(c);
    printf("%d palavras, %d diferentes\n", contador_total(c), n);
    Contagem *lista = contador_lista(c);
    if (lista != NULL) {
        qsort(lista, (size_t)n, sizeof lista[0], compara);
        for (int i = 0; i < 5 && i < n; i++) {
            printf("%d. %s: %d\n", i + 1, lista[i].palavra, lista[i].vezes);
        }
        free(lista);
    }
    contador_libera(c);
    return 0;
}
// Saída:
// 31 palavras, 17 diferentes
// 1. pão: 6
// 2. o: 4
// 3. café: 3
// 4. de: 2
// 5. e: 2
```

No fluxograma, "já está no balde?" ocorre 31 vezes: 14 Sim e 17 Não (uma por
palavra diferente, que cria o nó com 0). Os dois caminhos se juntam no
`vezes++`:

{{fluxograma}}

> [!WARNING]
> `isalpha` e `tolower` exigem um `unsigned char` (0 a 255) ou `EOF`. Os bytes
> do "ã" em UTF-8 são negativos num `char` com sinal (assunto 0105), e
> `isalpha(s[i])` com negativo é **comportamento indefinido**. Converta:
> `isalpha((unsigned char)s[i])`. O `eh_letra` trata todo byte a partir de 128
> como parte da palavra, e "pão" e "café" ficam inteiras.

> [!TIP]
> **Por dentro do C:** o vetor de `Contagem` **não copia** as palavras: cada
> `palavra` aponta para um nó da tabela, e por isso o `free(lista)` vem antes
> do `contador_libera`. Base e `m` não podem ter fator comum (com 31 e 31, o
> balde depende só da última letra); o exemplo usa 17.

> [!NOTE]
> **Pergunta para você:** "o", "de" e "e" lideram o ranking e não dizem nada
> sobre a padaria. Como ignorar essas palavras (as *stopwords*) com a própria
> tabela hash? Qual seria a 3ª do ranking depois disso?

{{pratique}}
