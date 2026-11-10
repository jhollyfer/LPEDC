## 0157 · Força bruta

Você aperta Ctrl+F no PDF do contrato de aluguel e digita "multa": o leitor
pinta todas as ocorrências. É achar um **padrão** dentro de um **texto**, o
problema do `grep` e do antivírus.

O texto tem `n` letras e o padrão tem `m`, com `m <= n`. Um **alinhamento**
encosta o padrão no texto a partir de uma posição `i`. Se as `m` letras batem
com `texto[i..i+m-1]`, há uma **ocorrência** em `i`.

A **força bruta** (ou busca ingênua) testa todos os alinhamentos, `i = 0, 1,
..., n - m`. Em cada um, compara da esquerda para a direita e desiste na
primeira diferença. O último alinhamento começa em `n - m`, porque depois dele
o padrão não cabe.

As ocorrências podem se **sobrepor**: em "banana", "ana" aparece em 1 e em 3.
A força bruta acha as duas porque avança de 1 em 1.

Num texto comum, quase todo alinhamento falha na primeira ou na segunda letra:
perto de `n` comparações. No **pior caso**, cada alinhamento compara quase o
padrão inteiro: até `(n - m + 1) · m`, ou **O(n·m)**. Procurar `"00001"` num
código de vinte zeros faz isso (A314).

Procure "ana" em "banana bacana": são 11 alinhamentos, com ocorrências no 1,
no 3 e no 10. O 0 falha no "b" e o 5 falha no espaço:

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

`strstr(texto, padrao)`, de `string.h`, devolve um ponteiro para a primeira
ocorrência ou `NULL`; a posição é `p - texto`. Para a próxima, chame de novo
a partir de `p + 1` (o A313 compara `p + 1` e `p + m`).

> [!WARNING]
> O laço vai até `i <= n - m`, **inclusive**: com `i < n - m`, o "ana" da
> posição 10 some. Guarde `n` e `m` em `int`: `strlen` devolve `size_t`, sem
> sinal, e com padrão maior que o texto `n - m` **dá a volta** e o laço lê além
> do `'\0'`.

> [!TIP]
> A força bruta usa memória O(1). Escrever pelo ponteiro que o `strstr`
> devolve, num literal, é comportamento indefinido (assunto 0048).

> [!NOTE]
> **Pergunta para você:** quantas comparações a força bruta faz para procurar
> "aaab" em "aaaaaaaaab" (nove "a" e um "b")? E para procurar "baaa" no mesmo
> texto? Conte no papel e troque os valores no código para conferir.

{{pratique}}
