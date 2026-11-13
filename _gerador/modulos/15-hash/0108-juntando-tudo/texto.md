## 0108 · Juntando tudo: o contador de palavras

- **Tabela como dicionário**: a chave é a palavra e o valor é a contagem.
  Cada palavra do texto vira uma busca e um `+1` (KERNIGHAN; RITCHIE, 1988,
  seção 6.6).
- **Quebrar em palavras**: `ctype.h` testa letras e passa para minúsculas,
  para "Pão" e "pão" contarem juntas (CPPREFERENCE, s.d.).
- **Encadeamento** (0106): `contador_soma` soma 1 à palavra do balde ou cria o
  nó com a palavra **copiada** (CELES; RANGEL, 2002).
- **Ranking com `qsort`** (0050 e 0096): a tabela não guarda ordem. As
  contagens vão para um vetor, ordenado por vezes e, no empate, pela palavra
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Custo**: com `N` palavras e `d` diferentes, a busca sequencial custa
  O(N · d); a tabela custa O(N) em média, mais O(d log d) do `qsort`
  (CORMEN et al., 2024, cap. 11).
- **Base e `m` sem fator comum**: com base 31 e `m = 31`, o balde depende só
  da última letra. O exemplo usa `m = 17` (CORMEN et al., 2024, cap. 11).
- **O vetor aponta para a tabela**: cada `palavra` de `Contagem` aponta para
  um nó, então `free(lista)` vem antes de `contador_libera`
  (CELES; CERQUEIRA; RANGEL, 2016).

> [!WARNING]
> `isalpha` e `tolower` exigem um `unsigned char` (0 a 255) ou `EOF`. Os bytes
> do "ã" em UTF-8 são negativos num `char` com sinal, e `isalpha(s[i])` com
> negativo é **comportamento indefinido**. Use `isalpha((unsigned char)s[i])`.

{{exemplo}}

A padaria quer saber do que os clientes falam nos comentários do app. São 31
palavras, 17 diferentes, em 17 baldes. O "pão" cai no balde 2 e chega a 6;
"estava" e "queijo" dividem o balde 4. O `qsort` monta o ranking:

{{ideia}}

O `main` conhece só as funções do TAD `palavras.h`. O `eh_letra` trata todo
byte a partir de 128 como letra, e "pão" e "café" ficam inteiras:

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
