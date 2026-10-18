## 0113 · Juntando tudo: o contador de palavras

A padaria do bairro recebeu dezenas de comentários no app de entrega e quer
saber do que os clientes mais falam. Um programa lê o texto, conta cada
palavra e mostra o ranking.

É o problema perfeito para uma tabela hash: a chave é a palavra, o valor é a
contagem, e cada palavra do texto vira uma busca seguida de `+1`. O programa
junta peças de vários módulos:

- **strings e `ctype.h`**: quebrar o texto em palavras e passar para
  minúsculas, para "Pão" e "pão" contarem juntas;
- **a tabela com encadeamento** (assunto 0111), agora como o TAD
  `palavras.h`: `contador_soma` procura a palavra no seu balde e soma 1, ou
  cria o nó com a palavra **copiada**;
- **vetor + `qsort`** (assuntos 0055 e 0101): a tabela não tem ordem nenhuma,
  então, para o ranking, as contagens vão para um vetor, que é ordenado por
  número de vezes e, no empate, em ordem alfabética.

Por que não um vetor com busca sequencial? Com `N` palavras no texto e `d`
diferentes, isso custa O(N · d). Com a tabela, O(N) em média, mais
O(d log d) do `qsort` no fim. Num livro de 100 mil palavras, 10 mil
diferentes: um bilhão de comparações contra algumas centenas de milhares.

Vamos ver na prática. O texto tem 31 palavras, 17 diferentes. A tabela tem
17 baldes, um fator de carga de 1. O "pão" cai no balde 2 e chega a 6; o
"café", no balde 3, chega a 3; "estava" e "queijo" dividem o balde 4. No
fim, a lista vai para o vetor, o `qsort` ordena e o ranking sai:

{{ideia}}

O programa completo (exemplo A225). O TAD `palavras.h` fica na pasta, e o
`main` só conhece as funções dele:

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

Repara no fluxograma: o laço principal é "pega a próxima palavra e soma". A
pergunta "já está no balde?" é feita 31 vezes. O Sim acontece 14 vezes; o
Não, 17, uma para cada palavra diferente, e cria o nó com 0. Os dois caminhos
se juntam no `vezes++`, como no `contador_soma`. Quando o texto acaba, sai o
ranking:

{{fluxograma}}

> [!WARNING]
> `isalpha`, `tolower` e companhia recebem um `int` que precisa ser um valor
> de `unsigned char` (0 a 255) ou `EOF`. Num texto UTF-8, o "ã" chega como
> os bytes `0xC3 0xA3`, que num `char` com sinal valem -61 e -93. Passar
> `isalpha(s[i])` com valor negativo é **comportamento indefinido**: muitas
> bibliotecas usam o valor como índice de uma tabela interna e leem fora
> dela. Converta sempre: `isalpha((unsigned char)s[i])`. O mesmo byte
> negativo, somado num `int`, dá índice negativo na sua tabela hash. Aqui o
> `eh_letra` trata todo byte de 128 para cima como parte da palavra, e assim
> "pão" e "café" ficam inteiras.

> [!TIP]
> **Por dentro do C:** cada nó tem 32 bytes de palavra, 4 da contagem, 4 de
> preenchimento e 8 do `prox`: 48 bytes. As 17 palavras ocupam 17 `malloc`
> de 48 bytes, mais 136 bytes do vetor de 17 ponteiros. O vetor de
> `Contagem` **não copia** as palavras: cada `palavra` aponta para dentro de
> um nó da tabela. Por isso o `free(lista)` vem antes do `contador_libera`,
> e usar a lista depois de liberar a tabela seria ponteiro solto. E um
> detalhe do hash: com base 31 e `m = 31`, `h * 31 % 31` é sempre 0, e o
> balde passa a depender **só da última letra**. Base e `m` não podem ter
> fator comum; por isso o exemplo usa 17.

> [!NOTE]
> **Pergunta para você:** o ranking tem "o", "de" e "e" logo no topo, que não
> dizem nada sobre a padaria. Como você ignoraria essas palavras (as
> *stopwords*) usando a própria tabela hash? E que palavra seria a 3ª do
> ranking depois disso?

{{pratique}}
