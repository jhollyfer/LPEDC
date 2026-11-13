## 0157 · Força bruta

Você aperta Ctrl+F no PDF do contrato de aluguel e digita "multa". Em menos
de um segundo o leitor pinta cada lugar em que a palavra aparece. Por trás
disso há um problema clássico: dado um **texto** de `n` letras e um
**padrão** de `m` letras, com `m <= n`, dizer em que posições o padrão
aparece. É o mesmo problema que o `grep` resolve num arquivo e que um
antivírus resolve ao procurar a assinatura de um vírus dentro de um programa
(CORMEN et al., 2024, cap. 32). Este módulo apresenta quatro jeitos de
resolvê-lo, e o primeiro é o mais direto de todos.

Imagine uma régua de papel com o padrão escrito nela, deitada sobre o texto.
Você encosta a régua no começo do texto, confere letra por letra e depois
escorrega a régua uma casa para a direita. Cada posição da régua é um
**alinhamento**: encostar o padrão no texto a partir da posição `i`. Se as
`m` letras do padrão batem com `texto[i..i+m-1]`, há uma **ocorrência** em
`i`. Em "banana", o padrão "ana" tem ocorrência em 1, porque `texto[1..3]` é
"ana".

A **força bruta**, também chamada de busca ingênua, é exatamente a régua:
ela testa todos os alinhamentos, de `i = 0` até `i = n - m`, e em cada um
compara da esquerda para a direita, desistindo na primeira letra diferente
(FEOFILOFF, 2009, cap. 13). O último alinhamento é `n - m` porque, a partir
dele, o padrão já não cabe no que sobra do texto. Com `n = 6` e `m = 3`, os
alinhamentos são 0, 1, 2 e 3: quatro ao todo, ou `n - m + 1`.

```c
for (int i = 0; i <= n - m; i++) {
    int j = 0;
    while (j < m && texto[i + j] == padrao[j]) j++;
    if (j == m) printf("ocorrência em %d\n", i);
}
```

Como a régua anda sempre de uma em uma casa, a força bruta acha também as
ocorrências que se **sobrepõem**, isto é, que dividem letras. Em "banana",
"ana" aparece em 1 e em 3, e as duas ocorrências compartilham o "a" da
posição 3. Um algoritmo que pulasse o padrão inteiro depois de achar perderia
a segunda.

Quanto isso custa? O trabalho se mede em **comparações de letra**. Num texto
comum, quase todo alinhamento falha logo na primeira ou na segunda letra,
então o total fica perto de `n`. O **pior caso** aparece quando quase todo
alinhamento casa o padrão inteiro antes de falhar na última letra: procurar
`"00001"` num código de vinte zeros compara cinco letras em cada um dos 16
alinhamentos. No geral, o teto é `(n - m + 1) · m` comparações, o que dá
**O(n·m)**. A memória extra é O(1): só os índices `i` e `j` (ZIVIANI, 2010,
cap. 8). O A314 mede esse pior caso.

A biblioteca padrão já traz uma busca pronta. `strstr(texto, padrao)`, de
`string.h`, devolve um ponteiro para a primeira ocorrência, ou `NULL` se o
padrão não aparece (DEITEL; DEITEL, 2011, cap. 8). A posição sai da
diferença de ponteiros, `p - texto`. Para achar a próxima, chame de novo a
partir de `p + 1`; se chamar a partir de `p + m`, as sobreposições somem (o
A313 compara os dois). Não escreva pelo ponteiro que o `strstr` devolve
quando o texto é um literal: isso é comportamento indefinido (assunto 0048).

Os próximos assuntos atacam o desperdício da força bruta. Depois de casar
`k` letras e falhar, ela joga fora tudo o que leu e recomeça uma casa
adiante. O KMP aproveita o que já leu; o Horspool pula casas; o Rabin-Karp
troca a comparação de letras por uma conta.

> [!WARNING]
> O laço vai até `i <= n - m`, **inclusive**: com `<`, a última ocorrência
> some. Guarde `n` e `m` em `int`: `strlen` devolve `size_t`, sem sinal, e com
> padrão maior que o texto `n - m` **dá a volta**, vira um número enorme e o
> laço lê além do `'\0'`.

{{exemplo}}

Procure "ana" em "banana bacana": são 11 alinhamentos, com ocorrências no 1, no
3 e no 10. O 0 falha no "b" e o 5 falha no espaço:

{{ideia}}

Em C, contando as comparações de letra:

```c
#include <stdio.h>
#include <string.h>

// mostra cada posição onde o padrão aparece; devolve quantas vezes apareceu
int forca_bruta(const char *texto, const char *padrao, int *comparacoes) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int achados = 0;
    *comparacoes = 0;
    for (int i = 0; i <= n - m; i++) {    // cada alinhamento possível
        int j = 0;
        while (j < m) {
            (*comparacoes)++;
            if (texto[i + j] != padrao[j]) {
                break;                    // errou uma letra: desiste daqui
            }
            j++;
        }
        if (j == m) {                     // as m letras bateram
            printf("  achou na posição %d\n", i);
            achados++;
        }
    }
    return achados;
}

int main(void) {
    const char *placa = "banana bacana";
    int comparacoes;

    printf("Procurando \"ana\" em \"%s\":\n", placa);
    int total = forca_bruta(placa, "ana", &comparacoes);
    printf("%d ocorrências, %d comparações\n", total, comparacoes);
    return 0;
}
// Saída:
// Procurando "ana" em "banana bacana":
//   achou na posição 1
//   achou na posição 3
//   achou na posição 10
// 3 ocorrências, 19 comparações
```

### Passo a passo

As 19 comparações, alinhamento por alinhamento (`n = 13`, `m = 3`):

| i | trecho do texto | comparações | resultado |
| --- | --- | --- | --- |
| 0 | `ban` | 1 (`b` ≠ `a`) | falha |
| 1 | `ana` | 3 | **ocorrência** |
| 2 | `nan` | 1 | falha |
| 3 | `ana` | 3 | **ocorrência** |
| 4 | `na␣` | 1 | falha |
| 5 | `a␣b` | 2 (o espaço ≠ `n`) | falha |
| 6, 7 | `␣ba`, `bac` | 1 cada | falha |
| 8 | `aca` | 2 (`c` ≠ `n`) | falha |
| 9 | `can` | 1 | falha |
| 10 | `ana` | 3 | **ocorrência** |

O teto seria `11 · 3 = 33`; deu 19 porque quase todo alinhamento falha cedo.

O laço de fora anda o alinhamento `i`, o de dentro anda a letra `j`. O `i`
sempre avança 1, tenha achado ou não:

{{fluxograma}}
