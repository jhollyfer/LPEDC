## 0108 · Juntando tudo: o contador de palavras

Contar quantas vezes cada palavra aparece num texto é o problema que mais
mostra para que serve uma tabela hash. Sem ela, cada palavra lida exige
procurar numa lista de palavras já vistas, comparando uma por uma. Com ela, a
procura cai direto no balde certo.

A ideia é usar a tabela como um **dicionário**: um conjunto de pares em que a
**chave** é a palavra e o **valor** é a contagem. Cada palavra do texto vira
uma busca seguida de um `+1`. Se a palavra ainda não existe, ela entra com
contagem 1 (KERNIGHAN; RITCHIE, 1988, seção 6.6). É o mesmo que o caixa da
padaria faria com um caderno indexado pela primeira letra: abre na página
certa e risca mais um ao lado do nome.

Antes de contar, o texto precisa virar palavras. As funções de `ctype.h`
resolvem isso: `isalpha` diz se um byte é letra, e `tolower` passa a letra para
minúscula. Com tudo em minúsculas, "Pão" e "pão" viram a mesma chave e contam
juntas (CPPREFERENCE, s.d.). Os bytes de letras acentuadas em UTF-8 ficam acima
de 127; o exemplo trata todo byte a partir de 128 como parte da palavra, e
"pão" e "café" não se partem no meio.

A tabela usa encadeamento, do assunto 0106, empacotada como um TAD em
`palavras.h`. A função `contador_soma` calcula o balde, procura a palavra na
lista dele e soma 1 se achar. Se não achar, cria um nó com uma **cópia** da
palavra, porque o texto de onde ela veio vai ser reaproveitado para a palavra
seguinte (CELES; RANGEL, 2002).

O ranking pede ordem, e a tabela não tem nenhuma: a função hash espalha as
palavras de propósito. Por isso as contagens saem da tabela para um vetor, e o
`qsort` (assuntos 0050 e 0096) ordena esse vetor pelo número de vezes e, no
empate, pela palavra em ordem alfabética (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 7).

Faça a conta do ganho. Com `N` palavras no texto e `d` palavras
diferentes, a busca sequencial compara cada uma das `N` com até `d` já vistas:
O(N · d). A tabela faz cada busca em O(1) na média, então o total é O(N), mais
O(d log d) do `qsort` no fim (CORMEN et al., 2024, cap. 11).

Um detalhe na escolha de `m`. O hash polinomial usa base 31, e a base e `m` não
podem ter fator comum. Com base 31 e `m = 31`, toda parcela multiplicada por 31
some no resto, e o balde passa a depender só da última letra. O exemplo usa
`m = 17`, primo e diferente de 31 (CORMEN et al., 2024, cap. 11).

Outro detalhe, de memória. O vetor de contagens não copia as palavras: cada
campo `palavra` aponta para o texto guardado num nó da tabela. Se você libera a
tabela primeiro, o vetor fica apontando para memória devolvida. Por isso o
`free(lista)` vem antes de `contador_libera` (CELES; CERQUEIRA; RANGEL, 2016).

> [!WARNING]
> `isalpha` e `tolower` exigem um `unsigned char` (0 a 255) ou `EOF`. Os bytes
> do "ã" em UTF-8 são negativos num `char` com sinal (assunto 0105), e
> `isalpha(s[i])` com negativo é **comportamento indefinido**. Converta:
> `isalpha((unsigned char)s[i])`.

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
